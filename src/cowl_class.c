/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2022 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_class_private.h"
#include "cowl_iri.h"
#include "cowl_iterator_private.h"
#include "cowl_set.h"
#include "cowl_template.h"

static UHash(CowlObjectTable) inst_tbl;

static ulib_uint inst_tbl_hash(void *key) {
    return cowl_iri_hash(cowl_class_get_iri(key));
}

static bool inst_tbl_eq(void *lhs, void *rhs) {
    return cowl_iri_equals(cowl_class_get_iri(lhs), cowl_class_get_iri(rhs));
}


cowl_ret cowl_class_api_init(void) {
    inst_tbl = uhset_init_pi(CowlObjectTable, inst_tbl_hash, inst_tbl_eq);
    return COWL_OK;
}

void cowl_class_api_deinit(void) {
    uhash_deinit(CowlObjectTable, &inst_tbl);
}

static CowlClass* cowl_class_alloc(CowlIRI *iri) {
    CowlClass *cls = ulib_alloc(cls);
    if (!cls) return NULL;

    (*cls) = (CowlClass) {
        .super = COWL_CLS_EXP_INIT(COWL_CET_CLASS),
        .iri = cowl_iri_retain(iri)
    };

    return cls;
}

static void cowl_class_free(CowlClass *cls) {
    cowl_iri_release(cls->iri);
    ulib_free(cls);
}

CowlClass* cowl_class_get(CowlIRI *iri) {
    if (!iri) return NULL;
    COWL_INST_TBL_GET_IMPL(Class, class, { .iri = iri }, cowl_class_alloc(iri))
}

CowlClass* cowl_class_retain(CowlClass *cls) {
    return cowl_object_incr_ref(cls);
}

void cowl_class_release(CowlClass *cls) {
    if (cls && !cowl_object_decr_ref(cls)) {
        uhset_remove(CowlObjectTable, &inst_tbl, cls);
        cowl_class_free(cls);
    }
}

CowlClass* cowl_class_from_string(UString string)
    COWL_ENTITY_FROM_STRING_IMPL(Class, class)

CowlIRI* cowl_class_get_iri(CowlClass *cls) {
    return cls->iri;
}

CowlString* cowl_class_to_string(CowlClass *cls)
    COWL_TO_STRING_IMPL(class, cls)

bool cowl_class_equals(CowlClass *lhs, CowlClass *rhs) {
    return lhs == rhs;
}

ulib_uint cowl_class_hash(CowlClass *cls) {
    return uhash_ptr_hash(cls);
}

bool cowl_class_iterate_primitives(CowlClass *cls, CowlPrimitiveFlags flags, CowlIterator *iter) {
    return uflags_is_set(COWL_PF, flags, COWL_PF_CLASS) ? cowl_iterate(iter, cls) : true;
}
