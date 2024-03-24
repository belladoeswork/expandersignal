#include "lumumbash.h"

static int	ft_check_flag(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != '-')
		return (0);
	i++;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **args)
{
	int		i;
	int		newline;
	char	*arg;
	size_t	len;

	i = 0;
	newline = 1;
	while (args[i] && ft_check_flag(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		arg = args[i];
		len = strlen(arg);
		if ((arg[0] == '"' || arg[0] == '\'') && arg[0] == arg[len - 1])
		{
			arg[len - 1] = '\0';
			arg++;
		}
		ft_putstr_fd(arg, 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
