/**
 * Declares CowlSubDataPropAxiom and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2022 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_SUB_DATA_PROP_AXIOM_H
#define COWL_SUB_DATA_PROP_AXIOM_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlDataPropExp);
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlSubDataPropAxiom);
/// @endcond

/**
 * Represents a [SubDataPropertyOf] axiom in the OWL 2 specification.
 *
 * [SubDataPropertyOf]: https://www.w3.org/TR/owl2-syntax/#Data_Subproperties
 *
 * @struct CowlSubDataPropAxiom
 * @extends CowlAxiom
 */

/**
 * Returns a retained data subproperty axiom.
 *
 * @param sub The subproperty.
 * @param super The superproperty.
 * @param annot [optional] The annotations.
 * @return Retained axiom, or NULL on error.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlSubDataPropAxiom* cowl_sub_data_prop_axiom_get(CowlDataPropExp *sub, CowlDataPropExp *super,
                                                   CowlVector *annot) {
    return (CowlSubDataPropAxiom *)cowl_get_impl_2_opt(COWL_OT_A_SUB_DATA_PROP, sub, super, annot);
}

/**
 * Retains the specified axiom.
 *
 * @param axiom The axiom.
 * @return Retained axiom.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlSubDataPropAxiom* cowl_sub_data_prop_axiom_retain(CowlSubDataPropAxiom *axiom) {
    return (CowlSubDataPropAxiom *)cowl_retain(axiom);
}

/**
 * Releases the specified axiom.
 *
 * @param axiom The axiom.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
void cowl_sub_data_prop_axiom_release(CowlSubDataPropAxiom *axiom) {
    cowl_release_impl(axiom);
}

/**
 * Gets the subproperty.
 *
 * @param axiom The axiom.
 * @return The subproperty.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlDataPropExp* cowl_sub_data_prop_axiom_get_sub(CowlSubDataPropAxiom *axiom) {
    return (CowlDataPropExp *)cowl_get_field(axiom, 0);
}

/**
 * Gets the superproperty.
 *
 * @param axiom The axiom.
 * @return The superproperty.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlDataPropExp* cowl_sub_data_prop_axiom_get_super(CowlSubDataPropAxiom *axiom) {
    return (CowlDataPropExp *)cowl_get_field(axiom, 1);
}

/**
 * Gets the annotations of the specified axiom.
 *
 * @param axiom The axiom.
 * @return The annotations.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlVector* cowl_sub_data_prop_axiom_get_annot(CowlSubDataPropAxiom *axiom) {
    return (CowlVector *)cowl_get_opt_field(axiom);
}

/**
 * Returns the string representation of the specified axiom.
 *
 * @param axiom The axiom.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
CowlString* cowl_sub_data_prop_axiom_to_string(CowlSubDataPropAxiom *axiom) {
    return cowl_to_string_impl(axiom);
}

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
bool cowl_sub_data_prop_axiom_equals(CowlSubDataPropAxiom *lhs, CowlSubDataPropAxiom *rhs) {
    return cowl_equals_impl(lhs, rhs);
}

/**
 * Hash function.
 *
 * @param axiom The axiom.
 * @return The hash value.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
ulib_uint cowl_sub_data_prop_axiom_hash(CowlSubDataPropAxiom *axiom) {
    return cowl_hash_impl(axiom);
}

/**
 * Iterates over the primitives referenced by the specified axiom.
 *
 * @param axiom The axiom.
 * @param flags Iteration flags.
 * @param iter The iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlSubDataPropAxiom
 */
COWL_INLINE
bool cowl_sub_data_prop_axiom_iterate_primitives(CowlSubDataPropAxiom *axiom,
                                                 CowlPrimitiveFlags flags, CowlIterator *iter) {
    return cowl_iterate_primitives_impl(axiom, flags, iter);
}

COWL_END_DECLS

#endif // COWL_SUB_DATA_PROP_AXIOM_H
