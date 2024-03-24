#include "lumumbash.h"

int	ft_append_separator(t_token_type type, char **line_ptr,
		t_token **token_list)
{
	t_token	*token;
	int		length;

	length = (type == TOKEN_HEREDOC
			|| type == TOKEN_APPEND_OUTPUT_REDIRECTION) ? 2 : 1;
	token = ft_new_token(ft_substr(*line_ptr, 0, length), type);
	if (!token)
		return (0);
	*line_ptr += length;
	return (ft_token_list_add_back(token_list, token), 1);
}

int	ft_handle_separator(char **line_ptr, t_token **token_list)
{
	int	length;

	length = 0;
	if (!ft_strncmp(*line_ptr, "<<", 2))
	{
		length = 2;
		return (ft_append_separator(TOKEN_HEREDOC, line_ptr, token_list) && 1);
	}
	else if (!ft_strncmp(*line_ptr, ">>", 2))
	{
		length = 2;
		return (ft_append_separator(TOKEN_APPEND_OUTPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	else if (!ft_strncmp(*line_ptr, "<", 1))
	{
		length = 1;
		return (ft_append_separator(TOKEN_INPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	else if (!ft_strncmp(*line_ptr, ">", 1))
	{
		length = 1;
		return (ft_append_separator(TOKEN_OUTPUT_REDIRECTION, line_ptr,
				token_list) && 1);
	}
	else
	{
		length = 1;
		return (ft_append_separator(TOKEN_PIPE, line_ptr, token_list) && 1);
	}
	*line_ptr += length;
}

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
	j = 0;
	while (line[i])
	{
		if (line[i] == '\\' && line[i + 1])
		{
			word[j++] = line[++i];
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			if (in_quotes)
			{
				if (in_quotes == line[i])
				{
					in_quotes = 0;
				}
			}
			else
			{
				in_quotes = line[i];
			}
			word[j++] = line[i];
		}
		else if (!in_quotes && (line[i] == '<' || line[i] == '>'
				|| line[i] == '|' || line[i] == ';'))
		{
			break ;
		}
		else
		{
			word[j++] = line[i];
		}
		i++;
	}
	word[j] = '\0';
	if (!ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)))
		return (0);
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
		{
			ft_skip_spaces(&line);
		}
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1))
		{
			error = !ft_handle_separator(&line, &token_list);
		}
		else
		{
			error = !ft_append_word(&line, &token_list);
		}
	}
	if (error)
	{
		ft_clear_token_list(&token_list);
		return (NULL);
	}
	return (token_list);
}