#include "lumumbash.h"

void	ft_reset_stds(bool piped)
{
	if (piped)
		return ;
	dup2(STDIN_FILENO, 0);
	dup2(STDOUT_FILENO, 1);
}

int	ft_exec_builtin(char **args, t_minishell *minishell)
{
	printf("exec_builtin: Executing command - %s\n", args[0]);
	if (!ft_strcmp(args[0], "echo"))
		return (ft_echo(args + 1));
	// if (!ft_strcmp(args[0], "cd"))
	// 	return (ft_cd(args[1]));
	// if (!ft_strcmp(args[0], "env"))
	// 	return (ft_env(minishell));
	if (!ft_strcmp(args[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, &minishell));
	if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, minishell));
	ft_exit(args, minishell);
	return (GENERAL);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
	{
		return (false);
		// printf("is_builtin: Checking command - %s\n", arg);
	}
	printf("is_builtin: Checking command - %s\n", arg);
	if (!strcmp(arg, "echo") || !strcmp(arg, "exit") || !strcmp(arg, "pwd")
		|| !strcmp(arg, "export") || !strcmp(arg, "unset") || !strcmp(arg,
			"env") || !strcmp(arg, "cd"))
	{
		printf("is_builtin: Detected as builtin command\n");
		return (true);
	}
	printf("is_builtin: Not a builtin command\n");
	return (false);
}



// int	ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell)
// {
// 	int		tmp_status;
// 	char	**split_args;
// 	char	*arg;
// 	int		i;

// 	if (node->args == NULL)
// 	{
// 		return (0);
// 	}
// 	// Split the command into separate words
// 	split_args = malloc(MAX_NUM_ARGS * sizeof(char *) + 1);
// 	arg = strtok(node->args, " ");
// 	i = 0;
// 	while (arg != NULL)
// 	{
// 		split_args[i] = arg;
// 		i++;
// 		arg = strtok(NULL, " ");
// 	}
// 	split_args[i] = NULL;
// 	if (ft_is_builtin(split_args[0]))
// 	{
// 		printf("exec_simple_cmd: Detected builtin command\n");
// 		tmp_status = ft_check_redir(node);
// 		if (tmp_status != SUCCESS)
// 		{
// 			ft_reset_stds(piped);
// 			printf("exec_simple_cmd: Redirection check failed\n");
// 			return (GENERAL);
// 		}
// 		tmp_status = ft_exec_builtin(split_args, minishell);
// 		free(split_args);
// 		return (ft_reset_stds(piped), tmp_status);
// 	}
// 	else
// 	{
// 		printf("exec_simple_cmd: Not a builtin command\n");
// 		free(split_args);
// 		// return (ft_exec_child(node));
// 		tmp_status = ft_exec_child(split_args); 
//         // ft_free_split_args(split_args);
//         return tmp_status;
// 	}
// }



// int ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell) {
//     int tmp_status;
//     char **split_args;
//     char *arg;
//     int i;

//     if (node->args == NULL) {
//         return 0;
//     }

//     // Allocate memory for the array of strings
//     split_args = malloc((MAX_NUM_ARGS + 1) * sizeof(char *));
//     if (split_args == NULL) {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }

//     // Tokenize the command into separate words
//     i = 0;
//     arg = strtok(node->args, " ");
//     while (arg != NULL && i < MAX_NUM_ARGS) {
//         split_args[i] = strdup(arg); // Duplicate the token
//         if (split_args[i] == NULL) {
//             perror("strdup");
//             exit(EXIT_FAILURE);
//         }
//         i++;
//         arg = strtok(NULL, " ");
//     }
//     split_args[i] = NULL; // Terminate the array with a NULL pointer

