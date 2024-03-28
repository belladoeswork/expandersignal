/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:12:03 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 16:19:18 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// int	ft_handle_separator(char **line_ptr, t_token **token_list)
// {
// 	return (ft_handle_heredoc(line_ptr, token_list)
// 		|| ft_handle_append_output_redirection(line_ptr, token_list)
// 		|| ft_handle_input_redirection(line_ptr, token_list)
// 		|| ft_handle_output_redirection(line_ptr, token_list)
// 		|| ft_handle_pipe(line_ptr, token_list));
// }

int	ft_handle_space_or_separator(char **line, t_token **token_list)
{
	if (ft_isspace(**line))
	{
		ft_skip_spaces(line);
		return (0);
	}
	else if (!ft_strncmp(*line, "<", 1) || !ft_strncmp(*line, ">", 1)
		|| !ft_strncmp(*line, "|", 1))
	{
		return (!ft_handle_separator(line, token_list));
	}
	return (0);
}

int	ft_process_token(char **line, t_token **token_list)
{
	int	error;

	error = 0;
	while (*line && !error)
	{
		error = ft_handle_space_or_separator(line, token_list);
		if (!error)
		{
			error = !ft_append_word(line, token_list);
		}
	}
	return (error);
}
