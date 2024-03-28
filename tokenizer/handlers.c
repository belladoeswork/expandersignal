/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:14 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 21:17:40 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// int	ft_append_separator(t_token_type type, char **line_ptr,
// 		t_token **token_list)
// {
// 	t_token	*token;
// 	int		length;

// 	if (type == TOKEN_HEREDOC)
// 	{
// 		length = 2;
// 	}
// 	else if (type == TOKEN_APPEND_OUTPUT_REDIRECTION)
// 	{
// 		length = 2;
// 	}
// 	else
// 	{
// 		length = 1;
// 	}
// 	token = ft_new_token(ft_substr(*line_ptr, 0, length), type);
// 	if (!token)
// 	{
// 		return (0);
// 	}
// 	*line_ptr += length;
// 	ft_token_list_add_back(token_list, token);
// 	return (1);
// }

// int	ft_append_word(char **line_ptr, t_token **token_list)
// {
// 	int		i;
// 	char	*line;
// 	char	*word;
// 	int		j;

// 	i = 0;
// 	line = *line_ptr;
// 	if (!ft_allocate_word(&word, line))
// 		return (0);
// 	j = 0;
// 	while (line[i])
// 	{
// 		if (ft_check_special_char(line[i]))
// 			break ;
// 		ft_append_char_to_word(word, &j, line[i]);
// 		i++;
// 	}
// 	word[j] = '\0';
// 	if (!ft_add_word_to_token_list(token_list, word))
// 		return (0);
// 	*line_ptr += i;
// 	return (1);
// }

// t_token	*ft_tokenization_handler(char *line)
// {
// 	t_token	*token_list;
// 	int		error;

// 	token_list = NULL;
// 	error = ft_process_token(&line, &token_list);
// 	if (error)
// 	{
// 		ft_clear_token_list(&token_list);
// 		return (NULL);
// 	}
// 	return (token_list);
// }

/////
int	ft_append_separator(t_token_type type, char **line_ptr,
		t_token **token_list)
{
	t_token	*token;
	int		length;

	if (type == TOKEN_HEREDOC || type == TOKEN_APPEND_OUTPUT_REDIRECTION)
		length = 2;
	else
		length = 1;
	token = ft_new_token(ft_substr(*line_ptr, 0, length), type);
	if (!token)
		return (0);
	*line_ptr += length;
	return (ft_token_list_add_back(token_list, token), 1);
}

// int	ft_handle_separator(char **line_ptr, t_token **token_list)
// {
// 	int	length;

// 	length = 0;
// 	if (!ft_strncmp(*line_ptr, "<<", 2))
// 	{
// 		length = 2;
// 		return (ft_append_separator(TOKEN_HEREDOC, line_ptr, token_list) && 1);
// 	}
// 	else if (!ft_strncmp(*line_ptr, ">>", 2))
// 	{
// 		length = 2;
// 		return (ft_append_separator(TOKEN_APPEND_OUTPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	else if (!ft_strncmp(*line_ptr, "<", 1))
// 	{
// 		length = 1;
// 		return (ft_append_separator(TOKEN_INPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	else if (!ft_strncmp(*line_ptr, ">", 1))
// 	{
// 		length = 1;
// 		return (ft_append_separator(TOKEN_OUTPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	else
// 	{
// 		length = 1;
// 		return (ft_append_separator(TOKEN_PIPE, line_ptr, token_list) && 1);
// 	}
// 	*line_ptr += length;
// }

// int	ft_append_word(char **line_ptr, t_token **token_list)
// {
// 	int		i;
// 	char	*line;
// 	int		in_quotes;
// 	char	*word;
// 	int		j;

