/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_iterator_private.h"
#include "cowl_table.h"
#include "cowl_vector.h"

static bool cowl_store_vec(void *vec, CowlAny *obj) {
    return uvec_push(CowlObjectPtr, vec, obj) != UVEC_ERR;
}

static bool cowl_store_set(void *set, CowlAny *obj) {
    return uhset_insert(CowlObjectTable, set, obj) != UHASH_ERR;
}

static bool cowl_count(void *count, cowl_unused CowlAny *obj) {
    (*((ulib_uint *)count))++;
    return true;
}

CowlIterator cowl_iterator_vec(UVec(CowlObjectPtr) *vec) {
    if (!vec) {
        vec = ulib_alloc(vec);
        if (vec) *vec = uvec(CowlObjectPtr);
    }
    return (CowlIterator){ .ctx = vec, .for_each = cowl_store_vec };
}

CowlIterator cowl_iterator_set(UHash(CowlObjectTable) *set) {
    if (!set) {
        set = ulib_alloc(set);
        if (set) *set = uhset(CowlObjectTable);
    }
    return (CowlIterator){ .ctx = set, .for_each = cowl_store_set };
}

CowlIterator cowl_iterator_count(ulib_uint *count) {
    if (!count) {
        count = ulib_alloc(count);
        if (count) *count = 0;
    }
    return (CowlIterator){ .ctx = count, .for_each = cowl_count };
}
