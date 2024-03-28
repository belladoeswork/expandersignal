/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:35 by aguede            #+#    #+#             */
/*   Updated: 2024/03/28 16:58:33 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

static int	ft_export_error_msg(char *identifier)
{
	ft_putstr_fd("lumumbash: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

// int	ft_strlen_double_pers(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != NULL)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_create_new_key(char *key)
// {
// 	int		j;
// 	char	*new_key;

// 	j = 0;
// 	new_key = ft_calloc(ft_strlen(key) + 2, sizeof(char));
// 	if (!new_key)
// 		exit(EXIT_FAILURE);
// 	while (key[j] != 0)
// 	{
// 		new_key[j] = key[j];
// 		j++;
// 	}
// 	new_key[j] = '=';
// 	j++;
// 	new_key[j] = 0;
// 	return (new_key);
// }

// char	**duplicate_environ(char **minishellenviron, char *key_update,
// 		char *value)
// {
// 	char	**new_environ;
// 	int		k;

// 	k = 0;
// 	new_environ = ft_calloc(ft_strlen_double_pers(minishellenviron) + 2,
// 			sizeof(char *));
// 	while (minishellenviron[k] != NULL)
// 	{
// 		new_environ[k] = ft_strdup(minishellenviron[k]);
// 		k++;
// 	}
// 	new_environ[k] = ft_strjoin(key_update, value);
// 	k++;
// 	new_environ[k] = NULL;
// 	k = 0;
// 	return (new_environ);
// }

void	ft_modif_env_var(t_lists_env envi, char *key, char *value,
		t_minishell *minishell)
{
	int		i;
	// int		k;
	char	*key_update;
	char	**new_environ;

	i = 0;
	// k = 0;
	key_update = ft_create_new_key(key);
	while (envi.p1[i] != NULL)
	{
		if (ft_strncmp(key, envi.p1[i], ft_strlen(envi.p1[i])) == 0)
			break ;
		i++;
	}
	new_environ = duplicate_environ(minishell->environ, key_update, value);
	ft_free_double_d(minishell->environ);
	minishell->environ = new_environ;
	free(key_update);
}

// void	ft_free_lists_env(t_lists_env envi)
// {
// 	ft_free_double_d(envi.p1);
// 	ft_free_double_d(envi.p2);
// }

char	**populate_str(char **minishellenviron, char *key, char *update,
		t_lists_env list_env)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen_double_pers(minishellenviron) + 1,
			sizeof(char *));
	if (!str)
		return (NULL);
	while (minishellenviron[i] != NULL)
	{
		if (ft_strncmp(list_env.p1[i], key, ft_strlen(key)) == 0)
		{
			str[i] = ft_strdup(update);
			if (str[i + 1] != NULL)
				i++;
			else
				break ;
		}
		str[i] = ft_strdup(minishellenviron[i]);
		i++;
	}
	i++;
	ft_free_lists_env(list_env);
	return (str[i] = NULL, str);
}

// char	*ft_update(char *key_update, char *value)
// {
// 	char	*p1;
// 	char	*p2;
// 	char	*updated;

// 	p1 = ft_strdup(key_update);
// 	p2 = ft_strdup(value);
// 	updated = ft_strjoin(p1, p2);
// 	free(p1);
// 	free(p2);
// 	return (updated);
// }

// char	**ft_modify_env_var(char **minishellenviron, char *key, char *value)
// {
// 	char		*key_update;
// 	char		**str;
// 	char		*updated;
// 	t_lists_env	list_env;

// 	list_env = ft_split_lists_env(minishellenviron);
// 	key_update = ft_create_new_key(key);
// 	updated = ft_update(key_update, value);
// 	str = populate_str(minishellenviron, key, updated, list_env);
// 	free(key_update);
// 	free(updated);
// 	return (str);
// }

void	ft_add_env_var(char *key, char *value, int true_or_false,
		t_minishell *minishell)
{
	t_lists_env	list_env;
	char		**str;

	list_env = ft_split_lists_env(minishell->environ);
	if (true_or_false == 1)
	{
		str = ft_modify_env_var(minishell->environ, key, value);
		ft_free_double_d(minishell->environ);
		minishell->environ = str;
	}
	else if (true_or_false == 0)
		ft_modif_env_var(list_env, key, value, minishell);
	printf("Before freeing list_env: %p\n", minishell->environ);
	ft_free_lists_env(list_env);
	printf("After freeing list_env: %p\n", minishell->environ);

}

// int	ft_key_check(char *key, t_minishell *minishell)
// {
// 	int			i;
// 	t_lists_env	envi;

// 	envi = ft_split_lists_env(minishell->environ);
// 	i = 0;
// 	while (envi.p1[i] != NULL)
// 	{
// 		if (ft_strcmp(key, envi.p1[i]) == 0)
// 		{
// 			ft_free_double_d(envi.p1);
// 			ft_free_double_d(envi.p2);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	ft_free_double_d(envi.p1);
// 	ft_free_double_d(envi.p2);
// 	return (0);
// }

int	ft_export(char **argv, t_minishell **minishell)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (1);
	while (argv[i])
	{
		if (ft_keycheck(argv[i]) == 0)
			exit_s = ft_export_error_msg(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (!ft_key_check(key, *minishell))
				ft_add_env_var(key, ft_extract_value(argv[i]), 0, *minishell);
			else
				ft_add_env_var(key, ft_extract_value(argv[i]), 1, *minishell);
		}
		i++;
	}
	return (exit_s);
}
