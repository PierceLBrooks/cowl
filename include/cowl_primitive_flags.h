/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2020-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_PRIMITIVE_FLAGS_H
#define COWL_PRIMITIVE_FLAGS_H

#include "cowl_std.h"
#include "cowl_primitive_type.h"

COWL_BEGIN_DECLS

/// Size of the CowlPrimitiveFlags type in bits.
#define COWL_PF 8

/// These flags are used to control iteration over primitives.
typedef UFlags(COWL_PF) CowlPrimitiveFlags;

/// Iterate over no primitives.
#define COWL_PF_NONE        uflags_none(COWL_PF)

/// Iterate over all primitives.
#define COWL_PF_ALL         uflags_all(COWL_PF)

/// Iterate over classes.
#define COWL_PF_CLASS       uflags_bit(COWL_PF, 0)

/// Iterate over object properties.
#define COWL_PF_OBJ_PROP    uflags_bit(COWL_PF, 1)

/// Iterate over data properties.
#define COWL_PF_DATA_PROP   uflags_bit(COWL_PF, 2)

/// Iterate over annotation properties.
#define COWL_PF_ANNOT_PROP  uflags_bit(COWL_PF, 3)

/// Iterate over named individuals.
#define COWL_PF_NAMED_IND   uflags_bit(COWL_PF, 4)

/// Iterate over anonymous individuals.
#define COWL_PF_ANON_IND    uflags_bit(COWL_PF, 5)

/// Iterate over datatypes.
#define COWL_PF_DATATYPE    uflags_bit(COWL_PF, 6)

/// Iterate over entities.
#define COWL_PF_ENTITY      (COWL_PF_CLASS | COWL_PF_OBJ_PROP | COWL_PF_DATA_PROP | \
                             COWL_PF_ANNOT_PROP | COWL_PF_NAMED_IND | COWL_PF_DATATYPE)

/**
 * Returns a bitmask with a bit set for the specified primitive type.
 *
 * @param type Primitive type.
 * @return Flags.
 *
 * @public
 */
COWL_INLINE
CowlPrimitiveFlags cowl_primitive_flags_from_type(CowlPrimitiveType type) {
    return uflags_bit(COWL_PF, type);
}

/**
 * Checks whether the specified type is included in the flags.
 *
 * @param flags Primitive flags.
 * @param type Primitive type.
 * @return True if the type is included in the flags, false otherwise.
 *
 * @public
 */
COWL_INLINE
bool cowl_primitive_flags_has_type(CowlPrimitiveFlags flags, CowlPrimitiveType type) {
    return uflags_is_set(COWL_PF, flags, uflags_bit(COWL_PF, type));
}

COWL_END_DECLS

#endif // COWL_PRIMITIVE_FLAGS_H
