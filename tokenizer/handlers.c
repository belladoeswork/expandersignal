/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:14 by tbella-n          #+#    #+#             */
/*   Updated: 2024/04/01 18:31:20 by tasha            ###   ########.fr       */
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

int	ft_handle_heredoc(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, "<<", 2))
	{
		return (ft_append_separator(TOKEN_HEREDOC, line_ptr, token_list) && 1);
	}
	return (0);
}

// int	ft_handle_append_output_redirection(char **line_ptr, t_token **token_list)
// {
// 	if (!ft_strncmp(*line_ptr, ">>", 2))
// 	{
// 		return (ft_append_separator(TOKEN_APPEND_OUTPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	return (0);
// }

int	ft_handle_append_output_redirection(char **line_ptr, t_token **token_list)
{
    if (!ft_strncmp(*line_ptr, ">>", 2))
    {
        while (!ft_strncmp(*line_ptr, ">", 1) || !ft_strncmp(*line_ptr, ">>", 2))
        {
            if (!ft_strncmp(*line_ptr, ">>", 2))
                (*line_ptr) += 2;
            else
                (*line_ptr)++;
        }
        if (*((*line_ptr) - 1) == '>')
            (*line_ptr) -= 2;
        else
            (*line_ptr)--;
        return (ft_append_separator(TOKEN_APPEND_OUTPUT_REDIRECTION, line_ptr,
                token_list) && 1);
    }
    return (0);
}


// int	ft_handle_input_redirection(char **line_ptr, t_token **token_list)
// {
// 	if (!ft_strncmp(*line_ptr, "<", 1))
// 	{
// 		return (ft_append_separator(TOKEN_INPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	return (0);
// }

int	ft_handle_input_redirection(char **line_ptr, t_token **token_list)
{
    if (!ft_strncmp(*line_ptr, "<", 1))
    {
        while (!ft_strncmp(*line_ptr, "<", 1))
        
            (*line_ptr)++;
        

        return (ft_append_separator(TOKEN_INPUT_REDIRECTION, line_ptr,
                token_list) && 1);
    }
    return (0);
}

// int	ft_handle_output_redirection(char **line_ptr, t_token **token_list)
// {
// 	if (!ft_strncmp(*line_ptr, ">", 1))
// 	{
// 		return (ft_append_separator(TOKEN_OUTPUT_REDIRECTION, line_ptr,
// 				token_list) && 1);
// 	}
// 	return (0);
// }

int	ft_handle_output_redirection(char **line_ptr, t_token **token_list)
{
    if (!ft_strncmp(*line_ptr, ">", 1))
    {
        while (!ft_strncmp(*line_ptr, ">", 1) || !ft_strncmp(*line_ptr, ">>", 2))
        {
            if (!ft_strncmp(*line_ptr, ">>", 2))
                (*line_ptr) += 2;
            else
                (*line_ptr)++;
        }
        if (*((*line_ptr) - 1) == '>')
            (*line_ptr) -= 2;
        else
            (*line_ptr)--;

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
	// *line_ptr += length;
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

int	ft_append_word(char **line_ptr, t_token **token_list)
{
    int		i;
    char	*line;
    int		in_quotes;
    char	*word;
    int		j;

    i = 0;
    line = *line_ptr;
    in_quotes = 0;
    word = malloc(ft_strlen(line) + 1);
    if (!word)
        return (0);
    j = 0;
    while (line[i])
    {
        if (line[i] == '\\' && line[i + 1])
            word[j++] = line[++i];
        else if (line[i] == '"')
        {
            if (in_quotes)
            {
                if (in_quotes == line[i])
                    in_quotes = 0;
            }
            else
                in_quotes = line[i];
            word[j++] = line[i];
        }
        else if (!in_quotes && (line[i] == '<' || line[i] == '|'
                || line[i] == ' '))
            break ;
        else if (!in_quotes && line[i] == '>' && line[i + 1] != '>')
            break ;
        else
            word[j++] = line[i];
        i++;
    }
    word[j] = '\0';
    if (!ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)))
    {
        free(word);
        return (0);
    }
    *line_ptr += i;
    return (1);
}

t_token	*ft_tokenization_handler(char *line)
{
	int		error;
	t_token	*token_list;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if (error)
		{
			ft_clear_token_list(&token_list);
			return (NULL);
		}
		if (ft_isspace(*line))
			ft_skip_spaces(&line);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1))
			error = !ft_handle_separator(&line, &token_list);
		else
			error = !ft_append_word(&line, &token_list);
	}
	if (error)
	{
		ft_clear_token_list(&token_list);
		return (NULL);
	}
	return (token_list);
}

// void handle_error(int *error, t_token **token_list)
// {
//     if (*error)
//     {
//         ft_clear_token_list(token_list);
//         *error = 0;
//     }
// }

// void process_line(char **line, int *error, t_token **token_list)
// {
//     if (ft_isspace(**line))
//         ft_skip_spaces(line);
//     else if (!ft_strncmp(*line, "<", 1) || !ft_strncmp(*line, ">", 1)
//         || !ft_strncmp(*line, "|", 1))
//         *error = !ft_handle_separator(line, token_list);
//     else
//         *error = !ft_append_word(line, token_list);
// }

// t_token	*ft_tokenization_handler(char *line)
// {
//     int		error;
//     t_token	*token_list;

//     error = 0;
//     token_list = NULL;
//     while (*line)
//     {
//         handle_error(&error, &token_list);
//         if (error)
//             return (NULL);
//         process_line(&line, &error, &token_list);
//     }
//     handle_error(&error, &token_list);
//     if (error)
//         return (NULL);
//     return (token_list);
// }