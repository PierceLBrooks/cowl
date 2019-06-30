/// @author Ivano Bilenchi

#ifndef COWL_STRING_PRIVATE_H
#define COWL_STRING_PRIVATE_H

#include "cowl_string.h"
#include "cowl_object.h"
#include "cowl_raw_string.h"

COWL_BEGIN_DECLS

cowl_struct(CowlString) {
    CowlHashObject super;
    CowlRawString raw_string;
};

cowl_struct(CowlString)* cowl_string_alloc(CowlRawString raw_string);

void cowl_string_split_two(char const *cstring, cowl_uint_t length,
                           char character, CowlString **out);

COWL_END_DECLS

#endif // COWL_STRING_PRIVATE_H
