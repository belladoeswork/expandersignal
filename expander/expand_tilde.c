/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:26:12 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 10:40:47 by aguede           ###   ########.fr       */
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

// char	*ft_expand_tilde(char *str, char **p1, char **p2)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	int		k;
// 	int		l;
// 	char	*str_tilde;
// 	char	*str_expanded;
// 	int		tmp;

// 	i = 0;
// 	j = 0;
// 	n = 0;
// 	k = 0;
// 	l = 0;
// 	while (str[i] != 0)
// 	{
// 		if (str[i] == '~' && (ft_isspace(str[i + 1]) || str[i + 1] == ':'
// 				|| str[i + 1] == '/' || str[i + 1] == 0))
// 			n++;
// 		i++;
// 	}
// 	if (n == 0)
// 	{
// 		return (str);
// 	}
// 	if (n > 0)
// 	{
// 		str_tilde = ft_search(p1, p2, "HOME");
// 		str_expanded = ft_calloc((ft_strlen(str_tilde) * n) + ft_strlen(str) - n
// 				+ 1, sizeof(char));
// 		tmp = (ft_strlen(str_tilde) * n) + ft_strlen(str) - n;
// 		while (l < tmp)
// 		{
// 			if (str[j] == '~' && (ft_isspace(str[j + 1]) || str[j + 1] == ':'
// 					|| str[j + 1] == '/' || str[j + 1] == 0))
// 			{
// 				k = 0;
// 				while (str_tilde[k] != 0)
// 				{
// 					str_expanded[l] = str_tilde[k];
// 					l++;
// 					k++;
// 				}
// 				j++;
// 			}
// 			str_expanded[l] = str[j];
// 			j++;
// 			l++;
// 		}
// 		free(str_tilde);
// 		return (str_expanded);
// 	}
// 	else
// 	{
// 		return (ft_strdup(str));
// 	}
// }

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
