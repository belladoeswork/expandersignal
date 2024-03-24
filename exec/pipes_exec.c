#include "lumumbash.h"

// before expander below
int	ft_exec_child(t_node *node)
{
	int		tmp_status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execvp(node->split_args[0], node->split_args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// Error forking
		perror("lsh");
	}
	else
	{
		// Parent process
		do
		{
			waitpid(pid, &tmp_status, WUNTRACED);
		} while (!WIFEXITED(tmp_status) && !WIFSIGNALED(tmp_status));
	}
	return (1);
}
