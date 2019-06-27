/// @author Ivano Bilenchi

#include "cowl_obj_prop_char_axiom_private.h"
#include "cowl_obj_prop_exp_private.h"

static CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_alloc(CowlAxiomType type,
                                                            CowlObjPropExp *prop,
                                                            CowlAnnotationVec *annot) {
    cowl_uint_t hash = cowl_axiom_hash_2(COWL_HASH_INIT_OBJ_PROP_CHAR_AXIOM, annot, type,
                                         cowl_obj_prop_exp_hash(prop));

    CowlObjPropCharAxiom init = {
        .super = COWL_AXIOM_INIT(type, hash, annot),
        .prop_exp = cowl_obj_prop_exp_retain(prop)
    };

    cowl_struct(CowlObjPropCharAxiom) *axiom;
    cowl_axiom_alloc(axiom, init, annot);
    return axiom;
}

static void cowl_obj_prop_char_axiom_free(CowlObjPropCharAxiom *axiom) {
    if (!axiom) return;
    cowl_obj_prop_exp_release(axiom->prop_exp);
    cowl_axiom_free(axiom);
}

CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_get(CowlObjPropCharAxiomType type,
                                                   CowlObjPropExp *prop,
                                                   CowlAnnotationVec *annot) {
    CowlAxiomType axiom_type = (CowlAxiomType)type + CAT_FUNCTIONAL_OBJ_PROP;
    return cowl_obj_prop_char_axiom_alloc(axiom_type, prop, annot);
}

CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_retain(CowlObjPropCharAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_obj_prop_char_axiom_release(CowlObjPropCharAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_obj_prop_char_axiom_free(axiom);
    }
}

CowlObjPropCharAxiomType cowl_obj_prop_char_axiom_get_type(CowlObjPropCharAxiom *axiom) {
    CowlAxiomFlags flags = axiom->super.flags;
    return (CowlObjPropCharAxiomType)(cowl_axiom_flags_get_type(flags) - CAT_FUNCTIONAL_OBJ_PROP);
}

CowlObjPropExp* cowl_obj_prop_char_axiom_get_prop(CowlObjPropCharAxiom *axiom) {
    return axiom->prop_exp;
}

CowlAnnotationVec* cowl_obj_prop_char_axiom_get_annot(CowlObjPropCharAxiom *axiom) {
    return cowl_axiom_get_annot(axiom);
}

bool cowl_obj_prop_char_axiom_equals(CowlObjPropCharAxiom *lhs, CowlObjPropCharAxiom *rhs) {
    return cowl_axiom_equals_impl(lhs, rhs, cowl_obj_prop_exp_equals(lhs->prop_exp, rhs->prop_exp));
}

cowl_uint_t cowl_obj_prop_char_axiom_hash(CowlObjPropCharAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_obj_prop_char_axiom_iterate_signature(CowlObjPropCharAxiom *axiom,
                                                CowlEntityIterator *iter) {
    if (!cowl_obj_prop_exp_iterate_signature(axiom->prop_exp, iter)) return false;
    if (!cowl_axiom_annot_iterate_signature(axiom, iter)) return false;
    return true;
}