// 	i = 0;
// 	line = *line_ptr;
// 	in_quotes = 0;
// 	word = malloc(ft_strlen(line) + 1);
// 	if (!word)
// 		return (0);
// 	j = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\\' && line[i + 1])
// 			word[j++] = line[++i];
// 		else if (line[i] == '"' || line[i] == '\'')
// 		{
// 			if (in_quotes)
// 			{
// 				if (in_quotes == line[i])
// 					in_quotes = 0;
// 			}
// 			else
// 				in_quotes = line[i];
// 			word[j++] = line[i];
// 		}
// 		else if (!in_quotes && (line[i] == '<' || line[i] == '>'
// 				|| line[i] == '|' || line[i] == ';' || line[i] == ' '))
// 			break ;
// 		else
// 			word[j++] = line[i];
// 		i++;
// 	}
// 	word[j] = '\0';
// 	if (!ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)))
// 	{
// 		free(word);
// 		return (0);
// 	}
// 	*line_ptr += i;
// 	return (1);
// }

// t_token	*ft_tokenization_handler(char *line)
// {
// 	int		error;
// 	t_token	*token_list;

// 	error = 0;
// 	token_list = NULL;
// 	while (*line)
// 	{
// 		if (error)
// 		{
// 			ft_clear_token_list(&token_list);
// 			return (NULL);
// 		}
// 		if (ft_isspace(*line))
// 			ft_skip_spaces(&line);
// 		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
// 			|| !ft_strncmp(line, "|", 1))
// 			error = !ft_handle_separator(&line, &token_list);
// 		else
// 			error = !ft_append_word(&line, &token_list);
// 	}
// 	if (error)
// 	{
// 		ft_clear_token_list(&token_list);
// 		return (NULL);
// 	}
// 	return (token_list);
// }

/// START HERE

int	ft_handle_heredoc(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, "<<", 2))
	{
		return (ft_append_separator(TOKEN_HEREDOC, line_ptr, token_list) && 1);
	}
	return (0);
}

int	ft_handle_append_output_redirection(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, ">>", 2))
	{
		return (ft_append_separator(TOKEN_APPEND_OUTPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	return (0);
}

int	ft_handle_input_redirection(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, "<", 1))
	{
		return (ft_append_separator(TOKEN_INPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	return (0);
}

int	ft_handle_output_redirection(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, ">", 1))
	{
		return (ft_append_separator(TOKEN_OUTPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	return (0);
}

int	ft_handle_pipe(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, "|", 1))
	{
		return (ft_append_separator(TOKEN_PIPE, line_ptr, token_list) && 1);
	}
	return (0);
}

int	ft_handle_separator(char **line_ptr, t_token **token_list)
{
	int	length;

	length = 0;
	if (ft_handle_heredoc(line_ptr, token_list))
		length = 2;
	else if (ft_handle_append_output_redirection(line_ptr, token_list))
		length = 2;
	else if (ft_handle_input_redirection(line_ptr, token_list))
		length = 1;
	else if (ft_handle_output_redirection(line_ptr, token_list))
		length = 1;
	else if (ft_handle_pipe(line_ptr, token_list))
		length = 1;
	*line_ptr += length;
	return (length);
}

// int	ft_append_word(char **line_ptr, t_token **token_list)
// {
// 	int		i;
// 	char	*line;
// 	int		in_quotes;
// 	char	*word;
// 	int		j;

// 	i = 0;
// 	line = *line_ptr;
// 	in_quotes = 0;
// 	word = malloc(ft_strlen(line) + 1);
// 	if (!word)
// 		return (0);
// 	j = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\\' && line[i + 1])
// 			word[j++] = line[++i];
// 		else if (line[i] == '"')
// 		{
// 			if (in_quotes)
// 			{
// 				if (in_quotes == line[i])
// 					in_quotes = 0;
// 			}
// 			else
// 				in_quotes = line[i];
// 			word[j++] = line[i];
// 		}
// 		else if (!in_quotes && (line[i] == '<' || line[i] == '>'
// 				|| line[i] == '|' || line[i] == ' '))
// 			break ;
// 		else
// 			word[j++] = line[i];
// 		i++;
// 	}
// 	word[j] = '\0';
// 	if (!ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)))
// 	{
// 		free(word);
// 		return (0);
// 	}
// 	*line_ptr += i;
// 	return (1);
// }

static int	ft_handle_quotes(char *line, int *in_quotes, int *i)
{
	if (line[*i] == '"')
	{
		if (*in_quotes)
			*in_quotes = 0;
		else
			*in_quotes = line[*i];
		(*i)++;
		return (1);
	}
	return (0);
}

static int	ft_handle_backslash(char *line, int *i)
{
	if (line[*i] == '\\' && line[*i + 1])
	{
		(*i)++;
		return (1);
	}
	return (0);
}

static int	ft_handle_word(char *line, int in_quotes, int *i)
{
	if (!in_quotes && (line[*i] == '<' || line[*i] == '>' || line[*i] == '|'
			|| line[*i] == ' '))
		return (0);
	(*i)++;
	return (1);
}

static char	*ft_extract_word(char **line_ptr)
{
	int		i;
	int		in_quotes;
	char	*word;
	int		j;

	i = 0;
	word = malloc(ft_strlen(*line_ptr) + 1);
	j = 0;
	in_quotes = 0;
	if (!word)
		return (NULL);
	while ((*line_ptr)[i]) 
	{
        if ((int)(j + 1) >= (int)ft_strlen(*line_ptr))
            break;
		if (ft_handle_quotes(*line_ptr, &in_quotes, &i)
			|| ft_handle_backslash(*line_ptr, &i) || ft_handle_word(*line_ptr,
				in_quotes, &i))
			word[j++] = (*line_ptr)[i - 1];
		else
			break ;
	}
	word[j] = '\0';
	*line_ptr += i;
	return (word);
}

static int	ft_append_token(t_token **token_list, char *word)
{
	int	result;

	result = ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD));
	if (result == 0)
		free(word);
	return (result);
}

