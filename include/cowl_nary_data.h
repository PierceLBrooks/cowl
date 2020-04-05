/**
 * Declares CowlNAryData and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_NARY_DATA_H
#define COWL_NARY_DATA_H

#include "cowl_std.h"
#include "cowl_iterator.h"
#include "cowl_nary_type.h"

COWL_BEGIN_DECLS

/// @cond
cowl_hash_decl(CowlDataRangeSet);
cowl_struct_decl(CowlNAryData);
/// @endcond

/**
 * Represents [DataIntersectionOf] and [DataUnionOf] in the OWL 2 specification.
 *
 * [DataIntersectionOf]: https://www.w3.org/TR/owl2-syntax/#Intersection_of_Data_Ranges
 * [DataUnionOf]: https://www.w3.org/TR/owl2-syntax/#Union_of_Data_Ranges
 *
 * @struct CowlNAryData
 * @extends CowlDataRange
 */

/**
 * Returns a retained N-ary data range.
 *
 * @param type N-ary data range type.
 * @param operands The operands.
 * @return Retained N-ary data range, or NULL on error.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
CowlNAryData* cowl_nary_data_get(CowlNAryType type, CowlDataRangeSet *operands);

/**
 * Retains the specified N-ary data range.
 *
 * @param range The data range.
 * @return Retained N-ary data range.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
CowlNAryData* cowl_nary_data_retain(CowlNAryData *range);

/**
 * Releases the specified N-ary data range.
 *
 * @param range The data range.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
void cowl_nary_data_release(CowlNAryData *range);

/**
 * Gets the type of the specified N-ary data range.
 * @param range The data range.
 * @return The type.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
CowlNAryType cowl_nary_data_get_type(CowlNAryData *range);

/**
 * Gets the operands of the specified N-ary data range.
 *
 * @param range The data range.
 * @return The operands.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
CowlDataRangeSet* cowl_nary_data_get_operands(CowlNAryData *range);

/**
 * Returns the string representation of the specified N-ary data range.
 *
 * @param range The data range.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
CowlString* cowl_nary_data_to_string(CowlNAryData *range);

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
bool cowl_nary_data_equals(CowlNAryData *lhs, CowlNAryData *rhs);

/**
 * Hash function.
 *
 * @param range The data range.
 * @return The hash value.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
cowl_uint_t cowl_nary_data_hash(CowlNAryData *range);

/**
 * Iterates over the signature of the specified N-ary data range.
 *
 * @param range The data range.
 * @param iter The entity iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
bool cowl_nary_data_iterate_signature(CowlNAryData *range, CowlEntityIterator *iter);

/**
 * Iterates over the primitives referenced by the specified N-ary data range.
 *
 * @param range The data range.
 * @param iter The primitive iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlNAryData
 */
COWL_PUBLIC
bool cowl_nary_data_iterate_primitives(CowlNAryData *range, CowlPrimitiveIterator *iter);

COWL_END_DECLS

#endif // COWL_NARY_DATA_H
