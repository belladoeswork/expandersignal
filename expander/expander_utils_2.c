/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:19:17 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 11:19:22 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	ft_free_tmp(char *str, int c, int check)
{
	int	i;

	i = 0;
	if (check == 1 && str)
	{
		while (i < c)
		{
			str--;
			i++;
		}
	}
	free(str);
}

int	ft_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_digit_or_q(char *str, char c)
{
	char	*tmp;

	tmp = str;
	if ((ft_isdigit(*tmp) || *tmp == '?') && *(tmp - 1) == c)
		return (1);
	else
		return (0);
}

int	ft_countword(char *str, char c)
{
	return (count_words(str, c) + 1);
}
