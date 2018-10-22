/// @author Ivano Bilenchi

#ifndef COWL_IRI_PRIVATE_H
#define COWL_IRI_PRIVATE_H

#include "cowl_iri.h"

COWL_BEGIN_DECLS

typedef struct CowlIRI {
    uint32_t ref_count;
    CowlString const *ns;
    CowlString const *rem;
} CowlIRI;

#define COWL_IRI_INIT(NS, REM) { .ref_count = 1, .ns = NS, .rem = REM }

#define cowl_iri_ref_get(i) (((CowlIRI *)(i))->ref_count)
#define cowl_iri_ref_incr(i) (++cowl_iri_ref_get(i), (i))
#define cowl_iri_ref_decr(i) (--cowl_iri_ref_get(i))

COWL_END_DECLS

#endif // COWL_IRI_PRIVATE_H