//     if (ft_is_builtin(split_args[0])) {
//         printf("exec_simple_cmd: Detected builtin command\n");
//         tmp_status = ft_check_redir(node);
//         if (tmp_status != SUCCESS) {
//             ft_reset_stds(piped);
//             printf("exec_simple_cmd: Redirection check failed\n");
//             return GENERAL;
//         }
//         tmp_status = ft_exec_builtin(split_args, minishell);
//         ft_free_split_args(split_args); // Free memory
//         return ft_reset_stds(piped), tmp_status;
//     } else {
//         printf("exec_simple_cmd: Not a builtin command\n");
//         tmp_status = ft_exec_child(split_args); // Pass the array of strings to ft_exec_child
//         ft_free_split_args(split_args); // Free memory
//         return tmp_status;
//     }
// }



// OK

// int ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell) {
//     int tmp_status;
//     char **split_args;
//     char *arg;
//     int i;

//     if (node->args == NULL) {
//         return 0;
//     }

//     split_args = malloc((MAX_NUM_ARGS + 1) * sizeof(char *));
//     if (split_args == NULL) {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }

//     i = 0;
//     arg = strtok(node->args, " ");
//     while (arg != NULL && i < MAX_NUM_ARGS) {
//         split_args[i] = strdup(arg); 
//         if (split_args[i] == NULL) {
//             perror("strdup");
//             exit(EXIT_FAILURE);
//         }
//         i++;
//         arg = strtok(NULL, " ");
//     }
//     split_args[i] = NULL; 

//     if (ft_is_builtin(split_args[0])) {
//         printf("exec_simple_cmd: Detected builtin command\n");
//         tmp_status = ft_check_redir(node);
//         if (tmp_status != SUCCESS) {
//             ft_reset_stds(piped);
//             printf("exec_simple_cmd: Redirection check failed\n");
//             return GENERAL;
//         }
//         tmp_status = ft_exec_builtin(split_args, minishell);
//         ft_free_split_args(split_args);
//         return ft_reset_stds(piped), tmp_status;
//     } else {
//         printf("exec_simple_cmd: Not a builtin command\n");
//         tmp_status = ft_exec_child(split_args); 
//         ft_free_split_args(split_args);
//         return tmp_status;
//     }
// }




// int	ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell)
// {
// 	int		tmp_status;
// 	char	**split_args;
// 	char	*arg;
// 	int		i;

// 	if (node->args == NULL)
// 	{
// 		return (0);
// 	}
// 	// Split the command into separate words
// 	split_args = malloc(MAX_NUM_ARGS * sizeof(char *) + 1);
// 	arg = strtok(node->args, " ");
// 	i = 0;
// 	while (arg != NULL)
// 	{
// 		split_args[i] = arg;
// 		i++;
// 		arg = strtok(NULL, " ");
// 	}
// 	split_args[i] = NULL;
// 	if (ft_is_builtin(split_args[0]))
// 	{
// 		printf("exec_simple_cmd: Detected builtin command\n");
// 		tmp_status = ft_check_redir(node);
// 		if (tmp_status != SUCCESS)
// 		{
// 			ft_reset_stds(piped);
// 			printf("exec_simple_cmd: Redirection check failed\n");
// 			return (GENERAL);
// 		}
// 		tmp_status = ft_exec_builtin(split_args, minishell);
// 		free(split_args);
// 		return (ft_reset_stds(piped), tmp_status);
// 	}
// 	else
// 	{
// 		printf("exec_simple_cmd: Not a builtin command\n");
// 		free(split_args);
// 		return (ft_exec_child(node));
// 	}
// }

int	ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell)
{
	int		tmp_status;

	if (!node -> expanded_args)
	{
		tmp_status = ft_check_redir(node);
		return (ft_reset_stds(piped), (tmp_status && GENERAL));
	}
	else if (ft_is_builtin((node -> expanded_args)[0]))
	{
		tmp_status = ft_check_redirection(node);
		if (tmp_status != SUCCESS)
			return (ft_reset_stds(piped), GENERAL);
		tmp_status = ft_exec_builtin(node -> expanded_args);
		return (ft_reset_stds(piped), tmp_status);
	}
	else
		return (ft_exec_child(node));
}


// Function to free the memory allocated for the array of strings
// void ft_free_split_args(char **split_args) {
//     for (int i = 0; split_args[i] != NULL; i++) {
//         free(split_args[i]);
//     }
//     free(split_args);
// }
