/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:28:36 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/27 15:54:42 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lumumbash.h"
# include "tokenizer.h"
# include <stdbool.h>
# include <termios.h>

typedef enum e_node_type
{
	NODE_PIPE,
	NODE_CMD,
	NODE_UNKNOWN
}						t_node_type;
typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND
}						t_redir_type;
typedef enum e_parse_err_type
{
	MALLOC_ERROR = 1,
	SYNTAX_ERROR,
	NO_ERROR,
}						t_parse_error_type;
typedef struct s_redir_node
{
	t_redir_type		type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_redir_node	*prev;
	struct s_redir_node	*next;
}						t_redir_node;
typedef struct s_node
{
	t_node_type			type;
	t_redir_node		*redir_list;
	char				*args;
	struct s_node		*left;
	struct s_node		*right;
	char				**split_args;
	char				**expanded_args;
	char				*value;

}						t_node;
typedef struct s_parse_error
{
	t_parse_error_type	type;
	char				*str;
}						t_parse_error;
typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_minishell
{
	char				*line;
	t_token				*tokens;
	t_token				*current_token;
	t_node				*ast;
	int exit_s; // exit status
	t_parse_error		parse_error;
	int					stdin;
	int					stdout;
	struct termios		original_term;
	char				**environ;
	t_env				*envlst;
	bool				heredoc_sigint;
}						t_minishell;
// nodes.c
void					ft_bzero(void *s, size_t n);
char					*ft_strjoin(char const *s1, char const *s2);
t_node_type				ft_get_node_type(t_token_type type);
t_redir_type			ft_get_redir_type(t_token_type type);
t_node					*ft_new_node(t_node_type type);
t_redir_node			*ft_new_redir_node(t_token_type type, char *value);
void					ft_append_redir_node(t_redir_node **list,
							t_redir_node *new);
// parser_errors.c
void					ft_set_parse_error(t_parse_error_type type);
void					ft_handle_parse_error(t_minishell *minishell);
void					ft_print_syntax_error(t_minishell *minishell,
							t_token_type token_type);
t_token_type			ft_determine_token_type(t_minishell *minishell);
bool					ft_process_redirection(t_redir_node **redir_list,
							t_minishell *minishell, t_token_type redir_type);
// parser_helpers.c
t_node					*ft_term(t_minishell *minishell);
t_node					*ft_combine(t_token_type op, t_node *left,
							t_node *right, t_minishell *minishell);
t_node					*ft_expression(t_minishell *minishell);
// parser_utils.c
bool					ft_current_token_is_op(t_minishell *minishell);
void					ft_get_next_token(t_minishell *minishell);
void					ft_clear_redir_list(t_redir_node **list);
void					ft_clear_cmd_node(t_node *node);
void					ft_recursive_clear_ast(t_node *node);
void					ft_clear_ast(t_node **ast, t_minishell *minishell);
bool					ft_is_redir(t_token_type type);
char					*ft_strjoin_with(char const *s1, char const *s2,
							char c);
bool					ft_join_args(char **args, t_minishell *minishell);
// bool					ft_get_redir_list(t_redir_node **redir_list,
// 							t_minishell *minishell);

bool check_parse_error(t_minishell *minishell);
bool check_current_token(t_minishell *minishell);
bool check_token_type(t_minishell *minishell);
bool create_and_append_redir_node(t_redir_node **redir_list, t_minishell *minishell, t_token_type redir_type);
bool ft_get_redir_list(t_redir_node **redir_list, t_minishell *minishell);
// parser.c
t_node					*ft_parse(t_minishell *minishell);

#endif