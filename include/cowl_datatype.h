/**
 * Declares CowlDatatype and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_DATATYPE_H
#define COWL_DATATYPE_H

#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlIRI);
cowl_struct_decl(CowlDatatype);
/// @endcond

/**
 * Represents a [Datatype] in the OWL 2 specification.
 *
 * [Datatype]: https://www.w3.org/TR/owl2-syntax/#Datatypes
 *
 * @struct CowlDatatype
 * @extends CowlDataRange
 */

/**
 * Returns a retained datatype.
 *
 * @param iri IRI of the datatype.
 * @return Retained datatype.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
CowlDatatype* cowl_datatype_get(CowlIRI *iri);

/**
 * Retains the specified datatype.
 *
 * @param dt The datatype.
 * @return Retained datatype.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
CowlDatatype* cowl_datatype_retain(CowlDatatype *dt);

/**
 * Releases the specified datatype.
 *
 * @param dt The datatype.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
void cowl_datatype_release(CowlDatatype *dt);

/**
 * Gets the IRI of the specified datatype.
 *
 * @param dt The datatype.
 * @return The IRI.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
CowlIRI* cowl_datatype_get_iri(CowlDatatype *dt);

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
bool cowl_datatype_equals(CowlDatatype *lhs, CowlDatatype *rhs);

/**
 * Hash function.
 *
 * @param dt The datatype.
 * @return The hash value.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
cowl_uint_t cowl_datatype_hash(CowlDatatype *dt);

/**
 * Iterates over the signature of the specified datatype.
 *
 * @param dt The datatype.
 * @param iter The entity iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlDatatype
 */
COWL_PUBLIC
bool cowl_datatype_iterate_signature(CowlDatatype *dt, CowlEntityIterator *iter);

COWL_END_DECLS

#endif // COWL_DATATYPE_H
