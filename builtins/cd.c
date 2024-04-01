/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:04 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/30 00:25:05 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// int	ft_cd(char **args)
// {
// 	char	*home;

// 	if (args[0] == NULL)
// 	{
// 		home = getenv("HOME");
// 		if (home == NULL)
// 		{
// 			fprintf(stderr, "cd: HOME not set\n");
// 			return (1);
// 		}
// 		if (chdir(home) != 0)
// 		{
// 			perror("cd");
// 			return (1);
// 		}
// 	}
// 	else
// 	{
// 		if (chdir(args[0]) != 0)
// 		{
// 			perror("cd");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int	ft_cd(char **args)
{
	char	*path;

	if (args[0] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
	}
	else if (strcmp(args[0], "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			printf("cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
		path = args[0];
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
