/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:14 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/27 00:23:58 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

int	ft_append_separator(t_token_type type, char **line_ptr,
		t_token **token_list)
{
	t_token	*token;
	int		length;

	if (type == TOKEN_HEREDOC)
	{
		length = 2;
	}
	else if (type == TOKEN_APPEND_OUTPUT_REDIRECTION)
	{
		length = 2;
	}
	else
	{
		length = 1;
	}
	token = ft_new_token(ft_substr(*line_ptr, 0, length), type);
	if (!token)
	{
		return (0);
	}
	*line_ptr += length;
	ft_token_list_add_back(token_list, token);
	return (1);
}

int	ft_append_word(char **line_ptr, t_token **token_list)
{
	int		i;
	char	*line;
	char	*word;
	int		j;

	i = 0;
	line = *line_ptr;
	if (!ft_allocate_word(&word, line))
		return (0);
	j = 0;
	while (line[i])
	{
		if (ft_check_special_char(line[i]))
			break ;
		ft_append_char_to_word(word, &j, line[i]);
		i++;
	}
	word[j] = '\0';
	if (!ft_add_word_to_token_list(token_list, word))
		return (0);
	*line_ptr += i;
	return (1);
}

t_token	*ft_tokenization_handler(char *line)
{
	t_token	*token_list;
	int		error;

	token_list = NULL;
	error = ft_process_token(&line, &token_list);
	if (error)
	{
		ft_clear_token_list(&token_list);
		return (NULL);
	}
	return (token_list);
}
