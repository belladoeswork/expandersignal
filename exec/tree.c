/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:19:10 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:19:11 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

bool	ft_is_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!*delimiter);
}

void	ft_heredoc(t_redir_node *redir, int p[2])
{
	char		*line;
	char		*quotes;
	t_minishell	*minishell;

	minishell = NULL;
	quotes = redir->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_is_delimiter(redir->value, line))
			break ;
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	ft_clean_shell(minishell);
	exit(0);
}

static bool	ft_leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	close(p[1]);
	if (WIFEXITED(*pid))
		return (true);
	return (false);
}

static void	ft_init_leaf(t_node *node)
{
	t_redir_node	*redir;
	int				p[2];
	int				pid;

	redir = node->redir_list;
	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
		{
			pipe(p);
			pid = fork();
			if (!pid)
				ft_heredoc(redir, p);
			if (ft_leave_leaf(p, &pid))
				return ;
			redir->here_doc = p[0];
		}
		redir = redir->next;
	}
}

void	ft_init_tree(t_node *node)
{
	if (!node)
		return ;
	if (node->type == NODE_PIPE)
	{
		if (node->left)
			ft_init_tree(node->left);
		if (node->right)
			ft_init_tree(node->right);
	}
	else
		ft_init_leaf(node);
}
