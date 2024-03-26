/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:14 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 21:43:59 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"
#include "expander.h"
void	ft_free_double_d(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_free_new_str_str(char ***new_str_str)
{
	int		i;
	char	**current_array;

	if (new_str_str)
	{
		i = 0;
		while (new_str_str[i] != NULL)
		{
			if (new_str_str[i])
			{
				current_array = new_str_str[i];
				if (current_array)
				{
					ft_free_double_d(current_array);
					new_str_str[i] = NULL;
				}
			}
			i++;
		}
		free(new_str_str);
	}
}

void	ft_free_envi(char **part1, char **part2)
{
	ft_free_double_d(part1);
	ft_free_double_d(part2);
}
