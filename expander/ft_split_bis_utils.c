/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bis_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:44:03 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 11:44:41 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	count_words(char *str, char c)
{
	int		n;
	int		flag;
	char	*tmp;

	n = 0;
	flag = 0;
	tmp = ft_strdup(str);
	if (!ft_dollar(str))
		return (ft_free_tmp(tmp, ft_strlen(str), 0), 1);
	while (*tmp)
	{
		if (*tmp == c)
			flag = 1;
		if ((*tmp == c && n == 1) || (flag == 1 && (ft_isspace(*tmp)
					|| ft_digit_or_q(tmp, c))))
		{
			n = 0;
			if (ft_isspace(*tmp))
				flag = 0;
		}
		n = 1;
		tmp++;
	}
	return (ft_free_tmp(tmp, ft_strlen(str), 1), n);
}

char	*ft_fill_the_word(char *str, int end, char *lst)
{
	int	i;
	int	tmp;

	tmp = end;
	while (end > 0)
	{
		str--;
		end--;
	}
	i = 0;
	while (i < tmp)
	{
		lst[i] = str[i];
		i++;
	}
	(void)str;
	lst[i] = 0;
	return (lst);
}

char	**ft_allocate_memory(char *str, char c)
{
	char	**lst;

	lst = ft_calloc((ft_countword(str, c) + 1), sizeof(char *));
	if (!str || !lst)
		return (NULL);
	return (lst);
}
