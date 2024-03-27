/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:43:55 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/27 17:27:43 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

bool	ft_is_redir(t_token_type type)
{
	if (type == TOKEN_INPUT_REDIRECTION || type == TOKEN_OUTPUT_REDIRECTION
		|| type == TOKEN_HEREDOC || type == TOKEN_APPEND_OUTPUT_REDIRECTION)
		return (true);
	return (false);
}

bool	ft_join_args(char **args, t_minishell *minishell)
{
	char	*to_free;

	if (minishell->parse_error.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (minishell->current_token
		&& minishell->current_token->type == TOKEN_WORD)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, minishell->current_token->value, ' ');
		if (!*args)
		{
			free(to_free);
			return (false);
		}
		free(to_free);
		ft_get_next_token(minishell);
	}
	return (true);
}

// bool	ft_get_redir_list(t_redir_node **redir_list, t_minishell *minishell)
// {
// 	t_token_type	redir_type;
// 	t_redir_node	*tmp_redir_node;

// 	if (minishell->parse_error.type)
// 	{
// 		return (false);
// 	}
// 	while (minishell->current_token
// 		&& ft_is_redir(minishell->current_token->type))
// 	{
// 		redir_type = minishell->current_token->type;
// 		ft_get_next_token(minishell);
// 		if (!minishell->current_token)
// 		{
// 			return (ft_set_parse_error(SYNTAX_ERROR), false);
// 		}
// 		if (minishell->current_token->type != TOKEN_WORD)
// 		{
// 			return (ft_set_parse_error(SYNTAX_ERROR), false);
// 		}
// 		tmp_redir_node = ft_new_redir_node(redir_type,
// 				minishell->current_token->value);
// 		if (!tmp_redir_node)
// 		{
// 			ft_clear_redir_list(redir_list);
// 			ft_set_parse_error(MALLOC_ERROR);
// 			return (false);
// 		}
// 		ft_append_redir_node(redir_list, tmp_redir_node);
// 		ft_get_next_token(minishell);
// 	}
// 	return (true);
// }

// bool	ft_process_redirection(t_redir_node **redir_list,
// 		t_minishell *minishell, t_token_type redir_type)
// {
// 	bool	handle_redir_result;
// 	bool	create_append_result;

// 	ft_get_next_token(minishell);
// 	handle_redir_result = ft_handle_redir_type(minishell);
// 	if (!handle_redir_result)
// 	{
// 		return (false);
// 	}
// 	create_append_result = ft_create_append_redir_node(redir_list, minishell,
// 			redir_type);
// 	if (!create_append_result)
// 	{
// 		return (false);
// 	}
// 	return (true);
// }

// bool	ft_get_redir_list(t_redir_node **redir_list, t_minishell *minishell)
// {
// 	t_token_type	redir_type;
// 	bool			process_result;

// 	if (minishell->parse_error.type)
// 	{
// 		return (false);
// 	}
// 	while (minishell->current_token
// 		&& ft_is_redir(minishell->current_token->type))
// 	{
// 		redir_type = minishell->current_token->type;
// 		process_result = ft_process_redirection(redir_list, minishell,
// 				redir_type);
// 		if (!process_result)
// 		{
// 			return (false);
// 		}
// 	}
// 	return (true);
// }

bool	check_parse_error(t_minishell *minishell)
{
	t_parse_error_type	parse_error_type;

	parse_error_type = minishell->parse_error.type;
	if (parse_error_type)
	{
		return (false);
	}
	return (true);
}

bool	check_current_token(t_minishell *minishell)
{
	if (!minishell->current_token)
	{
		ft_set_parse_error(SYNTAX_ERROR);
		return (false);
	}
	return (true);
}

bool	ft_get_redir_list(t_redir_node **redir_list, t_minishell *minishell)
{
	t_token_type	redir_type;

	if (!check_parse_error(minishell))
	{
		return (false);
	}
	while (minishell->current_token
		&& ft_is_redir(minishell->current_token->type))
	{
		redir_type = minishell->current_token->type;
		ft_get_next_token(minishell);
		if (!check_current_token(minishell) || !check_token_type(minishell))
		{
			return (false);
		}
		if (!create_and_append_redir_node(redir_list, minishell, redir_type))
		{
			return (false);
		}
		// ft_get_next_token(minishell);
		if (minishell->current_token) {
            ft_get_next_token(minishell);
        }
	}
	return (true);
}
