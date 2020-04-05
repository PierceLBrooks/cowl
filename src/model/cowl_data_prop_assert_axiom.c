/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_data_prop_assert_axiom_private.h"
#include "cowl_data_prop_exp.h"
#include "cowl_individual.h"
#include "cowl_literal.h"
#include "cowl_str_buf.h"
#include "cowl_template.h"

static CowlDataPropAssertAxiom* cowl_data_prop_assert_axiom_alloc(CowlAxiomType type,
                                                                  CowlIndividual *subj,
                                                                  CowlDataPropExp *prop,
                                                                  CowlLiteral *obj,
                                                                  CowlAnnotationVec *annot) {
    CowlDataPropAssertAxiom *axiom = cowl_axiom_alloc(axiom, annot);
    if (!axiom) return NULL;

    cowl_uint_t hash = cowl_axiom_hash_4(COWL_HASH_INIT_DATA_PROP_ASSERT_AXIOM, annot, type,
                                         cowl_individual_hash(subj),
                                         cowl_data_prop_exp_hash(prop),
                                         cowl_literal_hash(obj));

    cowl_axiom_init(CowlDataPropAssertAxiom, axiom, annot,
        .super = COWL_AXIOM_INIT(type, hash, annot),
        .subject = cowl_individual_retain(subj),
        .prop = cowl_data_prop_exp_retain(prop),
        .object = cowl_literal_retain(obj)
    );

    return axiom;
}

static void cowl_data_prop_assert_axiom_free(CowlDataPropAssertAxiom *axiom) {
    if (!axiom) return;
    cowl_individual_release(axiom->subject);
    cowl_data_prop_exp_release(axiom->prop);
    cowl_literal_release(axiom->object);
    cowl_axiom_free(axiom);
}

CowlDataPropAssertAxiom* cowl_data_prop_assert_axiom_get(CowlIndividual *subj,
                                                         CowlDataPropExp *prop,
                                                         CowlLiteral *obj,
                                                         CowlAnnotationVec *annot) {
    if (!(subj && prop && obj)) return NULL;
    return cowl_data_prop_assert_axiom_alloc(COWL_AT_DATA_PROP_ASSERT, subj, prop, obj, annot);
}

CowlDataPropAssertAxiom* cowl_neg_data_prop_assert_axiom_get(CowlIndividual *subj,
                                                             CowlDataPropExp *prop,
                                                             CowlLiteral *obj,
                                                             CowlAnnotationVec *annot) {
    return cowl_data_prop_assert_axiom_alloc(COWL_AT_NEG_DATA_PROP_ASSERT,
                                             subj, prop, obj, annot);
}

CowlDataPropAssertAxiom* cowl_data_prop_assert_axiom_retain(CowlDataPropAssertAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_data_prop_assert_axiom_release(CowlDataPropAssertAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_data_prop_assert_axiom_free(axiom);
    }
}

bool cowl_data_prop_assert_axiom_is_negative(CowlDataPropAssertAxiom *axiom) {
    return cowl_axiom_flags_get_type(axiom->super.flags) == COWL_AT_NEG_DATA_PROP_ASSERT;
}

CowlIndividual* cowl_data_prop_assert_axiom_get_subject(CowlDataPropAssertAxiom *axiom) {
    return axiom->subject;
}

CowlLiteral* cowl_data_prop_assert_axiom_get_object(CowlDataPropAssertAxiom *axiom) {
    return axiom->object;
}

CowlDataPropExp* cowl_data_prop_assert_axiom_get_prop(CowlDataPropAssertAxiom *axiom) {
    return axiom->prop;
}

CowlAnnotationVec* cowl_data_prop_assert_axiom_get_annot(CowlDataPropAssertAxiom *axiom) {
    return cowl_axiom_get_annot(axiom);
}

CowlString* cowl_data_prop_assert_axiom_to_string(CowlDataPropAssertAxiom *axiom)
    COWL_TO_STRING_IMPL(data_prop_assert, axiom)

bool cowl_data_prop_assert_axiom_equals(CowlDataPropAssertAxiom *lhs,
                                        CowlDataPropAssertAxiom *rhs) {
    return cowl_axiom_equals_impl(lhs, rhs,
                                  cowl_literal_equals(lhs->object, rhs->object) &&
                                  cowl_data_prop_exp_equals(lhs->prop, rhs->prop) &&
                                  cowl_individual_equals(lhs->subject, rhs->subject));
}

cowl_uint_t cowl_data_prop_assert_axiom_hash(CowlDataPropAssertAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_data_prop_assert_axiom_iterate_signature(CowlDataPropAssertAxiom *axiom,
                                                   CowlEntityIterator *iter) {
    if (cowl_individual_iterate_signature(axiom->subject, iter) &&
        cowl_data_prop_exp_iterate_signature(axiom->prop, iter) &&
        cowl_literal_iterate_signature(axiom->object, iter) &&
        cowl_axiom_annot_iterate_signature(axiom, iter)) {
        return true;
    }
    return false;
}

bool cowl_data_prop_assert_axiom_iterate_primitives(CowlDataPropAssertAxiom *axiom,
                                                    CowlPrimitiveIterator *iter) {
    if (cowl_individual_iterate_primitives(axiom->subject, iter) &&
        cowl_data_prop_exp_iterate_primitives(axiom->prop, iter) &&
        cowl_literal_iterate_primitives(axiom->object, iter) &&
        cowl_axiom_annot_iterate_primitives(axiom, iter)) {
        return true;
    }
    return false;
}
