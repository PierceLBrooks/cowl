/**
 * Declares CowlDatatype and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_DATATYPE_H
#define COWL_DATATYPE_H

#include "cowl_entity.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlDatatype);
/// @endcond

/**
 * Represents a [Datatype] in the OWL 2 specification.
 *
 * [Datatype]: https://www.w3.org/TR/owl2-syntax/#Datatypes
 *
 * @struct CowlDatatype
 * @extends CowlDataRange
 * @extends CowlEntity
 */

/**
 * Returns a retained datatype.
 *
 * @param iri IRI of the datatype.
 * @return Retained datatype, or NULL on error.
 *
 * @public @memberof CowlDatatype
 */
COWL_INLINE
CowlDatatype *cowl_datatype(CowlIRI *iri) {
    return (CowlDatatype *)cowl_entity_get_impl(COWL_OT_DR_DATATYPE, iri);
}

/**
 * Returns a retained datatype given the string representation of its IRI.
 *
 * @param string String representation of the IRI.
 * @return Retained datatype, or NULL on error.
 *
 * @public @memberof CowlDatatype
 */
COWL_INLINE
CowlDatatype *cowl_datatype_from_string(UString string) {
    return (CowlDatatype *)cowl_entity_from_string_impl(COWL_OT_DR_DATATYPE, string);
}

/**
 * Returns a retained datatype given the static string representation of its IRI.
 *
 * @param CSTR [char const[]] Static string.
 * @return [CowlDatatype *] Retained datatype, or NULL on error.
 *
 * @public @related CowlDatatype
 */
#define cowl_datatype_from_static(CSTR) cowl_datatype_from_string(ustring_literal(CSTR))

/**
 * Gets the IRI of the specified datatype.
 *
 * @param dt The datatype.
 * @return The IRI.
 *
 * @public @memberof CowlDatatype
 */
COWL_INLINE
CowlIRI *cowl_datatype_get_iri(CowlDatatype *dt) {
    return cowl_entity_get_iri((CowlEntity *)dt);
}

COWL_END_DECLS

#endif // COWL_DATATYPE_H
