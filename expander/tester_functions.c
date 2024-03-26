/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:25 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 16:28:26 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "lumumbash.h"

void	ft_print_double_d(char **str, char *from, int n)
{
	int	i;

	i = 0;
	if (n == -1)
	{
		while (str[i] != NULL)
		{
			printf("from %s : %s\n", from, str[i]);
			i++;
		}
		printf("from %s : %s\n", from, str[i]);
	}
	else
	{
		while (str[i] != NULL)
		{
			printf("nbr %d from %s : %s\n", n, from, str[i]);
			i++;
		}
	}
}

int	ft_count_number_of_words(char ***triple_d_str)
{
	int			i;
	int			j;
	static int	total;

	i = 0;
	total = 0;
	while (triple_d_str[i] != NULL)
	{
		j = 0;
		while (triple_d_str[i][j] != NULL)
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}

// char	*ft_strcat(char *dest, char *src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (dest[i] != '\0')
// 		i++;
// 	j = 0;
// 	while (src[j] != '\0')
// 	{
// 		dest[i + j] = src[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

void	ft_free_everything(t_lists_env envi,char **div_by_quote,char **clean )//, char *expanded_tilde)
{
	//free(expanded_tilde);
	ft_free_double_d(div_by_quote);
	ft_free_double_d(clean);
	ft_free_double_d(envi.p1);
	ft_free_double_d(envi.p2);
}