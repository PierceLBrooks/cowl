/**
 * Declares CowlDataProp and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_DATA_PROP_H
#define COWL_DATA_PROP_H

#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlIRI);
cowl_struct_decl(CowlDataProp);
/// @endcond

/**
 * Represents a [DataProperty] in the OWL 2 specification.
 *
 * [DataProperty]: https://www.w3.org/TR/owl2-syntax/#Data_Properties
 *
 * @struct CowlDataProp
 * @extends CowlDataPropExp
 */

/**
 * Returns a retained data property.
 *
 * @param iri IRI of the data property.
 * @return Retained data property.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
CowlDataProp* cowl_data_prop_get(CowlIRI *iri);

/**
 * Retains the specified data property.
 *
 * @param prop The data property.
 * @return Retained data property.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
CowlDataProp* cowl_data_prop_retain(CowlDataProp *prop);

/**
 * Releases the specified data property.
 *
 * @param prop The data property.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
void cowl_data_prop_release(CowlDataProp *prop);

/**
 * Gets the IRI of the specified data property.
 *
 * @param prop The data property.
 * @return The IRI.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
CowlIRI* cowl_data_prop_get_iri(CowlDataProp *prop);

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
bool cowl_data_prop_equals(CowlDataProp *lhs, CowlDataProp *rhs);

/**
 * Hash function.
 *
 * @param prop The property.
 * @return The hash value.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
cowl_uint_t cowl_data_prop_hash(CowlDataProp *prop);

/**
 * Iterates over the signature of the specified data property.
 *
 * @param prop The data property.
 * @param iter The entity iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlDataProp
 */
COWL_PUBLIC
bool cowl_data_prop_iterate_signature(CowlDataProp *prop, CowlEntityIterator *iter);

COWL_END_DECLS

#endif // COWL_DATA_PROP_H
