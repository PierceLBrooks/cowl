/**
 * Declares CowlPrimitive and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_PRIMITIVE_H
#define COWL_PRIMITIVE_H

#include "cowl_primitive_type.h"
#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlPrimitive);
/// @endcond

/**
 * Represents a primitive, a collective term for entities and anonymous individuals.
 *
 * @struct CowlPrimitive
 * @extends CowlObject
 */

/**
 * Retains the primitive.
 *
 * @param primitive The primitive.
 * @return Retained primitive.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
CowlPrimitive* cowl_primitive_retain(CowlPrimitive *primitive) {
    return (CowlPrimitive *)cowl_retain(primitive);
}

/**
 * Releases the primitive.
 *
 * @param primitive The primitive.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
void cowl_primitive_release(CowlPrimitive *primitive) {
    cowl_release(primitive);
}

/**
 * Gets the type of the primitive.
 *
 * @param primitive The primitive.
 * @return The type.
 *
 * @public @memberof CowlPrimitive
 */
COWL_PUBLIC
CowlPrimitiveType cowl_primitive_get_type(CowlPrimitive *primitive);

/**
 * Checks whether the primitive is an entity.
 *
 * @param primitive The primitive.
 * @return True if the primitive is an entity,
 *
 * @public @memberof CowlPrimitive
 */
COWL_PUBLIC
bool cowl_primitive_is_entity(CowlPrimitive *primitive);

/**
 * Returns the string representation of the specified primitive.
 *
 * @param primitive The primitive.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
CowlString* cowl_primitive_to_string(CowlPrimitive *primitive) {
    return cowl_to_string(primitive);
}

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
bool cowl_primitive_equals(CowlPrimitive *lhs, CowlPrimitive *rhs) {
    return lhs == rhs;
}

/**
 * Hash function.
 *
 * @param primitive The primitive.
 * @return The hash value.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
ulib_uint cowl_primitive_hash(CowlPrimitive *primitive) {
    return uhash_ptr_hash(primitive);
}

/**
 * Iterates over this primitive.
 *
 * @param primitive The primitive.
 * @param flags Iteration flags.
 * @param iter The iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlPrimitive
 */
COWL_INLINE
bool cowl_primitive_iterate_primitives(CowlPrimitive *primitive, CowlPrimitiveFlags flags,
                                       CowlIterator *iter) {
    return cowl_iterate_primitives(primitive, flags, iter);
}

COWL_END_DECLS

#endif // COWL_PRIMITIVE_H
