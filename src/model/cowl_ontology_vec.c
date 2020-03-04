/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_ontology_vec.h"
#include "cowl_ontology.h"

VECTOR_IMPL_EQUATABLE(CowlOntologyPtr, cowl_ontology_equals)

void cowl_ontology_vec_free(Vector(CowlOntologyPtr) *vec) {
    if (!vec) return;
    vector_foreach(CowlOntologyPtr, vec, onto, cowl_ontology_release(onto));
    vector_free(CowlOntologyPtr, vec);
}
