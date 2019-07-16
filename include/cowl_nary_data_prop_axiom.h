/**
 * Declares CowlNAryDataPropAxiom and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_NARY_DATA_PROP_AXIOM_H
#define COWL_NARY_DATA_PROP_AXIOM_H

#include "cowl_iterator.h"
#include "cowl_nary_axiom_type.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_hash_decl(CowlDataPropExpSet);
cowl_vector_decl(CowlAnnotationPtr, CowlAnnotationVec);
cowl_struct_decl(CowlNAryDataPropAxiom);
/// @endcond

/**
 * Represents an [EquivalentDataProperties] or [DisjointDataProperties] axiom
 * in the OWL 2 specification.
 *
 * [EquivalentDataProperties]: https://www.w3.org/TR/owl2-syntax/#Equivalent_Data_Properties
 * [DisjointDataProperties]: https://www.w3.org/TR/owl2-syntax/#Disjoint_Data_Properties
 *
 * @struct CowlNAryDataPropAxiom
 * @extends CowlAxiom
 */

/**
 * Returns a retained N-ary data property axiom.
 *
 * @param type The type.
 * @param props The data properties.
 * @param annot The annotations.
 * @return Retained axiom.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlNAryDataPropAxiom* cowl_nary_data_prop_axiom_get(CowlNAryAxiomType type,
                                                     CowlDataPropExpSet *props,
                                                     CowlAnnotationVec *annot);

/**
 * Retains the specified axiom.
 *
 * @param axiom The axiom.
 * @return Retained axiom.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlNAryDataPropAxiom* cowl_nary_data_prop_axiom_retain(CowlNAryDataPropAxiom *axiom);

/**
 * Releases the specified axiom.
 *
 * @param axiom The axiom.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
void cowl_nary_data_prop_axiom_release(CowlNAryDataPropAxiom *axiom);

/**
 * Gets the type of the specified N-ary data property axiom.
 *
 * @param axiom The axiom.
 * @return The type.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlNAryAxiomType cowl_nary_data_prop_axiom_get_type(CowlNAryDataPropAxiom *axiom);

/**
 * Gets the data properties of the specified N-ary data property axiom.
 *
 * @param axiom The axiom.
 * @return The data properties.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlDataPropExpSet* cowl_nary_data_prop_axiom_get_props(CowlNAryDataPropAxiom *axiom);

/**
 * Gets the annotations of the specified axiom.
 *
 * @param axiom The axiom.
 * @return The annotations.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlAnnotationVec* cowl_nary_data_prop_axiom_get_annot(CowlNAryDataPropAxiom *axiom);

/**
 * Returns the string representation of the specified axiom.
 *
 * @param axiom The axiom.
 * @return String representation.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
CowlString* cowl_nary_data_prop_axiom_to_string(CowlNAryDataPropAxiom *axiom);

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
bool cowl_nary_data_prop_axiom_equals(CowlNAryDataPropAxiom *lhs, CowlNAryDataPropAxiom *rhs);

/**
 * Hash function.
 *
 * @param axiom The axiom.
 * @return The hash value.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
cowl_uint_t cowl_nary_data_prop_axiom_hash(CowlNAryDataPropAxiom *axiom);

/**
 * Iterates over the signature of the specified axiom.
 *
 * @param axiom The axiom.
 * @param iter The entity iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlNAryDataPropAxiom
 */
COWL_PUBLIC
bool cowl_nary_data_prop_axiom_iterate_signature(CowlNAryDataPropAxiom *axiom,
                                                 CowlEntityIterator *iter);

COWL_END_DECLS

#endif // COWL_NARY_DATA_PROP_AXIOM_H
