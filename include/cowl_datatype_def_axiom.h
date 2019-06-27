/// @author Ivano Bilenchi

#ifndef COWL_DATATYPE_DEF_AXIOM_H
#define COWL_DATATYPE_DEF_AXIOM_H

#include "cowl_iterator.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

cowl_struct_decl(CowlDataRange);
cowl_struct_decl(CowlDatatype);
cowl_vector_decl(CowlAnnotationPtr, CowlAnnotationVec);

cowl_struct_decl(CowlDatatypeDefAxiom);

CowlDatatypeDefAxiom* cowl_datatype_def_axiom_get(CowlDatatype *datatype, CowlDataRange *range,
                                                  CowlAnnotationVec *annot);
CowlDatatypeDefAxiom* cowl_datatype_def_axiom_retain(CowlDatatypeDefAxiom *axiom);
void cowl_datatype_def_axiom_release(CowlDatatypeDefAxiom *axiom);

CowlDatatype* cowl_datatype_def_axiom_get_datatype(CowlDatatypeDefAxiom *axiom);
CowlDataRange* cowl_datatype_def_axiom_get_range(CowlDatatypeDefAxiom *axiom);
CowlAnnotationVec* cowl_datatype_def_axiom_get_annot(CowlDatatypeDefAxiom *axiom);

bool cowl_datatype_def_axiom_equals(CowlDatatypeDefAxiom *lhs, CowlDatatypeDefAxiom *rhs);
cowl_uint_t cowl_datatype_def_axiom_hash(CowlDatatypeDefAxiom *axiom);

bool cowl_datatype_def_axiom_iterate_signature(CowlDatatypeDefAxiom *axiom,
                                               CowlEntityIterator *iter);

COWL_END_DECLS

#endif // COWL_DATATYPE_DEF_AXIOM_H
