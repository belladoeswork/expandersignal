/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:26:12 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 23:27:42 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*ft_search(char **p1, char **p2, char *str)
{
	int	k;

	k = 0;
	while (p1[k] != NULL)
	{
		if (ft_strncmp(str, p1[k], ft_strlen(p1[k])) == 0
			&& (ft_strlen(p1[k]) == (ft_strlen(str))))
		{
			break ;
		}
		k++;
	}
	return (ft_strdup(p2[k]));
}

int	count_tildes(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '~' && (ft_isspace(*(str + 1)) || *(str + 1) == ':' || *(str
					+ 1) == '/' || *(str + 1) == '\0'))
			count++;
		str++;
	}
	return (count);
}

char	*expand_tilde(const char *str, char **p1, char **p2)
{
	char	*str_tilde;
	int		expanded_len;
	char	*str_expanded;
	int		l;
	int		k;

	str_tilde = ft_search(p1, p2, "HOME");
	expanded_len = (ft_strlen(str_tilde) * count_tildes(str)) + ft_strlen(str)
		- count_tildes(str) + 1;
	str_expanded = ft_calloc(expanded_len, sizeof(char));
	l = 0;
	while (*str != '\0')
	{
		if (*str == '~' && (ft_isspace(*(str + 1)) || *(str + 1) == ':' || *(str
					+ 1) == '/' || *(str + 1) == '\0'))
		{
			k = 0;
			while (str_tilde[k] != '\0')
				str_expanded[l++] = str_tilde[k++];
			str++;
		}
		str_expanded[l++] = *str++;
	}
	return (free(str_tilde), str_expanded);
}

char	*ft_expand_tilde(char *str, char **p1, char **p2)
{
	int	n;

	n = count_tildes(str);
	if (n == 0)
		return (ft_strdup(str));
	else
		return (expand_tilde(str, p1, p2));
}
