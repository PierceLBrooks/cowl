/// @author Ivano Bilenchi

#ifndef COWL_DECL_AXIOM_H
#define COWL_DECL_AXIOM_H

#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

cowl_vector_decl(CowlAnnotationPtr, CowlAnnotationVec);

cowl_struct_decl(CowlDeclAxiom);

CowlDeclAxiom* cowl_decl_axiom_get(CowlEntity entity, CowlAnnotationVec *annot);
CowlDeclAxiom* cowl_decl_axiom_retain(CowlDeclAxiom *axiom);
void cowl_decl_axiom_release(CowlDeclAxiom *axiom);

CowlEntity cowl_decl_axiom_get_entity(CowlDeclAxiom *axiom);
CowlAnnotationVec* cowl_decl_axiom_get_annot(CowlDeclAxiom *axiom);

bool cowl_decl_axiom_equals(CowlDeclAxiom *lhs, CowlDeclAxiom *rhs);
cowl_uint_t cowl_decl_axiom_hash(CowlDeclAxiom *axiom);

bool cowl_decl_axiom_iterate_signature(CowlDeclAxiom *axiom, CowlEntityIterator *iter);

COWL_END_DECLS

#endif // COWL_DECL_AXIOM_H
