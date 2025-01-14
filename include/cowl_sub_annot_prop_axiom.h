/**
 * Declares CowlSubAnnotPropAxiom and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_SUB_ANNOT_PROP_AXIOM_H
#define COWL_SUB_ANNOT_PROP_AXIOM_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlAnnotProp);
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlSubAnnotPropAxiom);
/// @endcond

/**
 * Represents a [SubAnnotationPropertyOf] axiom in the OWL 2 specification.
 *
 * [SubAnnotationPropertyOf]: https://www.w3.org/TR/owl2-syntax/#Annotation_Subproperties
 *
 * @struct CowlSubAnnotPropAxiom
 * @extends CowlAxiom
 */

/**
 * Returns a retained annotation subproperty axiom.
 *
 * @param sub The subproperty.
 * @param super The superproperty.
 * @param annot [optional] The annotations.
 * @return Retained axiom, or NULL on error.
 *
 * @public @memberof CowlSubAnnotPropAxiom
 */
COWL_INLINE
CowlSubAnnotPropAxiom *
cowl_sub_annot_prop_axiom(CowlAnnotProp *sub, CowlAnnotProp *super, CowlVector *annot) {
    return (CowlSubAnnotPropAxiom *)cowl_get_impl_2_annot(COWL_OT_A_SUB_ANNOT_PROP, sub, super,
                                                          annot);
}

/**
 * Gets the subproperty.
 *
 * @param axiom The axiom.
 * @return The subproperty.
 *
 * @public @memberof CowlSubAnnotPropAxiom
 */
COWL_INLINE
CowlAnnotProp *cowl_sub_annot_prop_axiom_get_sub(CowlSubAnnotPropAxiom *axiom) {
    return (CowlAnnotProp *)cowl_get_field(axiom, 0);
}

/**
 * Gets the superproperty.
 *
 * @param axiom The axiom.
 * @return The superproperty.
 *
 * @public @memberof CowlSubAnnotPropAxiom
 */
COWL_INLINE
CowlAnnotProp *cowl_sub_annot_prop_axiom_get_super(CowlSubAnnotPropAxiom *axiom) {
    return (CowlAnnotProp *)cowl_get_field(axiom, 1);
}

/**
 * Gets the annotations of the specified axiom.
 *
 * @param axiom The axiom.
 * @return The annotations.
 *
 * @public @memberof CowlSubAnnotPropAxiom
 */
COWL_INLINE
CowlVector *cowl_sub_annot_prop_axiom_get_annot(CowlSubAnnotPropAxiom *axiom) {
    return (CowlVector *)cowl_get_opt_field(axiom);
}

COWL_END_DECLS

#endif // COWL_SUB_ANNOT_PROP_AXIOM_H
