/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_string_private.h"
#include "cowl_object_table_private.h"

static UHash(CowlObjectTable) *inst_tbl = NULL;
static CowlString *empty = NULL;

cowl_ret cowl_string_api_init(void) {
    inst_tbl = cowl_string_map_alloc();
    empty = cowl_string_from_static("");
    return (inst_tbl && empty) ? COWL_OK : COWL_ERR_MEM;
}

void cowl_string_api_deinit(void) {
    cowl_string_release(empty);
    uhash_free(CowlObjectTable, inst_tbl);
}

CowlString* cowl_string_alloc(UString raw_string) {
    if (ustring_is_null(raw_string)) return NULL;
    CowlString *string = ulib_alloc(string);
    if (string) {
        *string = cowl_string_init(raw_string);
    } else {
        ustring_deinit(raw_string);
    }
    return string;
}

CowlString cowl_string_init(UString raw_string) {
    ulib_uint hash = ustring_is_null(raw_string) ? 0 : ustring_hash(raw_string);

    CowlString init = {
        .super = COWL_HASH_OBJECT_INIT(COWL_OT_STRING, hash),
        .raw_string = raw_string
    };

    return init;
}

static void cowl_string_free(CowlString *string) {
    if (!string) return;
    ustring_deinit(string->raw_string);
    ulib_free(string);
}

static CowlString* cowl_string_get_intern(UString raw_string, bool copy) {
    if (!raw_string.length) return cowl_string_get_empty();

    CowlString *string;
    CowlString key = cowl_string_init(raw_string);

    uhash_uint idx;
    uhash_ret ret = uhash_put(CowlObjectTable, inst_tbl, &key, &idx);

    if (ret == UHASH_PRESENT) {
        string = uhash_key(inst_tbl, idx);
        cowl_string_retain(string);
    } else if (ret == UHASH_INSERTED) {
        if (copy) raw_string = ustring_copy(raw_string);
        string = cowl_string_alloc(raw_string);
        cowl_object_bit_set(string);
        uhash_key(inst_tbl, idx) = string;
    } else {
        string = NULL;
    }

    return string;
}

CowlString* cowl_string_intern(CowlString *string) {
    if (!(string && string->raw_string.length)) return empty;

    uhash_uint idx;
    uhash_ret ret = uhash_put(CowlObjectTable, inst_tbl, string, &idx);

    if (ret == UHASH_INSERTED) {
        cowl_object_bit_set(string);
    } else if (ret == UHASH_PRESENT) {
        string = uhash_key(inst_tbl, idx);
    } else {
        string = NULL;
    }

    return string;
}

CowlString* cowl_string_copy(CowlString *string) {
    CowlString *copy = ulib_alloc(copy);
    if (!copy) return NULL;

    ulib_uint hash = cowl_object_hash_get(string);
    copy->super = COWL_HASH_OBJECT_INIT(COWL_OT_STRING, hash);
    copy->raw_string = ustring_copy(string->raw_string);

    return copy;
}

cowl_ret cowl_string_get_ns_rem(UString string, ulib_uint ns_length, CowlString **out) {
    CowlString *rhs;

    if (ns_length < string.length) {
        rhs = cowl_string_get(string.cstring + ns_length, string.length - ns_length, true);
    } else {
        ns_length = string.length;
        rhs = cowl_string_get_empty();
    }

    UString raw_string = ustring_init(string.cstring, ns_length, false);
    CowlString *lhs = cowl_string_get_intern(raw_string, true);
    cowl_ret ret;

    if (lhs && rhs) {
        ret = COWL_OK;
    } else {
        cowl_string_release(lhs);
        cowl_string_release(rhs);
        lhs = NULL;
        rhs = NULL;
        ret = COWL_ERR_MEM;
    }

    out[0] = lhs;
    out[1] = rhs;
    return ret;
}

CowlString* cowl_string_get(char const *cstring, size_t length, bool copy) {
    UString raw_string = ustring_init(cstring, length, copy);
    return cowl_string_alloc(raw_string);
}

CowlString* cowl_string_get_empty(void) {
    return cowl_string_retain(empty);
}

CowlString* cowl_string_retain(CowlString *string) {
    return cowl_object_incr_ref(string);
}

void cowl_string_release(CowlString *string) {
    if (string && !cowl_object_decr_ref(string)) {
        // If the string was interned, it must also be removed from the hash set.
        if (cowl_object_bit_get(string)) uhset_remove(CowlObjectTable, inst_tbl, string);
        cowl_string_free(string);
    }
}

char const* cowl_string_release_copying_cstring(CowlString *string) {
    if (!string) return NULL;
    char const *cstring;

    if (cowl_object_decr_ref(string)) {
        cstring = ulib_str_dup(string->raw_string.cstring, string->raw_string.length);
    } else {
        cstring = string->raw_string.cstring;
        string->raw_string.cstring = NULL;
        cowl_string_free(string);
    }

    return cstring;
}

char const* cowl_string_get_cstring(CowlString *string) {
    return string->raw_string.cstring;
}

ulib_uint cowl_string_get_length(CowlString *string) {
    return string->raw_string.length;
}

bool cowl_string_equals(CowlString *lhs, CowlString *rhs) {
    return cowl_object_hash_equals(lhs, rhs) &&
           ustring_equals(lhs->raw_string, rhs->raw_string);
}

ulib_uint cowl_string_hash(CowlString *string) {
    return cowl_object_hash_get(string);
}

CowlString* cowl_string_with_format(char const *format, ...) {
    va_list args;
    va_start(args, format);
    UString raw_string = ustring_with_format_list(format, args);
    va_end(args);
    return cowl_string_alloc(raw_string);
}

CowlString* cowl_string_concat(CowlString *lhs, CowlString *rhs) {
    UString comp[] = { lhs->raw_string, rhs->raw_string };
    UString cat = ustring_concat(comp, ulib_array_count(comp));
    return cowl_string_alloc(cat);
}
