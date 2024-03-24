#include "lumumbash.h"

// before expander below
// int	ft_exec_child(t_node *node)
// {
// 	int		tmp_status;
// 	// int	fork_pid;
// 	pid_t pid;

// 	// is the sginit child true
// 	// then 
// 	// fork_pid = fork()
// 	// if(!fork_pid) {
// 	// 	tmp_status = ft_check_redir(node);
// 	// 	if(tmp_status != ENO_SUCCESS){
// 	// 		(ft_clean_ms(), exit(ENO_GENERAL));
// 	// 	}
// 	// 	if (execve(path_status.path, node -> expanded_args))
// 	// }

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		// Child process
// 		if (execvp(node->split_args[0], node->split_args) == -1)
// 		{
// 			perror("lsh");
// 		}
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid < 0)
// 	{
// 		// Error forking
// 		perror("lsh");
// 	}
// 	else
// 	{
// 		// Parent process
// 		do
// 		{
// 			waitpid(pid, &tmp_status, WUNTRACED);
// 		} while (!WIFEXITED(tmp_status) && !WIFSIGNALED(tmp_status));
// 	}
// 	return (1);
// }



char *ft_find_command_path(const char *command) {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    while (token != NULL) {
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);
        if (access(full_path, X_OK) == 0) {
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}


int ft_exec_child(t_node *node) {
    int tmp_status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *full_path = ft_find_command_path(node->split_args[0]);
        if (full_path == NULL) {
            fprintf(stderr, "Command '%s' not found\n", node->split_args[0]);
            exit(EXIT_FAILURE);
        }
        char *const args[] = {full_path, node->split_args[1], NULL}; 
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






// int ft_exec_child(char **args) {
	
int ft_exec_child(t_node *node, t_minishell *minishell) {
	
    int tmp_status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
		tmp_status = ft_check_redir(node);
		if (tmp_status != SUCCESS)
			(ft_clean_ms(), exit(GENERAL));
		path_status = ft_get_path((node -> expanded_args)[0]);
		if (path_status.err.no != SUCCESS)
		{
			tmp_status = ft_err_msg(path_status.err);
			(ft_clean_ms(), exit(tmp_status));
		}
		if (execve(path_status.path, node -> expanded_args,
				minishell->environ) == -1)
			(ft_clean_ms(), exit(1));
	}
	waitpid(fork_pid, &tmp_status, 0);
	// g_minishell.signint_child = false;
	return (ft_get_exit_status(tmp_status));














        char *full_path = ft_find_command_path(args[0]);
        if (full_path == NULL) {
            fprintf(stderr, "Command '%s' not found\n", args[0]);
            exit(EXIT_FAILURE);
        }
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



static int	ft_exec_child(t_node *node)
{
	t_path	path_status;
	int		fork_pid;

	// g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		// tmp_status = ft_check_redirection(node);
		if (tmp_status != ENO_SUCCESS)
			(ft_clean_ms(), exit(ENO_GENERAL));
		path_status = ft_get_path((node -> expanded_args)[0]);
		if (path_status.err.no != ENO_SUCCESS)
		{
			tmp_status = ft_err_msg(path_status.err);
			(ft_clean_ms(), exit(tmp_status));
		}
		if (execve(path_status.path, node -> expanded_args,
				g_minishell.environ) == -1)
			(ft_clean_ms(), exit(1));
	}
	waitpid(fork_pid, &tmp_status, 0);
	// g_minishell.signint_child = false;
	return (ft_get_exit_status(tmp_status));
}