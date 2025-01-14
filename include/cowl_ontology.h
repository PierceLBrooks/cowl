/**
 * Declares CowlOntology and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_ONTOLOGY_H
#define COWL_ONTOLOGY_H

#include "cowl_axiom_type.h"
#include "cowl_iterator.h"
#include "cowl_object.h"
#include "cowl_ontology_id.h"
#include "cowl_std.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlAnnotation);
cowl_struct_decl(CowlClass);
cowl_struct_decl(CowlManager);
cowl_struct_decl(CowlSymTable);
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlOntology);
/// @endcond

/**
 * Represents an [Ontology] in the OWL 2 specification.
 *
 * [Ontology]: https://www.w3.org/TR/owl2-syntax/#Ontologies
 *
 * @struct CowlOntology
 * @extends CowlObject
 */

/**
 * Gets the manager of this ontology.
 *
 * @param onto The ontology.
 * @return The manager.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlManager *cowl_ontology_get_manager(CowlOntology *onto);

/**
 * Gets the symbol table of this ontology.
 *
 * @param onto The ontology.
 * @return The symbol table.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlSymTable *cowl_ontology_get_sym_table(CowlOntology *onto);

/**
 * Gets the ontology ID.
 *
 * @param onto The ontology.
 * @return The ontology ID.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlOntologyId cowl_ontology_get_id(CowlOntology *onto);

/**
 * Sets the IRI of the ontology.
 *
 * @param onto The ontology.
 * @param iri The IRI.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
void cowl_ontology_set_iri(CowlOntology *onto, CowlIRI *iri);

/**
 * Sets the version IRI of the ontology.
 *
 * @param onto The ontology.
 * @param version The version IRI.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
void cowl_ontology_set_version(CowlOntology *onto, CowlIRI *version);

/**
 * Gets the annotations of the specified ontology.
 *
 * @param onto The ontology.
 * @return The annotations.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlVector *cowl_ontology_get_annot(CowlOntology *onto);

/**
 * Adds an annotation to the ontology.
 *
 * @param onto The ontology.
 * @param annot The annotation.
 * @return Return code.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
cowl_ret cowl_ontology_add_annot(CowlOntology *onto, CowlAnnotation *annot);

/**
 * Removes an annotation from the ontology.
 *
 * @param onto The ontology.
 * @param annot The annotation.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
void cowl_ontology_remove_annot(CowlOntology *onto, CowlAnnotation *annot);

/**
 * Gets an imported ontology given its import IRI.
 *
 * @param onto The ontology.
 * @param iri Import IRI.
 * @return Imported ontology.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlOntology *cowl_ontology_get_import(CowlOntology *onto, CowlIRI *iri);

/**
 * Gets the import IRI of an imported ontology.
 *
 * @param onto The ontology.
 * @param import The imported ontology.
 * @return Import IRI.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
CowlIRI *cowl_ontology_get_import_iri(CowlOntology *onto, CowlOntology *import);

/**
 * Adds an import to the ontology.
 *
 * @param onto The ontology.
 * @param import IRI of the imported ontology.
 * @return Return code.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
cowl_ret cowl_ontology_add_import(CowlOntology *onto, CowlIRI *import);

/**
 * Removes an import from the ontology.
 *
 * @param onto The ontology.
 * @param import IRI of the imported ontology.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
void cowl_ontology_remove_import(CowlOntology *onto, CowlIRI *import);

/**
 * Adds an axiom to the ontology.
 *
 * @param onto The ontology.
 * @param axiom The axiom.
 * @return Return code.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
cowl_ret cowl_ontology_add_axiom(CowlOntology *onto, CowlAnyAxiom *axiom);

/**
 * Removes an axiom from the ontology.
 *
 * @param onto The ontology.
 * @param axiom The axiom.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
void cowl_ontology_remove_axiom(CowlOntology *onto, CowlAnyAxiom *axiom);

/**
 * Gets the number of axioms in the ontology.
 *
 * @param onto The ontology.
 * @param imports If true, the query recurses over imported ontologies.
 * @return Number of axioms.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
ulib_uint cowl_ontology_axiom_count(CowlOntology *onto, bool imports);

/**
 * Gets the number of imported ontologies.
 *
 * @param onto The ontology.
 * @param imports If true, the query recurses over imported ontologies.
 * @return Number of imports.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
ulib_uint cowl_ontology_imports_count(CowlOntology *onto, bool imports);

/**
 * Gets the number of axioms of the specified type.
 *
 * @param onto The ontology.
 * @param type The axiom type.
 * @param imports If true, the query recurses over imported ontologies.
 * @return Number of axioms.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
ulib_uint cowl_ontology_axiom_count_for_type(CowlOntology *onto, CowlAxiomType type, bool imports);

/**
 * Gets the number of axioms referencing the specified primitive.
 *
 * @param onto The ontology.
 * @param primitive The primitive.
 * @param imports If true, the query recurses over imported ontologies.
 * @return Number of axioms.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
ulib_uint cowl_ontology_axiom_count_for_primitive(CowlOntology *onto, CowlAnyPrimitive *primitive,
                                                  bool imports);

/**
 * Gets the number of primitives.
 *
 * @param onto The ontology.
 * @param flags Primitive flags.
 * @param imports If true, the query recurses over imported ontologies.
 * @return Number of primitives.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
ulib_uint
cowl_ontology_primitives_count(CowlOntology *onto, CowlPrimitiveFlags flags, bool imports);

/**
 * Checks if the specified primitive is referenced by an axiom in the ontology.
 *
 * @param onto The ontology.
 * @param primitive The primitive.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the primitive is referenced by an axiom, false otherwise.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_has_primitive(CowlOntology *onto, CowlAnyPrimitive *primitive, bool imports);

/**
 * Checks whether the ontology contains the specified axiom.
 *
 * @param onto The ontology.
 * @param axiom The axiom.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the ontology contains the axiom, false otherwise.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_has_axiom(CowlOntology *onto, CowlAnyAxiom *axiom, bool imports);

/**
 * Iterates over the primitives referenced by the specified ontology.
 *
 * @param onto The ontology.
 * @param flags Primitive flags.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_primitives(CowlOntology *onto, CowlPrimitiveFlags flags,
                                      CowlIterator *iter, bool imports);

/**
 * Iterates over the imported ontologies.
 *
 * @param onto The ontology.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_imports(CowlOntology *onto, CowlIterator *iter, bool imports);

/**
 * Iterates over the import IRIs.
 *
 * @param onto The ontology.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_import_iris(CowlOntology *onto, CowlIterator *iter, bool imports);

/**
 * Iterates over the axioms in the ontology.
 *
 * @param onto The ontology.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_axioms(CowlOntology *onto, CowlIterator *iter, bool imports);

/**
 * Iterates over the axioms of a certain type.
 *
 * @param onto The ontology.
 * @param type The axiom type.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_axioms_of_type(CowlOntology *onto, CowlAxiomType type,
                                          CowlIterator *iter, bool imports);

/**
 * Iterates over the axioms referencing the specified primitive.
 *
 * @param onto The ontology.
 * @param primitive The primitive.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_axioms_for_primitive(CowlOntology *onto, CowlAnyPrimitive *primitive,
                                                CowlIterator *iter, bool imports);

/**
 * Iterates over the subclasses of the specified class.
 *
 * @param onto The ontology.
 * @param owl_class The class.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_sub_classes(CowlOntology *onto, CowlClass *owl_class, CowlIterator *iter,
                                       bool imports);

/**
 * Iterates over the superclasses of the specified class.
 *
 * @param onto The ontology.
 * @param owl_class The class.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_super_classes(CowlOntology *onto, CowlClass *owl_class,
                                         CowlIterator *iter, bool imports);

/**
 * Iterates over the equivalent classes of the specified class.
 *
 * @param onto The ontology.
 * @param owl_class The class.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_eq_classes(CowlOntology *onto, CowlClass *owl_class, CowlIterator *iter,
                                      bool imports);

/**
 * Iterates over the disjoint classes of the specified class.
 *
 * @param onto The ontology.
 * @param owl_class The class.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_disjoint_classes(CowlOntology *onto, CowlClass *owl_class,
                                            CowlIterator *iter, bool imports);

/**
 * Iterates over the types of the specified individual.
 *
 * @param onto The ontology.
 * @param ind The individual.
 * @param iter The iterator.
 * @param imports If true, the query recurses over imported ontologies.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlOntology
 */
COWL_PUBLIC
bool cowl_ontology_iterate_types(CowlOntology *onto, CowlAnyIndividual *ind, CowlIterator *iter,
                                 bool imports);

COWL_END_DECLS

#endif // COWL_ONTOLOGY_H
