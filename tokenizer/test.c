// #include "lumumbash.h"

// int	ft_handle_quotes(char *line, int *in_quotes, int *i)
// {
//     if (line[*i] == '"')
//     {
//         *in_quotes = (*in_quotes) ? 0 : line[*i];
//         (*i)++;
//         return (1);
//     }
//     return (0);
// }

// int	ft_handle_backslash(char *line, int *i)
// {
//     if (line[*i] == '\\' && line[*i + 1])
//     {
//         (*i)++;
//         return (1);
//     }
//     return (0);
// }

// int	ft_handle_word(char *line, int in_quotes, int *i)
// {
//     if (!in_quotes && (line[*i] == '<' || line[*i] == '>' || line[*i] == '|' || line[*i] == ' '))
//         return (0);
//     (*i)++;
//     return (1);
// }

// int	ft_append_word(char **line_ptr, t_token **token_list)
// {
//     int		i = 0;
//     int		in_quotes = 0;
//     char	*word = malloc(ft_strlen(*line_ptr) + 1);
//     int		j = 0;

//     if (!word)
//         return (0);
//     while ((*line_ptr)[i] && j < ft_strlen(*line_ptr))
//     {
//         if (ft_handle_quotes(*line_ptr, &in_quotes, &i) || ft_handle_backslash(*line_ptr, &i) || ft_handle_word(*line_ptr, in_quotes, &i))
//             word[j++] = (*line_ptr)[i - 1];
//         else
//             break ;
//     }
//     word[j] = '\0';
//     *line_ptr += i;
//     return (ft_token_list_add_back(token_list, ft_new_token(word, TOKEN_WORD)) ? 1 : (free(word), 0));
// }