/// @author Ivano Bilenchi

#ifndef COWL_OBJ_PROP_H
#define COWL_OBJ_PROP_H

#include "cowl_std.h"

COWL_BEGIN_DECLS

typedef struct CowlIRI CowlIRI;

typedef struct CowlObjProp CowlObjProp;

CowlIRI const* cowl_obj_prop_get_iri(CowlObjProp const *prop);

bool cowl_obj_prop_equals(CowlObjProp const *lhs, CowlObjProp const *rhs);
uint32_t cowl_obj_prop_hash(CowlObjProp const *prop);

COWL_END_DECLS

#endif // COWL_OBJ_PROP_H