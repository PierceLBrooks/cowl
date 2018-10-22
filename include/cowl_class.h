/// @author Ivano Bilenchi

#ifndef COWL_CLASS_H
#define COWL_CLASS_H

#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

typedef struct CowlIRI CowlIRI;

typedef struct CowlClass CowlClass;

CowlClass const* cowl_class_get(CowlIRI const *iri);
CowlClass const* cowl_class_retain(CowlClass const *cls);
void cowl_class_release(CowlClass const *cls);

CowlIRI const* cowl_class_get_iri(CowlClass const *cls);

bool cowl_class_equals(CowlClass const *lhs, CowlClass const *rhs);
uint32_t cowl_class_hash(CowlClass const *cls);

bool cowl_class_iterate_signature(CowlClass const *cls, void *ctx, CowlEntityIterator iter);

COWL_END_DECLS

#endif // COWL_CLASS_H
