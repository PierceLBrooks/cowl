/// @author Ivano Bilenchi

#include "cowl_anon_individual_private.h"
#include "cowl_hash_utils.h"
#include "cowl_string.h"
#include "khash_utils.h"

#pragma mark - Instance map

KHASH_MAP_UTILS_INIT(CowlAnonIndividualMap, CowlString const*, CowlAnonIndividual*,
                     cowl_string_hash, cowl_string_equals);
static khash_t(CowlAnonIndividualMap) *inst_map = NULL;

#pragma mark - Private

static CowlAnonIndividual* cowl_anon_individual_alloc(CowlString const *id) {
    CowlAnonIndividual init = {
        .super = COWL_INDIVIDUAL_INIT(false),
        .id = cowl_string_retain(id)
    };
    CowlAnonIndividual *ind = malloc(sizeof(*ind));
    memcpy(ind, &init, sizeof(*ind));
    return ind;
}

static void cowl_anon_individual_free(CowlAnonIndividual const *ind) {
    if (!ind) return;
    cowl_string_release(ind->id);
    free((void *)ind);
}

#pragma mark - Public

CowlAnonIndividual const* cowl_anon_individual_get(CowlString const *id) {
    if (!inst_map) inst_map = kh_init(CowlAnonIndividualMap);

    CowlAnonIndividual *ind;
    bool absent;
    khint_t idx = kh_put_key(CowlAnonIndividualMap, inst_map, id, &absent);

    if (absent) {
        ind = cowl_anon_individual_alloc(id);
        kh_value(inst_map, idx) = ind;
    } else {
        ind = kh_value(inst_map, idx);
        cowl_individual_ref_incr(ind);
    }

    return ind;
}

CowlAnonIndividual const* cowl_anon_individual_retain(CowlAnonIndividual const *ind) {
    return cowl_individual_ref_incr(ind);
}

void cowl_anon_individual_release(CowlAnonIndividual const *ind) {
    if (ind && !cowl_individual_ref_decr(ind)) {
        kh_del_val(CowlAnonIndividualMap, inst_map, ind->id);
        cowl_anon_individual_free(ind);
    }
}

CowlString const* cowl_anon_individual_get_id(CowlAnonIndividual const *ind) {
    return ind->id;
}

bool cowl_anon_individual_equals(CowlAnonIndividual const *lhs, CowlAnonIndividual const *rhs) {
    return lhs == rhs;
}

uint32_t cowl_anon_individual_hash(CowlAnonIndividual const *ind) {
    return kh_ptr_hash_func(ind);
}
