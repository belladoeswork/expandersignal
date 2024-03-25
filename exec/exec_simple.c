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
	if (!ft_strcmp(args[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, &minishell));
	if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, &minishell));
	ft_exit(args, minishell);
	return (GENERAL);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
	{
		return (false);
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


int ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell) {
    int tmp_status;

    if (node->split_args && node->split_args[0]) {
        printf("exec_simple_cmd: Command - %s\n", node->split_args[0]);

        if (ft_is_builtin(node->split_args[0])) {
            printf("exec_simple_cmd: Detected builtin command\n");
            tmp_status = ft_check_redir(node);
            if (tmp_status != SUCCESS) {
                ft_reset_stds(piped);
                printf("exec_simple_cmd: Redirection check failed\n");
                return GENERAL;
            }
            // tmp_status = ft_exec_builtin(node->split_args, minishell);
            // return ft_reset_stds(piped), tmp_status;
            if (strcmp(node->split_args[0], "env") == 0) {
                tmp_status = ft_env(minishell->environ);
            } else {
                tmp_status = ft_exec_builtin(node->split_args, minishell);
            }
            return ft_reset_stds(piped), tmp_status;
        } else {
            printf("exec_simple_cmd: Not a builtin command\n");
            tmp_status = ft_check_redir(node);
            if (tmp_status != SUCCESS) {
                ft_reset_stds(piped);
                printf("exec_simple_cmd: Redirection check failed\n");
                return GENERAL;
            }
            tmp_status = ft_exec_child(node->split_args);
            return tmp_status;
        }
    } else {
        printf("exec_simple_cmd: No command provided\n");
        return GENERAL;
    }
}
