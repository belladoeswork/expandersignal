#include "lumumbash.h"


int ft_cd(char **args) {
    if (args[0] == NULL) {
        char *home = getenv("HOME");
        if (home == NULL) {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }
        if (chdir(home) != 0) {
            perror("cd");
            return 1;
        }
    } else {
        if (chdir(args[0]) != 0) {
            perror("cd");
            return 1;
        }
    }
    return 0;
}
