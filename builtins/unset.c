#include "lumumbash.h"

// static void	ft_unset_helper(t_minishell *minishell, char *key)
// {
// 	t_env	*current;
// 	t_env	*prev;

// 	printf("inside ft_unset_helper\n");
// 	char **str;
// 	str = calloc(ft_strlen_double_pers(minishell), sizeof(char *));
// 	prev = NULL;
// 	current = minishell->envlst;
// 	while (current)
// 	{
// 		if (!ft_strcmp(key, minishell->environ))
// 		{
// 			if (prev)
// 				prev->next = current->next;
// 			else
// 				minishell->envlst = current->next;
// 			free(current);
// 			return ;
// 		}
// 		prev = current;
// 		current = current->next;
// 	}
// 	// int i;

// 	// i = 0;
// 	// char **str;
// 	// str = calloc(ft_strlen_double_pers(minishell), sizeof(char *));
// 	// while(minishell->environ[i])
// 	// {

// 	// }
// }

static void	ft_unset_helper(t_minishell *minishell, char *key)
{
	//t_env	*current;
	int	i;
	int j;
	char **str;

	printf("inside ft_unset_helper\n");
	printf("this is the key : %s\n", key);
	i = 0;
	j = 0;
	printf("minishell environ [%d] = %s\n", i, minishell->environ[i]);
	str = calloc(ft_strlen_double_pers(minishell->environ), sizeof(char *));
	printf("ft_strlen of minishell environ is : %d\n", ft_strlen_double_pers(minishell->environ));
	//current = minishell->envlst;
	while (minishell->environ[j] != NULL)
	{
		if (ft_strcmp(key, minishell->environ[j]) == 0)
		{
			printf("this is the key : %s and this is the minishell env var : %s\n", key, minishell->environ[j]);
			j++;
		}
		str[i] = ft_strdup(minishell->environ[j]);
		i++;
		j++;
	}
	str[i] = NULL;
	ft_print_double_d(str, "unset helper", -1);
	minishell->environ = str;
	// int i;

	// i = 0;
	// char **str;
	// str = calloc(ft_strlen_double_pers(minishell), sizeof(char *));
	// while(minishell->environ[i])
	// {

	// }
}

int	ft_unset(char **args, t_minishell **minishell)
{
	int		i;
	bool	err;

	i = 1;
	if (!args[1])
		return (0);
	err = false;
	while (args[i])
	{
		if (!ft_keycheck(args[i]))
		{
			ft_putstr_fd("lumumbash: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = true;
		}
		else
			ft_unset_helper(*minishell, ft_collector(ft_extract_key(args[i]),
					false));
		i++;
	}
	return (err);
}
