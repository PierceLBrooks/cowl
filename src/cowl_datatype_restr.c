/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_datatype_restr_private.h"
#include "cowl_datatype.h"
#include "cowl_facet_restr.h"
#include "cowl_hash_utils.h"
#include "cowl_object_vec_private.h"
#include "cowl_template.h"

static CowlDatatypeRestr* cowl_datatype_restr_alloc(CowlDatatype *datatype,
                                                    CowlObjectVec *restrictions) {
    CowlDatatypeRestr *restr = ulib_alloc(restr);
    if (!restr) return NULL;

    *restr = (CowlDatatypeRestr) {
        .super = COWL_DATA_RANGE_INIT(COWL_DRT_DATATYPE_RESTR),
        .datatype = cowl_datatype_retain(datatype),
        .restrictions = restrictions
    };

    return restr;
}

static void cowl_datatype_restr_free(CowlDatatypeRestr *restr) {
    cowl_datatype_release(restr->datatype);
    cowl_object_vec_free(restr->restrictions);
    ulib_free(restr);
}

CowlDatatypeRestr* cowl_datatype_restr_get(CowlDatatype *datatype, CowlObjectVec *restr) {
    if (!(datatype && restr)) return NULL;
    return cowl_datatype_restr_alloc(datatype, restr);
}

CowlDatatypeRestr* cowl_datatype_restr_retain(CowlDatatypeRestr *restr) {
    return cowl_object_incr_ref(restr);
}

void cowl_datatype_restr_release(CowlDatatypeRestr *restr) {
    if (restr && !cowl_object_decr_ref(restr)) {
        cowl_datatype_restr_free(restr);
    }
}

CowlDatatype* cowl_datatype_restr_get_datatype(CowlDatatypeRestr *restr) {
    return restr->datatype;
}

CowlObjectVec* cowl_datatype_restr_get_restrictions(CowlDatatypeRestr *restr) {
    return restr->restrictions;
}

CowlString* cowl_datatype_restr_to_string(CowlDatatypeRestr *restr)
    COWL_TO_STRING_IMPL(datatype_restr, restr)

bool cowl_datatype_restr_equals(CowlDatatypeRestr *lhs, CowlDatatypeRestr *rhs) {
    return cowl_datatype_equals(lhs->datatype, rhs->datatype) &&
           cowl_object_vec_equals_no_order(lhs->restrictions, rhs->restrictions);
}

ulib_uint cowl_datatype_restr_hash(CowlDatatypeRestr *restr) {
    return cowl_hash_2(COWL_HASH_INIT_DATA_RESTR,
                       cowl_datatype_hash(restr->datatype),
                       cowl_object_vec_hash_no_order(restr->restrictions));
}

bool cowl_datatype_restr_iterate_primitives(CowlDatatypeRestr *restr, CowlPrimitiveFlags flags,
                                            CowlIterator *iter) {
    if (!cowl_datatype_iterate_primitives(restr->datatype, flags, iter)) return false;

    uvec_foreach(CowlObjectPtr, restr->restrictions, fr) {
        if (!cowl_facet_restr_iterate_primitives((CowlFacetRestr *)*fr.item, flags, iter)) {
            return false;
        }
    }

    return true;
}
