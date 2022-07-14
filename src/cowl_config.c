/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_config_private.h"
#include "cowl_entity_private.h"
#include "cowl_error_handler_private.h"
#include "cowl_import_loader_private.h"
#include "cowl_iri_private.h"
#include "cowl_owl_vocab_private.h"
#include "cowl_parser.h"
#include "cowl_rdf_vocab_private.h"
#include "cowl_rdfs_vocab_private.h"
#include "cowl_string_private.h"
#include "cowl_writer.h"
#include "cowl_xsd_vocab_private.h"

static bool cowl_api_initialized = false;
static CowlErrorHandler global_error_handler;
static CowlImportLoader global_import_loader;
static CowlParser global_parser;
static CowlWriter global_writer;

#ifdef COWL_DEFAULT_PARSER
    #define cowl_api_default_parser() P_ULIB_MACRO_CONCAT(cowl_parser_get_, COWL_DEFAULT_PARSER)()
#else
    #define cowl_api_default_parser() ((CowlParser){0})
#endif

#ifdef COWL_DEFAULT_WRITER
    #define cowl_api_default_writer() P_ULIB_MACRO_CONCAT(cowl_writer_get_, COWL_DEFAULT_WRITER)()
#else
    #define cowl_api_default_writer() ((CowlWriter){0})
#endif

static void cowl_api_config_init(void) {
    global_error_handler = (CowlErrorHandler){0};
    global_import_loader = (CowlImportLoader){0};
    global_parser = cowl_api_default_parser();
    global_writer = cowl_api_default_writer();

    ulib_int seed = (ulib_int)utime_get_ns();
    urand_set_seed(seed ? seed : 12345);
}

static void cowl_api_config_deinit(void) {
    cowl_error_handler_deinit(global_error_handler);
    cowl_import_loader_deinit(global_import_loader);
}

cowl_ret cowl_api_init(void) {
    if (cowl_api_initialized) return COWL_OK;
    cowl_api_initialized = true;
    cowl_api_config_init();

    if (cowl_object_api_init() ||
        cowl_iri_api_init() ||
        cowl_entity_api_init() ||
        cowl_string_api_init() ||
        cowl_owl_vocab_init() ||
        cowl_rdf_vocab_init() ||
        cowl_rdfs_vocab_init() ||
        cowl_xsd_vocab_init()) {
        return COWL_ERR_MEM;
    }

    return COWL_OK;
}

void cowl_api_deinit(void) {
    if (!cowl_api_initialized) return;
    cowl_owl_vocab_deinit();
    cowl_rdf_vocab_deinit();
    cowl_rdfs_vocab_deinit();
    cowl_xsd_vocab_deinit();
    cowl_entity_api_deinit();
    cowl_iri_api_deinit();
    cowl_string_api_deinit();
    cowl_object_api_deinit();
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

CowlWriter cowl_api_get_writer(void) {
    return global_writer;
}

void cowl_api_set_parser(CowlParser parser) {
    global_parser = parser;
}

void cowl_api_set_writer(CowlWriter writer) {
    global_writer = writer;
}
