/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_config_private.h"
#include "cowl_annot_prop_private.h"
#include "cowl_class_private.h"
#include "cowl_data_prop_private.h"
#include "cowl_datatype_private.h"
#include "cowl_error_handler_private.h"
#include "cowl_facet_private.h"
#include "cowl_import_loader_private.h"
#include "cowl_iri_private.h"
#include "cowl_named_ind_private.h"
#include "cowl_obj_prop_private.h"
#include "cowl_owl_vocab_private.h"
#include "cowl_parser.h"
#include "cowl_rdf_vocab_private.h"
#include "cowl_rdfs_vocab_private.h"
#include "cowl_string_private.h"
#include "cowl_xsd_vocab_private.h"

static bool cowl_api_initialized = false;
static CowlErrorHandler global_error_handler;
static CowlImportLoader global_import_loader;
static CowlParser global_parser;

static void cowl_api_config_init(void) {
    global_error_handler = (CowlErrorHandler){};
    global_import_loader = (CowlImportLoader){};
    global_parser = cowl_api_default_parser();
}

static void cowl_api_config_deinit(void) {
    cowl_error_handler_deinit(global_error_handler);
    cowl_import_loader_deinit(global_import_loader);
}

cowl_ret cowl_api_init(void) {
    if (cowl_api_initialized) return COWL_OK;
    cowl_api_initialized = true;
    cowl_api_config_init();

    if (cowl_annot_prop_api_init() ||
        cowl_class_api_init() ||
        cowl_data_prop_api_init() ||
        cowl_datatype_api_init() ||
        cowl_iri_api_init() ||
        cowl_named_ind_api_init() ||
        cowl_obj_prop_api_init() ||
        cowl_string_api_init() ||
        cowl_owl_vocab_init() ||
        cowl_rdf_vocab_init() ||
        cowl_rdfs_vocab_init() ||
        cowl_xsd_vocab_init() ||
        cowl_facet_init()) {
        return COWL_ERR_MEM;
    }

    return COWL_OK;
}

void cowl_api_deinit(void) {
    if (!cowl_api_initialized) return;
    cowl_facet_deinit();
    cowl_owl_vocab_deinit();
    cowl_rdf_vocab_deinit();
    cowl_rdfs_vocab_deinit();
    cowl_xsd_vocab_deinit();
    cowl_annot_prop_api_deinit();
    cowl_class_api_deinit();
    cowl_data_prop_api_deinit();
    cowl_datatype_api_deinit();
    cowl_iri_api_deinit();
    cowl_named_ind_api_deinit();
    cowl_obj_prop_api_deinit();
    cowl_string_api_deinit();
    cowl_api_config_deinit();
    cowl_api_initialized = false;
}

CowlErrorHandler cowl_api_get_error_handler(void) {
    return (CowlErrorHandler){
        .ctx = global_error_handler.ctx,
        .handle_error = global_error_handler.handle_error
    };
}

void cowl_api_set_error_handler(CowlErrorHandler handler) {
    global_error_handler = handler;
}

CowlImportLoader cowl_api_get_import_loader(void) {
    return (CowlImportLoader){
        .ctx = global_import_loader.ctx,
        .load_ontology = global_import_loader.load_ontology
    };
}

void cowl_api_set_import_loader(CowlImportLoader loader) {
    global_import_loader = loader;
}

CowlParser cowl_api_get_parser(void) {
    return global_parser;
}

void cowl_api_set_parser(CowlParser parser) {
    global_parser = parser;
}

CowlParser cowl_api_default_parser(void) {
#ifdef COWL_PARSER_FUNCTIONAL
    return cowl_parser_get_functional();
#else
    return (CowlParser){};
#endif
}