#include "lumumbash.h"

int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static int	ft_exec_pipeline(t_node *tree, t_minishell *minishell)
{
	int	status;
	int	pfds[2];
	int	pid_left;
	int	pid_right;

	pipe(pfds);
	pid_left = fork();
	if (pid_left == 0)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
		ft_exec_node(tree->left, true, minishell);
		exit(EXIT_FAILURE);
	}
	pid_right = fork();
	if (pid_right == 0)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
		ft_exec_node(tree->right, true, minishell);
		exit(EXIT_FAILURE);
	}
	close(pfds[0]);
	close(pfds[1]);
	waitpid(pid_left, &status, 0);
	waitpid(pid_right, &status, 0);
	return (ft_get_exit_status(status));
}

int	ft_exec_node(t_node *tree, bool piped, t_minishell *minishell)
{
	// int	status;
	if (!tree)
		return (1);
	if (tree->type == NODE_PIPE)
		return (ft_exec_pipeline(tree, minishell));
	else
		return (ft_exec_simple_cmd(tree, piped, minishell));
	return (GENERAL);
}
