#include "lumumbash.h"

int ft_exec_child(char **split_args) {
    int tmp_status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *full_path = ft_find_command_path(split_args[0]);
        if (full_path == NULL) {
            fprintf(stderr, "Command '%s' not found\n", split_args[0]);
            exit(EXIT_FAILURE);
        }
        char *const args[] = {full_path, split_args[1], NULL};
        if (execve(full_path, args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        return -1; 
    } else {
        do {
            waitpid(pid, &tmp_status, WUNTRACED);
        } while (!WIFEXITED(tmp_status) && !WIFSIGNALED(tmp_status));
    }
    return 1; 
}