int	ft_append_word(char **line_ptr, t_token **token_list)
{
	char	*word;
	int		result;

	word = ft_extract_word(line_ptr);
	if (!word)
		return (0);
	result = ft_append_token(token_list, word);
	return (result);
}

/////////

// t_token	*ft_tokenization_handler(char *line)
// {
// 	int		error;
// 	t_token	*token_list;

// 	error = 0;
// 	token_list = NULL;
// 	while (*line)
// 	{
// 		if (error)
// 		{
// 			ft_clear_token_list(&token_list);
// 			return (NULL);
// 		}
// 		if (ft_isspace(*line))
// 			ft_skip_spaces(&line);
// 		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
// 			|| !ft_strncmp(line, "|", 1))
// 			error = !ft_handle_separator(&line, &token_list);
// 		else
// 			error = !ft_append_word(&line, &token_list);
// 	}
// 	if (error)
// 	{
// 		ft_clear_token_list(&token_list);
// 		return (NULL);
// 	}
// 	return (token_list);
// }

int	ft_handle_tk_error(int *error, t_token **token_list)
{
	if (*error)
	{
		ft_clear_token_list(token_list);
		return (1);
	}
	return (0);
}

int	ft_handle_token(char **line, t_token **token_list)
{
	if (ft_isspace(**line))
	{
		ft_skip_spaces(line);
		return (0);
	}
	else if (!ft_strncmp(*line, "<", 1) || !ft_strncmp(*line, ">", 1)
		|| !ft_strncmp(*line, "|", 1))
	{
		if (!ft_handle_separator(line, token_list))
			return (1);
	}
	else
	{
		if (!ft_append_word(line, token_list))
			return (1);
	}
	return (0);
}

t_token	*ft_tokenization_handler(char *line)
{
	int		error;
	t_token	*token_list;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if (ft_handle_tk_error(&error, &token_list))
			return (NULL);
		error = ft_handle_token(&line, &token_list);
	}
	if (ft_handle_tk_error(&error, &token_list))
		return (NULL);
	return (token_list);
}
