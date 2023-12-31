#ifndef DIRS_H
#define DIRS_H

// Includes
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * Make a new directory on Linux
 *
 * @param const char *name
 * @return void
 */
#define _mkdir(name) mkdir(name, 0777)

/**
 * Make a new directory on Windows/Linux
 *
 * @param const char *name
 * @return void
 */
void make_dir(const char *name);

/**
 * Make a new random environment directory
 *
 * @return char * The directory name
 */
char *make_env_dir();

/**
 * Remove a directory
 *
 * @param const char *name
 * @return void
 */
void rm_dir(const char *name);

/**
 * Rename a directory
*/
void rename_dir(const char *old_name, const char *new_name);

/**
 * Open in vscode
*/
void open_in_vscode(const char *dir_name);

#endif // DIRS_H