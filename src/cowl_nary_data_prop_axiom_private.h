/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_NARY_DATA_PROP_AXIOM_PRIVATE_H
#define COWL_NARY_DATA_PROP_AXIOM_PRIVATE_H

#include "cowl_nary_data_prop_axiom.h"
#include "cowl_axiom_private.h"

COWL_BEGIN_DECLS

cowl_axiom_struct(CowlNAryDataPropAxiom,
    CowlObjectVec *props;
);


COWL_END_DECLS

#endif // COWL_NARY_DATA_PROP_AXIOM_PRIVATE_H
