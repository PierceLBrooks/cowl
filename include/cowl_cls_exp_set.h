/// @author Ivano Bilenchi

#ifndef COWL_CLS_EXP_SET_H
#define COWL_CLS_EXP_SET_H

#include "cowl_std.h"
#include "khash_utils.h"

COWL_BEGIN_DECLS

typedef struct CowlClsExp CowlClsExp;

KHASH_SET_UTILS_DECL(CowlClsExpSet, CowlClsExp const*);

bool cowl_cls_exp_set_add(khash_t(CowlClsExpSet) *set, CowlClsExp const *exp);
void cowl_cls_exp_set_free(khash_t(CowlClsExpSet) const *set);

COWL_END_DECLS

#endif // COWL_CLS_EXP_SET_H
