/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:44:11 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 21:04:25 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

t_node	*ft_parse(t_minishell *minishell)
{
	t_node	*ast;

	if (minishell->tokens != NULL)
		minishell->current_token = minishell->tokens;
	ast = ft_expression(minishell);
	if (minishell->current_token)
	{
		ft_set_parse_error(SYNTAX_ERROR);
		return (ast);
	}
	return (ast);
}
