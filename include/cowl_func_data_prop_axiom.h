/**
 * Declares CowlFuncDataPropAxiom and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_FUNC_DATA_PROP_AXIOM_H
#define COWL_FUNC_DATA_PROP_AXIOM_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlDataPropExp);
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlFuncDataPropAxiom);
/// @endcond

/**
 * Represents a [FunctionalDataProperty] axiom in the OWL 2 Specification.
 *
 * [FunctionalDataProperty]: https://www.w3.org/TR/owl2-syntax/#Functional_Data_Properties
 *
 * @struct CowlFuncDataPropAxiom
 * @extends CowlAxiom
 */

/**
 * Returns a retained functional data property axiom.
 *
 * @param prop The data property.
 * @param annot [optional] The annotations.
 * @return Retained axiom, or NULL on error.
 *
 * @public @memberof CowlFuncDataPropAxiom
 */
COWL_INLINE
CowlFuncDataPropAxiom *cowl_func_data_prop_axiom(CowlAnyDataPropExp *prop, CowlVector *annot) {
    return (CowlFuncDataPropAxiom *)cowl_get_impl_1_annot(COWL_OT_A_FUNC_DATA_PROP, prop, annot);
}

/**
 * Gets the data property.
 *
 * @param axiom The axiom.
 * @return The data property.
 *
 * @public @memberof CowlFuncDataPropAxiom
 */
COWL_INLINE
CowlDataPropExp *cowl_func_data_prop_axiom_get_prop(CowlFuncDataPropAxiom *axiom) {
    return (CowlDataPropExp *)cowl_get_field(axiom, 0);
}

/**
 * Gets the annotations of the specified axiom.
 *
 * @param axiom The axiom.
 * @return The annotations.
 *
 * @public @memberof CowlFuncDataPropAxiom
 */
COWL_INLINE
CowlVector *cowl_func_data_prop_axiom_get_annot(CowlFuncDataPropAxiom *axiom) {
    return (CowlVector *)cowl_get_opt_field(axiom);
}

COWL_END_DECLS

#endif // COWL_FUNC_DATA_PROP_AXIOM_H
