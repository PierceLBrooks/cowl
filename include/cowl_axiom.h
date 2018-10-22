/// @author Ivano Bilenchi

#ifndef COWL_AXIOM_H
#define COWL_AXIOM_H

#include "cowl_axiom_type.h"
#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

typedef struct CowlAxiom const CowlAxiom;

CowlAxiom* cowl_axiom_retain(CowlAxiom *axiom);
void cowl_axiom_release(CowlAxiom *axiom);

CowlAxiomType cowl_axiom_get_type(CowlAxiom *axiom);

bool cowl_axiom_equals(CowlAxiom *lhs, CowlAxiom *rhs);
uint32_t cowl_axiom_hash(CowlAxiom *axiom);

bool cowl_axiom_iterate_signature(CowlAxiom *axiom, void *ctx, CowlEntityIterator iter);

COWL_END_DECLS

#endif // COWL_AXIOM_H
