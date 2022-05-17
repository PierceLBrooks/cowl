/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_CARD_PRIVATE_H
#define COWL_OBJ_CARD_PRIVATE_H

#include "cowl_obj_card.h"
#include "cowl_object_private.h"

COWL_BEGIN_DECLS

struct CowlObjCard {
    CowlObject super;
    ulib_uint cardinality;
    CowlObjPropExp *prop;
    CowlClsExp *filler;
};

COWL_END_DECLS

#endif // COWL_OBJ_CARD_PRIVATE_H
