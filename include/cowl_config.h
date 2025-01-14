/**
 * Declares API configuration functions.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_CONFIG_H
#define COWL_CONFIG_H

#include "cowl_error_handler.h"
#include "cowl_import_loader.h"
#include "cowl_reader.h"
#include "cowl_std.h"
#include "cowl_writer.h"

COWL_BEGIN_DECLS

/**
 * Initializes the library.
 *
 * @return Return code.
 *
 * @note It's mandatory to call this function before making any other function call.
 */
COWL_PUBLIC
cowl_ret cowl_init(void);

/**
 * Deinitializes the library.
 *
 * @note Calling this function releases any resource loaded when the library was initialized.
 *       You **must not** use objects retrieved before deinitializing the library, even
 *       if you later re-initialize it.
 */
COWL_PUBLIC
void cowl_deinit(void);

/**
 * Sets the global error handler.
 *
 * @param handler The error handler.
 *
 * @note This function must be called again if you reinitialize the library after deinitializing it.
 */
COWL_PUBLIC
void cowl_set_error_handler(CowlErrorHandler handler);

/**
 * Sets the global import loader.
 *
 * @param loader The import loader.
 *
 * @note This function must be called again if you reinitialize the library after deinitializing it.
 */
COWL_PUBLIC
void cowl_set_import_loader(CowlImportLoader loader);

/**
 * Sets the default reader.
 *
 * @param reader The reader.
 *
 * @note This function must be called again if you reinitialize library API after deinitializing it.
 */
COWL_PUBLIC
void cowl_set_reader(CowlReader reader);

/**
 * Sets the default writer.
 *
 * @param writer The writer.
 *
 * @note This function must be called again if you reinitialize the library after deinitializing it.
 */
COWL_PUBLIC
void cowl_set_writer(CowlWriter writer);

COWL_END_DECLS

#endif // COWL_CONFIG_H
