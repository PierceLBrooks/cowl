/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_facet_restr_private.h"
#include "cowl_alloc.h"
#include "cowl_hash_utils.h"
#include "cowl_literal.h"
#include "cowl_macros.h"
#include "cowl_str_buf.h"
#include "cowl_template.h"

static CowlFacetRestr* cowl_facet_restr_alloc(CowlFacet facet, CowlLiteral *value) {
    CowlFacetRestr *restr = cowl_alloc(restr);
    if (!restr) return NULL;

    cowl_uint_t hash = cowl_hash_2(COWL_HASH_INIT_FACET_RESTR, facet, cowl_literal_hash(value));
    *restr = (CowlFacetRestr) {
        .super = COWL_HASH_OBJECT_INIT(COWL_OT_FACET_RESTR, hash),
        .facet = facet,
        .value = cowl_literal_retain(value)
    };

    return restr;
}

static void cowl_facet_restr_free(CowlFacetRestr *restr) {
    if (!restr) return;
    cowl_literal_release(restr->value);
    cowl_free(restr);
}

CowlFacetRestr* cowl_facet_restr_get(CowlFacet facet, CowlLiteral *value) {
    if (!(value && cowl_enum_value_is_valid(FACET, facet))) return NULL;
    return cowl_facet_restr_alloc(facet, value);
}

CowlFacetRestr* cowl_facet_restr_retain(CowlFacetRestr *restr) {
    return cowl_object_retain(restr);
}

void cowl_facet_restr_release(CowlFacetRestr *restr) {
    if (restr && !cowl_object_release(restr)) {
        cowl_facet_restr_free(restr);
    }
}

CowlFacet cowl_facet_restr_get_facet(CowlFacetRestr *restr) {
    return restr->facet;
}

CowlLiteral* cowl_facet_restr_get_value(CowlFacetRestr *restr) {
    return restr->value;
}

CowlString* cowl_facet_restr_to_string(CowlFacetRestr *restr)
    COWL_TO_STRING_IMPL(facet_restr, restr)

bool cowl_facet_restr_equals(CowlFacetRestr *lhs, CowlFacetRestr *rhs) {
    return lhs->facet == rhs->facet && cowl_literal_equals(lhs->value, rhs->value);
}

cowl_uint_t cowl_facet_restr_hash(CowlFacetRestr *restr) {
    return cowl_object_hash_get(restr);
}

bool cowl_facet_restr_iterate_signature(CowlFacetRestr *restr, CowlEntityIterator *iter) {
    return cowl_literal_iterate_signature(restr->value, iter);
}

bool cowl_facet_restr_iterate_primitives(CowlFacetRestr *restr, CowlPrimitiveIterator *iter) {
    return cowl_literal_iterate_primitives(restr->value, iter);
}
