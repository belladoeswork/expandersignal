/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:51 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 21:05:56 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

void	ft_clear_token_list(t_token **list)
{
	t_token	*current_node;
	t_token	*next;

	current_node = *list;
	while (current_node)
	{
		next = current_node->next;
		if (current_node->value)
		{
			free(current_node->value);
			current_node->value = NULL;
		}
		free(current_node);
		current_node = next;
	}
	*list = NULL;
}

int	ft_token_list_add_back(t_token **lst, t_token *new_token)
{
	t_token	*curr_node;
	int		counter;

	counter = 0;
	if (!new_token || new_token->next)
		return (0);
	if (!*lst)
	{
		*lst = new_token;
		return (1);
	}
	curr_node = *lst;
	while (curr_node->next)
	{
		curr_node = curr_node->next;
		counter++;
		if (counter > 1000 || !curr_node)
			return (0);
	}
	curr_node->next = new_token;
	new_token->prev = curr_node;
	return (1);
}

// t_token	*get_last_node(t_token **lst)
// {
// 	t_token	*curr_node;

// 	curr_node = *lst;
// 	while (curr_node->next)
// 	{
// 		curr_node = curr_node->next;
// 	}
// 	return (curr_node);
// }

// int	ft_token_list_add_back(t_token **lst, t_token *new_token)
// {
// 	t_token	*curr_node;

// 	if (!new_token || new_token->next)
// 	{
// 		return (0);
// 	}
// 	if (!*lst)
// 	{
// 		*lst = new_token;
// 		return (1);
// 	}
// 	curr_node = get_last_node(lst);
// 	if (!curr_node)
// 	{
// 		return (0);
// 	}
// 	curr_node->next = new_token;
// 	new_token->prev = curr_node;
// 	return (1);
// }
