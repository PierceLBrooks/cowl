/**
 * Declares CowlObjHasSelf and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_HAS_SELF_H
#define COWL_OBJ_HAS_SELF_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlObjPropExp);
cowl_struct_decl(CowlObjHasSelf);
/// @endcond

/**
 * Represents [ObjectHasSelf] in the OWL 2 specification.
 *
 * [ObjectHasSelf]: https://www.w3.org/TR/owl2-syntax/#Self-Restriction
 *
 * @struct CowlObjHasSelf
 * @extends CowlClsExp
 */

/**
 * Returns a retained self-restriction.
 *
 * @param prop The property expression.
 * @return Retained restriction, or NULL on error.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_INLINE
CowlObjHasSelf *cowl_obj_has_self(CowlAnyObjPropExp *prop) {
    return (CowlObjHasSelf *)cowl_get_impl_1(COWL_OT_CE_OBJ_HAS_SELF, prop);
}

/**
 * Gets the object property expression of the specified self-restriction.
 *
 * @param exp The restriction.
 * @return The object property expression.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_INLINE
CowlObjPropExp *cowl_obj_has_self_get_prop(CowlObjHasSelf *exp) {
    return (CowlObjPropExp *)cowl_get_field(exp, 0);
}

COWL_END_DECLS

#endif // COWL_OBJ_HAS_SELF_H
