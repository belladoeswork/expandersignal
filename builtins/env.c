/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:35 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/25 20:26:36 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

char	**ft_split_path(char *path)
{
	char	**result;
	int		i;
	int		j;
	int		count;

	count = 1;
	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
		{
			count++;
		}
	}
	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	j = 0;
	result[j] = path;
	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
		{
			path[i] = '\0';
			result[++j] = &path[i + 1];
		}
	}
	result[j + 1] = NULL;
	return (result);
}

char	*ft_find_command_path(const char *command)
{
	char	*path;
	char	**directories;
	int		i;
	char	*full_path;

	path = getenv("PATH");
	directories = ft_split_path(path);
	for (i = 0; directories[i] != NULL; i++)
	{
		full_path = malloc(ft_strlen(directories[i]) + ft_strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		ft_strcpy(full_path, directories[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(directories);
			return (full_path);
		}
		free(full_path);
	}
	free(directories);
	return (NULL);
}

int	ft_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
