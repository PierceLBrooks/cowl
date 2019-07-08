/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_rdf_vocab_private.h"
#include "cowl_vocab_utils.h"

static cowl_struct(CowlRDFVocab) vocab;

void cowl_rdf_vocab_init(void) {
    CowlString *ns = cowl_string_vocab_get("http://www.w3.org/1999/02/22-rdf-syntax-ns#");

    CowlRDFVocab v = {
        .iri = {
            .plain_literal = cowl_iri_vocab_get(ns, "PlainLiteral"),
            .xml_literal = cowl_iri_vocab_get(ns, "XMLLiteral"),
            .lang_range = cowl_iri_vocab_get(ns, "langRange")
        }
    };

    vocab = (cowl_struct(CowlRDFVocab)) {
        .ns = ns,
        .iri = v.iri,
        .dt = {
            .plain_literal = cowl_datatype_vocab_get(v.iri.plain_literal),
            .xml_literal = cowl_datatype_vocab_get(v.iri.xml_literal)
        }
    };
}

void cowl_rdf_vocab_deinit(void) {
    cowl_string_vocab_free(vocab.ns);
    cowl_iri_vocab_free(vocab.iri.plain_literal);
    cowl_iri_vocab_free(vocab.iri.xml_literal);
    cowl_iri_vocab_free(vocab.iri.lang_range);
    cowl_datatype_vocab_free(vocab.dt.plain_literal);
    cowl_datatype_vocab_free(vocab.dt.xml_literal);
}

CowlRDFVocab* cowl_rdf_vocab_get(void) {
    return &vocab;
}
