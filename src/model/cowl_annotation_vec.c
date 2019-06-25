/// @author Ivano Bilenchi

#include "cowl_annotation_vec_private.h"
#include "cowl_annotation.h"
#include "cowl_hash_utils.h"

VECTOR_IMPL_EQUATABLE(CowlAnnotationPtr, cowl_annotation_equals)

void cowl_annotation_vec_free(CowlAnnotationVec *vec) {
    vector_deep_free(CowlAnnotationPtr, (Vector(CowlAnnotationPtr)*)vec, cowl_annotation_release);
}

void cowl_annotation_vec_push(CowlMutableAnnotationVec *vec, CowlAnnotation *annot) {
    vector_push(CowlAnnotationPtr, vec, cowl_annotation_retain(annot));
}

bool cowl_annotation_vec_equals(CowlAnnotationVec *lhs, CowlAnnotationVec *rhs) {
    return vector_equals(CowlAnnotationPtr, lhs, rhs);
}

cowl_uint_t cowl_annotation_vec_hash(CowlAnnotationVec *vec) {
    cowl_uint_t hash = 0;

    vector_foreach(CowlAnnotationPtr, vec, annot, {
        hash = cowl_hash_iter(hash, cowl_annotation_hash(annot));
    });

    return hash;
}

bool cowl_annotation_vec_iterate_signature(CowlAnnotationVec *vec, void *ctx,
                                           CowlEntityIterator iter) {
    vector_foreach(CowlAnnotationPtr, vec, annot, {
        if (!cowl_annotation_iterate_signature(annot, ctx, iter)) return false;
    });
    return true;
}