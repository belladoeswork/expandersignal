/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:28 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 21:07:56 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_skip_quotes(char *str, size_t *i)
{
	char	quote_type;

	quote_type = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote_type)
	{
		if (str[*i] == '\\' && str[*i + 1] == quote_type)
			(*i)++;
		(*i)++;
	}
	if (str[*i] == quote_type)
	{
		(*i)++;
		return (1);
	}
	else
	{
		ft_quote_error(quote_type);
		return (0);
	}
}

void	ft_quote_error(char c)
{
	ft_putstr_fd("lumumbash: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
