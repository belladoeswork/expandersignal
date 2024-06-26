/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:38 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 21:06:46 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

t_token	*ft_new_token(char *value, t_token_type type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
	{
		return (NULL);
	}
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

void	ft_free_token(t_token *token)
{
	if (token)
	{
		free(token->value);
		free(token);
	}
}

t_token	*ft_tokenize(char *input_line)
{
	t_token	*token_list;
	char	*line;

	line = ft_strdup(input_line);
	token_list = ft_tokenization_handler(line);
	free(line);
	return (token_list);
}
