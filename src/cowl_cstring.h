/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_CSTRING_H
#define COWL_CSTRING_H

#include "cowl_std.h"

COWL_BEGIN_DECLS

size_t cowl_str_from_uint(uint64_t uint, char *buf);
uint64_t cowl_str_to_uint(char const *string, size_t length);

COWL_END_DECLS

#endif // COWL_CSTRING_H
