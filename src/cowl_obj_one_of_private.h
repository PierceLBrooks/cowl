/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_ONE_OF_PRIVATE_H
#define COWL_OBJ_ONE_OF_PRIVATE_H

#include "cowl_obj_one_of.h"
#include "cowl_cls_exp_private.h"

COWL_BEGIN_DECLS

struct CowlObjOneOf {
    CowlClsExp super;
    CowlObjectVec *inds;
};

COWL_END_DECLS

#endif // COWL_OBJ_ONE_OF_PRIVATE_H
