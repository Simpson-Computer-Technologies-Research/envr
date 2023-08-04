#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <string.h>
#include "dirs.h"

// Function prototypes
int none();
int new_env(int argc, char *argv[]);
int unknown();
int equals(const char *a, const char *b)
{
    return strcmp(a, b) == 0;
}
char **move_up(char *argv[], int argc)
{
    char *tmp[] = {};
    for (int i = 1; i < argc; i++)
        tmp[i - 1] = argv[i];
    return tmp;
}

/**
 * Main function
 */
int main(int argc, char *argv[])
{
    const char *command = argv[0];
    if (command == NULL)
        return none();
    else if (equals(command, "new"))
        return new_env(argc - 1, move_up(argv, argc));
    else
        return unknown();
}

/**
 * No command specified.
 */
int none()
{
    printf("No command specified. Example: envr new -cpp\n");
    return 0;
}

/**
 * New environment command.
 */
int new_env(int argc, char *argv[])
{
    // Iterate over the arguments
    for (int i = 0; i < argc; i++)
    {
        // If --cpp environment
        if (equals(argv[i], "-cpp"))
        {
            char *dir_name = make_env_dir();
            open_in_vscode(dir_name);
            free(dir_name);
            return 0;
        }
    }
    return 0;
}

/**
 * Unknown command.
 */
int unknown()
{
    printf("Unknown command. Use 'help' for more information.\n");
    return 0;
}

#endif // MAIN_C