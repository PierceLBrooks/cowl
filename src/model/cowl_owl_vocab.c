/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_owl_vocab_private.h"
#include "cowl_vocab_utils.h"

static cowl_struct(CowlOWLVocab) vocab;

void cowl_owl_vocab_init(void) {
    CowlString *ns = cowl_string_vocab_get("http://www.w3.org/2002/07/owl#");

    CowlOWLVocab v = {
        .iri = {
            .thing = cowl_iri_vocab_get(ns, "Thing"),
            .nothing = cowl_iri_vocab_get(ns, "Nothing"),
            .top_obj_prop = cowl_iri_vocab_get(ns, "topObjectProperty"),
            .bottom_obj_prop = cowl_iri_vocab_get(ns, "bottomObjectProperty"),
            .top_data_prop = cowl_iri_vocab_get(ns, "topDataProperty"),
            .bottom_data_prop = cowl_iri_vocab_get(ns, "bottomDataProperty"),
            .backward_comp = cowl_iri_vocab_get(ns, "backwardCompatibleWith"),
            .deprecated = cowl_iri_vocab_get(ns, "deprecated"),
            .incompatible = cowl_iri_vocab_get(ns, "incompatibleWith"),
            .prior_version = cowl_iri_vocab_get(ns, "priorVersion"),
            .rational = cowl_iri_vocab_get(ns, "rational"),
            .real = cowl_iri_vocab_get(ns, "real"),
            .version_info = cowl_iri_vocab_get(ns, "versionInfo")
        }
    };

    vocab = (cowl_struct(CowlOWLVocab)) {
        .ns = ns,
        .iri = v.iri,

        .cls = {
            .thing = cowl_class_vocab_get(v.iri.thing),
            .nothing = cowl_class_vocab_get(v.iri.nothing)
        },

        .dt = {
            .rational = cowl_datatype_vocab_get(v.iri.rational),
            .real = cowl_datatype_vocab_get(v.iri.real)
        },

        .obj_props = {
            .top_obj_prop = cowl_obj_prop_vocab_get(v.iri.top_obj_prop),
            .bottom_obj_prop = cowl_obj_prop_vocab_get(v.iri.bottom_obj_prop)
        },

        .data_props = {
            .top_data_prop = cowl_data_prop_vocab_get(v.iri.top_data_prop),
            .bottom_data_prop = cowl_data_prop_vocab_get(v.iri.bottom_data_prop)
        },

        .annot_props = {
            .backward_comp = cowl_annot_prop_vocab_get(v.iri.backward_comp),
            .deprecated = cowl_annot_prop_vocab_get(v.iri.deprecated),
            .incompatible = cowl_annot_prop_vocab_get(v.iri.incompatible),
            .prior_version = cowl_annot_prop_vocab_get(v.iri.prior_version),
            .version_info = cowl_annot_prop_vocab_get(v.iri.version_info)
        }
    };
}

void cowl_owl_vocab_deinit(void) {
    cowl_string_vocab_free(vocab.ns);

    cowl_iri_vocab_free(vocab.iri.thing);
    cowl_iri_vocab_free(vocab.iri.nothing);
    cowl_iri_vocab_free(vocab.iri.top_obj_prop);
    cowl_iri_vocab_free(vocab.iri.bottom_obj_prop);
    cowl_iri_vocab_free(vocab.iri.top_data_prop);
    cowl_iri_vocab_free(vocab.iri.bottom_data_prop);
    cowl_iri_vocab_free(vocab.iri.backward_comp);
    cowl_iri_vocab_free(vocab.iri.deprecated);
    cowl_iri_vocab_free(vocab.iri.incompatible);
    cowl_iri_vocab_free(vocab.iri.prior_version);
    cowl_iri_vocab_free(vocab.iri.rational);
    cowl_iri_vocab_free(vocab.iri.real);
    cowl_iri_vocab_free(vocab.iri.version_info);

    cowl_class_vocab_free(vocab.cls.thing);
    cowl_class_vocab_free(vocab.cls.nothing);

    cowl_datatype_vocab_free(vocab.dt.rational);
    cowl_datatype_vocab_free(vocab.dt.real);

    cowl_obj_prop_vocab_free(vocab.obj_props.top_obj_prop);
    cowl_obj_prop_vocab_free(vocab.obj_props.bottom_obj_prop);

    cowl_data_prop_vocab_free(vocab.data_props.top_data_prop);
    cowl_data_prop_vocab_free(vocab.data_props.bottom_data_prop);

    cowl_annot_prop_vocab_free(vocab.annot_props.backward_comp);
    cowl_annot_prop_vocab_free(vocab.annot_props.deprecated);
    cowl_annot_prop_vocab_free(vocab.annot_props.incompatible);
    cowl_annot_prop_vocab_free(vocab.annot_props.prior_version);
    cowl_annot_prop_vocab_free(vocab.annot_props.version_info);
}

CowlOWLVocab* cowl_owl_vocab_get(void) {
    return &vocab;
}
