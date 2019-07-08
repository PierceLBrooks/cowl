/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_rdfs_vocab_private.h"
#include "cowl_vocab_utils.h"

static cowl_struct(CowlRDFSVocab) vocab;

void cowl_rdfs_vocab_init(void) {
    CowlString *ns = cowl_string_vocab_get("http://www.w3.org/2000/01/rdf-schema#");

    CowlRDFSVocab v = {
        .iri = {
            .comment = cowl_iri_vocab_get(ns, "comment"),
            .defined_by = cowl_iri_vocab_get(ns, "isDefinedBy"),
            .label = cowl_iri_vocab_get(ns, "label"),
            .literal = cowl_iri_vocab_get(ns, "Literal"),
            .see_also = cowl_iri_vocab_get(ns, "seeAlso")
        }
    };

    vocab = (cowl_struct(CowlRDFSVocab)) {
        .ns = ns,
        .iri = v.iri,
        .dt = {
            .literal = cowl_datatype_vocab_get(v.iri.literal)
        },
        .annot_props = {
            .comment = cowl_annot_prop_vocab_get(v.iri.comment),
            .defined_by = cowl_annot_prop_vocab_get(v.iri.defined_by),
            .label = cowl_annot_prop_vocab_get(v.iri.label),
            .see_also = cowl_annot_prop_vocab_get(v.iri.see_also)
        }
    };
}

void cowl_rdfs_vocab_deinit(void) {
    cowl_string_vocab_free(vocab.ns);

    cowl_iri_vocab_free(vocab.iri.comment);
    cowl_iri_vocab_free(vocab.iri.defined_by);
    cowl_iri_vocab_free(vocab.iri.label);
    cowl_iri_vocab_free(vocab.iri.literal);
    cowl_iri_vocab_free(vocab.iri.see_also);

    cowl_datatype_vocab_free(vocab.dt.literal);
    cowl_annot_prop_vocab_free(vocab.annot_props.comment);
    cowl_annot_prop_vocab_free(vocab.annot_props.defined_by);
    cowl_annot_prop_vocab_free(vocab.annot_props.label);
    cowl_annot_prop_vocab_free(vocab.annot_props.see_also);
}

CowlRDFSVocab* cowl_rdfs_vocab_get(void) {
    return &vocab;
}
