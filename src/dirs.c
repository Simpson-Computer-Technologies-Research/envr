#ifndef DIRS_H
#define DIRS_H

// Includes
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

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
void make_dir(const char *name)
{
#ifdef __linux__
    mkdir(name, 777);
#else
    _mkdir(name);
#endif
}

/**
 * Make a new random environment directory
 *
 * @return char * The directory name
 */
char *make_env_dir()
{
    long time = get_time();
    char* dir_name = malloc(100);
    sprintf(dir_name, "env_%ld", time);
    make_dir(dir_name);
    return dir_name;
}

/**
 * Remove a directory
 *
 * @param const char *name
 * @return void
 */
void rm_dir(const char *name)
{
    char* command = malloc(100);
    sprintf(command, "rm -rf %s", name);
    system(command);
    free(command);
}

/**
 * Rename a directory
*/
void rename_dir(const char *old_name, const char *new_name)
{
    char* command = malloc(100);
    sprintf(command, "mv %s %s", old_name, new_name);
    system(command);
    free(command);
}

/**
 * Open in vscode
*/
void open_in_vscode(const char *dir_name)
{
    char* command = malloc(100);
    sprintf(command, "code %s", dir_name);
    system(command);
    free(command);
}

#endif // DIRS_H