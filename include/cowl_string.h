/// @author Ivano Bilenchi

#ifndef COWL_STRING_H
#define COWL_STRING_H

#include "cowl_std.h"

COWL_BEGIN_DECLS

typedef struct CowlString const CowlString;

CowlString* cowl_string_get(char const *cstring, uint32_t length, bool owned);
CowlString* cowl_string_retain(CowlString *string);
void cowl_string_release(CowlString *string);

char const* cowl_string_get_cstring(CowlString *string);
uint32_t cowl_string_get_length(CowlString *string);

bool cowl_string_equals(CowlString *lhs, CowlString *rhs);
uint32_t cowl_string_hash(CowlString *string);

COWL_END_DECLS

#endif // COWL_STRING_H
