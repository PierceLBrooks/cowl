/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_func_yylexer.h"
#include "cowl_reader.h"

static void *cowl_func_reader_alloc(void) {
    void *scanner;
    return cowl_func_yylex_init(&scanner) == 0 ? scanner : NULL;
}

static void cowl_func_reader_free(void *scanner) {
    cowl_func_yylex_destroy(scanner);
}

static cowl_ret cowl_func_reader_read(void *scanner, UIStream *istream, CowlStream *stream) {
    cowl_func_yyset_in(NULL, scanner);
    cowl_func_yyset_extra(istream, scanner);
    return cowl_func_yyparse(scanner, stream) == 0 ? COWL_OK : COWL_ERR;
}

static CowlReader const cowl_func_reader = {
    .name = "functional",
    .alloc = cowl_func_reader_alloc,
    .free = cowl_func_reader_free,
    .read = cowl_func_reader_read,
};

CowlReader cowl_reader_functional(void) {
    return cowl_func_reader;
}
