/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2022 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_datatype_private.h"
#include "cowl_iri.h"
#include "cowl_iterator_private.h"
#include "cowl_set.h"
#include "cowl_template.h"

static UHash(CowlObjectTable) inst_tbl;

static ulib_uint inst_tbl_hash(void *key) {
    return cowl_iri_hash(cowl_datatype_get_iri(key));
}

static bool inst_tbl_eq(void *lhs, void *rhs) {
    return cowl_iri_equals(cowl_datatype_get_iri(lhs), cowl_datatype_get_iri(rhs));
}

cowl_ret cowl_datatype_api_init(void) {
    inst_tbl = uhset_init_pi(CowlObjectTable, inst_tbl_hash, inst_tbl_eq);
    return COWL_OK;
}

void cowl_datatype_api_deinit(void) {
    uhash_deinit(CowlObjectTable, &inst_tbl);
}

static CowlDatatype* cowl_datatype_alloc(CowlIRI *iri) {
    CowlDatatype *dt = ulib_alloc(dt);
    if (!dt) return NULL;

    *dt = (CowlDatatype) {
        .super = COWL_OBJECT_INIT(COWL_OT_DR_DATATYPE),
        .iri = cowl_iri_retain(iri)
    };

    return dt;
}

static void cowl_datatype_free(CowlDatatype *dt) {
    cowl_iri_release(dt->iri);
    ulib_free(dt);
}

CowlDatatype* cowl_datatype_get(CowlIRI *iri) {
    if (!iri) return NULL;
    COWL_INST_TBL_GET_IMPL(Datatype, datatype, { .iri = iri }, cowl_datatype_alloc(iri))
}

CowlDatatype* cowl_datatype_retain(CowlDatatype *dt) {
    return cowl_object_incr_ref(dt);
}

void cowl_datatype_release(CowlDatatype *dt) {
    if (dt && !cowl_object_decr_ref(dt)) {
        uhset_remove(CowlObjectTable, &inst_tbl, dt);
        cowl_datatype_free(dt);
    }
}

CowlDatatype* cowl_datatype_from_string(UString string)
    COWL_ENTITY_FROM_STRING_IMPL(Datatype, datatype)

CowlIRI* cowl_datatype_get_iri(CowlDatatype *dt) {
    return dt->iri;
}

CowlString* cowl_datatype_to_string(CowlDatatype *dt)
    COWL_TO_STRING_IMPL(datatype, dt)

bool cowl_datatype_equals(CowlDatatype *lhs, CowlDatatype *rhs) {
    return lhs == rhs;
}

ulib_uint cowl_datatype_hash(CowlDatatype *dt) {
    return uhash_ptr_hash(dt);
}

bool cowl_datatype_iterate_primitives(CowlDatatype *dt, CowlPrimitiveFlags flags,
                                      CowlIterator *iter) {
    return uflags_is_set(COWL_PF, flags, COWL_PF_DATATYPE) ? cowl_iterate(iter, dt) : true;
}
