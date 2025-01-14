/**
 * Defines CowlError and declares its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_ERROR_H
#define COWL_ERROR_H

#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlIRI);
cowl_struct_decl(CowlString);
/// @endcond

/// Error location.
typedef struct CowlErrorLoc {

    /// Line where the error occurred.
    ulib_uint line;

    /// Location of the ontology where the error occurred.
    CowlString *source;

} CowlErrorLoc;

/// Error data structure.
typedef struct CowlError {

    /// Error code.
    cowl_ret code;

    /// Human readable description of the error.
    CowlString *description;

    /// Object that originated the error.
    CowlAny *origin;

} CowlError;

/// Syntax error.
typedef struct CowlSyntaxError {

    /// Base error.
    CowlError super;

    /// Error location.
    CowlErrorLoc loc;

} CowlSyntaxError;

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
CowlString *cowl_error_to_string(CowlError const *error);

COWL_END_DECLS

#endif // COWL_ERROR_H
