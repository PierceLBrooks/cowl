/**
 * Declares CowlManager and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_MANAGER_H
#define COWL_MANAGER_H

#include "cowl_error_handler.h"
#include "cowl_import_loader.h"
#include "cowl_istream_config.h"
#include "cowl_object.h"
#include "cowl_reader.h"
#include "cowl_writer.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlOntology);
cowl_struct_decl(CowlOntologyId);
cowl_struct_decl(CowlOStream);
cowl_struct_decl(CowlManager);
/// @endcond

/**
 * Manages ontology documents.
 *
 * CowlManager supports multiple input sources, such as files, memory buffers, or
 * buffered streams. It also supports multiple readers, either built-in or provided by the user.
 *
 * @see CowlReader
 *
 * @struct CowlManager
 * @extends CowlObject
 */

/**
 * Returns a retained manager that uses the default reader and writer.
 *
 * @return Retained manager, or NULL on error.
 *
 * @note You can specify the default reader and writer
 *       via `cowl_set_reader()` and `cowl_set_writer()`.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlManager *cowl_manager(void);

/**
 * Sets the reader.
 *
 * @param manager The manager.
 * @param reader The reader.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
void cowl_manager_set_reader(CowlManager *manager, CowlReader reader);

/**
 * Sets the writer.
 *
 * @param manager The manager.
 * @param writer The writer.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
void cowl_manager_set_writer(CowlManager *manager, CowlWriter writer);

/**
 * Sets the import loader.
 *
 * @param manager The manager.
 * @param loader The import loader.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
void cowl_manager_set_import_loader(CowlManager *manager, CowlImportLoader loader);

/**
 * Sets the error handler.
 *
 * @param manager The manager.
 * @param handler The error handler.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
void cowl_manager_set_error_handler(CowlManager *manager, CowlErrorHandler handler);

/**
 * Gets the ontology with the specified identifier.
 * If no existing ontology has the specified identifier, a new ontology is returned.
 *
 * @param manager The manager.
 * @param id The ontology identifier.
 * @return Ontology with the specified identifier.
 *
 * @note The returned ontology is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOntology *cowl_manager_get_ontology(CowlManager *manager, CowlOntologyId const *id);

/**
 * Reads an ontology from the file at the specified path.
 *
 * @param manager The manager.
 * @param path The file path.
 * @return The read ontology, or NULL on error.
 *
 * @note The returned ontology is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOntology *cowl_manager_read_path(CowlManager *manager, UString path);

/**
 * Reads an ontology from the specified file.
 *
 * @param manager The manager.
 * @param file The input file.
 * @return The read ontology, or NULL on error.
 *
 * @note The returned ontology is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOntology *cowl_manager_read_file(CowlManager *manager, FILE *file);

/**
 * Reads an ontology from the specified string.
 *
 * @param manager The manager.
 * @param string The input string.
 * @return The read ontology, or NULL on error.
 *
 * @note The returned ontology is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOntology *cowl_manager_read_string(CowlManager *manager, UString const *string);

/**
 * Reads an ontology from the specified input stream.
 *
 * @param manager The manager.
 * @param stream The input stream.
 * @return The read ontology, or NULL on error.
 *
 * @note The stream is not released by the manager, you must do it yourself.
 * @note The returned ontology is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOntology *cowl_manager_read_stream(CowlManager *manager, UIStream *stream);

/**
 * Streams through the ontology at the specified path.
 *
 * @param manager The manager.
 * @param config Ontology stream configuration.
 * @param path The file path.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_stream_path(CowlManager *manager, CowlIStreamConfig config, UString path);

/**
 * Streams through the ontology read from the specified file.
 *
 * @param manager The manager.
 * @param config Ontology stream configuration.
 * @param file The file.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_stream_file(CowlManager *manager, CowlIStreamConfig config, FILE *file);

/**
 * Streams through the ontology read from the specified string.
 *
 * @param manager The manager.
 * @param config Ontology stream configuration.
 * @param string The string.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret
cowl_manager_stream_string(CowlManager *manager, CowlIStreamConfig config, UString const *string);

/**
 * Streams through the ontology read from the specified input stream.
 *
 * @param manager The manager.
 * @param config Ontology stream configuration.
 * @param stream The input stream.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret
cowl_manager_stream_stream(CowlManager *manager, CowlIStreamConfig config, UIStream *stream);

/**
 * Streams through the specified ontology.
 *
 * @param manager The manager.
 * @param config Ontology stream configuration.
 * @param ontology The ontology.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_stream_ontology(CowlManager *manager, CowlIStreamConfig config,
                                      CowlOntology *ontology);

/**
 * Writes the ontology to the file at the specified path.
 *
 * @param manager The manager.
 * @param ontology The ontology.
 * @param path The file path.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_write_path(CowlManager *manager, CowlOntology *ontology, UString path);

/**
 * Writes the ontology to the specified file.
 *
 * @param manager The manager.
 * @param ontology The ontology.
 * @param file The output file.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_write_file(CowlManager *manager, CowlOntology *ontology, FILE *file);

/**
 * Writes the ontology to the specified string buffer.
 *
 * @param manager The manager.
 * @param ontology The ontology.
 * @param buf The string buffer.
 * @return Return code.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_write_strbuf(CowlManager *manager, CowlOntology *ontology, UStrBuf *buf);

/**
 * Writes the ontology to the specified output stream.
 *
 * @param manager The manager.
 * @param ontology The ontology.
 * @param stream The output stream.
 * @return Return code.
 *
 * @note The stream is not released by the manager, you must do it yourself.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
cowl_ret cowl_manager_write_stream(CowlManager *manager, CowlOntology *ontology, UOStream *stream);

/**
 * Returns an ontology output stream.
 *
 * @param manager The manager.
 * @param stream The output stream.
 * @return Ontology output stream.
 *
 * @note You are responsible for releasing the returned object.
 *
 * @public @memberof CowlManager
 */
COWL_PUBLIC
CowlOStream *cowl_manager_open_ostream(CowlManager *manager, UOStream *stream);

COWL_END_DECLS

#endif // COWL_MANAGER_H
