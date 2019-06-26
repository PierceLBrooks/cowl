/// @author Ivano Bilenchi

#ifndef COWL_PARSER_H
#define COWL_PARSER_H

#include "cowl_error.h"
#include "cowl_imports_loader.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

cowl_struct_decl(CowlOntology);

cowl_struct_decl(CowlParser);

CowlParser* cowl_parser_alloc(void);
void cowl_parser_free(CowlParser *parser);

CowlOntology* cowl_parser_parse_ontology(CowlParser *parser, char const *path);

cowl_uint_t cowl_parser_get_error_count(CowlParser *parser);
Vector(CowlError) const* cowl_parser_get_errors(CowlParser *parser);
CowlError cowl_parser_get_last_error(CowlParser *parser);

void cowl_parser_set_ontology_loader(CowlParser *parser, CowlImportsLoader loader);

COWL_END_DECLS

#endif // COWL_PARSER_H
