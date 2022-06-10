/**
 * Declares CowlObjOneOf and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2022 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_ONE_OF_H
#define COWL_OBJ_ONE_OF_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlObjOneOf);
/// @endcond

/**
 * Represents [ObjectOneOf] in the OWL 2 specification.
 *
 * [ObjectOneOf]: https://www.w3.org/TR/owl2-syntax/#Enumeration_of_Individuals
 *
 * @struct CowlObjOneOf
 * @extends CowlClsExp
 */

/**
 * Returns a retained individual enumeration.
 *
 * @param inds The individuals.
 * @return Retained individual enumeration, or NULL on error.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
CowlObjOneOf* cowl_obj_one_of_get(CowlVector *inds) {
    return (CowlObjOneOf *)cowl_get_impl_1(COWL_OT_CE_OBJ_ONE_OF, inds);
}

/**
 * Retains the specified individual enumeration.
 *
 * @param exp The individual enumeration.
 * @return Retained individual enumeration.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
CowlObjOneOf* cowl_obj_one_of_retain(CowlObjOneOf *exp) {
    return (CowlObjOneOf *)cowl_retain(exp);
}

/**
 * Releases the specified individual enumeration.
 *
 * @param exp The individual enumeration.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
void cowl_obj_one_of_release(CowlObjOneOf *exp) {
    cowl_release_impl(exp);
}

/**
 * Gets the individuals of the specified enumeration.
 *
 * @param exp The individual enumeration.
 * @return The individuals.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
CowlVector* cowl_obj_one_of_get_inds(CowlObjOneOf *exp) {
    return (CowlVector *)cowl_get_field(exp, 0);
}

/**
 * Returns the string representation of the specified individual enumeration.
 *
 * @param exp The individual enumeration.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
CowlString* cowl_obj_one_of_to_string(CowlObjOneOf *exp) {
    return cowl_to_string_impl(exp);
}

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
bool cowl_obj_one_of_equals(CowlObjOneOf *lhs, CowlObjOneOf *rhs) {
    return cowl_equals_impl(lhs, rhs);
}

/**
 * Hash function.
 *
 * @param exp The individual enumeration.
 * @return The hash value.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
ulib_uint cowl_obj_one_of_hash(CowlObjOneOf *exp) {
    return cowl_hash_impl(exp);
}

/**
 * Iterates over the primitives referenced by the specified individual enumeration.
 *
 * @param exp The individual enumeration.
 * @param flags Iteration flags.
 * @param iter The iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlObjOneOf
 */
COWL_INLINE
bool cowl_obj_one_of_iterate_primitives(CowlObjOneOf *exp, CowlPrimitiveFlags flags,
                                        CowlIterator *iter) {
    return cowl_iterate_primitives_impl(exp, flags, iter);
}

COWL_END_DECLS

#endif // COWL_OBJ_ONE_OF_H
