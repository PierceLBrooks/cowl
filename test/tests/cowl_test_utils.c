/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_test_utils.h"
#include "cowl_manager.h"

// Test import ontology

static char const test_import[] = "test_import.owl";

// Import loader

CowlOntology* cowl_test_load_import(cowl_unused void *ctx, cowl_unused CowlIRI *iri) {
    CowlManager *manager = cowl_manager_get();
    CowlOntology *onto = cowl_manager_read_path(manager, test_import);
    cowl_manager_release(manager);
    return onto;
}
