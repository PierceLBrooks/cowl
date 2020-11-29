/**
 * Defines CowlError and declares its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_ERROR_H
#define COWL_ERROR_H

#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlString);
/// @endcond

/// Error data structure.
typedef cowl_struct(CowlError) {

    /// Error code.
    cowl_ret code;

    /// If code is COWL_ERR_SYNTAX, this is the line where the error occurred.
    cowl_uint line;

    /// Human readable description of the error.
    CowlString *description;

} CowlError;

/// @cond
UVEC_DECL_SPEC(CowlError, COWL_PUBLIC)
/// @endcond

/**
 * Vector of CowlError elements.
 *
 * @struct Vector_CowlError
 * @extends Vector
 */

/**
 * Returns a human-readable string representation of the specified error.
 *
 * @param error The error.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlError
 */
COWL_PUBLIC
CowlString* cowl_error_to_string(CowlError error);

COWL_END_DECLS

#endif // COWL_ERROR_H
