#include "lumumbash.h"

char **ft_split_path(char *path) {
    int i, j, count;
    char **result;

    count = 1;
    for (i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':') {
            count++;
        }
    }
    result = malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    j = 0;
    result[j] = path;
    for (i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':') {
            path[i] = '\0';
            result[++j] = &path[i + 1];
        }
    }
    result[j + 1] = NULL;

    return result;
}


char *ft_find_command_path(const char *command) {
    char *path = getenv("PATH");
    char **directories = ft_split_path(path);
    int i;

    for (i = 0; directories[i] != NULL; i++) {
        char *full_path = malloc(strlen(directories[i]) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(full_path, directories[i]);
        strcat(full_path, "/");
        strcat(full_path, command);
        if (access(full_path, X_OK) == 0) {
            free(directories);
            return full_path;
        }
        free(full_path);
    }
    free(directories);
    return NULL;
}


int ft_env(char **environ) {
    int i = 0;

    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
    return 1;
}