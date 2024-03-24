#ifndef LUMUMBASH_H
# define LUMUMBASH_H

# include "parser.h"
# include "tokenizer.h"
# include "global.h"
# include "expander.h"
# include <ctype.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define MAX_NUM_ARGS 100

typedef enum e_ast_direction
{
	TD_LEFT,
	TD_RIGHT
}		t_ast_direction;
// builtins
int		ft_echo(char **args);
void	ft_exit(char **args, t_minishell *minishell);
int		ft_pwd(void);
void	ft_init_envlst(t_minishell *minishell);
int		ft_env(t_minishell *minishell);
// int		ft_unset(char **args, t_minishell *minishell);
int	ft_unset(char **args, t_minishell **minishell);
void	ft_update_envlst(char *key, char *value, bool create,
			t_minishell *minishell);
// int		ft_export(char **argv, t_minishell *minishell);
int	ft_export(char **argv, t_minishell **minishell);
int 	ft_strlen_double_pers(char **str);
// help
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_alphanum(int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_extract_key(char *str);
bool	ft_env_entry_exists(char *key, t_minishell *minishell);
int		ft_keycheck(char *str);
void	ft_envlst_back(t_env *new, t_minishell *minishell);
char	*ft_extract_value(char *str);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_clean_shell(t_minishell *minishell);
void	*ft_collector(void *ptr, bool clean);
void	ft_free_char2(char **tofree); // added after expander
// tree.c
void	ft_init_tree(t_node *node);
bool	ft_is_delimiter(char *delimiter, char *str);
void	ft_heredoc(t_redir_node *redir, int p[2]);
// pipes_exec.c
int		ft_exec_child(t_node *node);
// exec.c
int		ft_get_exit_status(int status);
int		ft_exec_node(t_node *tree, bool piped, t_minishell *minishell);
// exec_utils.c
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_check_redir(t_node *node);
// exec_simple.c
void	ft_reset_stds(bool piped);
int		ft_exec_builtin(char **args, t_minishell *minishell);
bool	ft_is_builtin(char *arg);
int		ft_exec_simple_cmd(t_node *node, bool piped, t_minishell *minishell);
// errors.c
int		ft_error_msg(t_error error);
// checks.c
t_error	ft_check_exec(char *file, bool cmd);
t_error	ft_check_read(char *file);
t_error	ft_check_write(char *file);
// exec_redir.c
int		ft_out(t_redir_node *redir_list, int *status);
int		ft_in(t_redir_node *redir_list, int *status);
int		ft_append(t_redir_node *redir_list, int *status);

// expander.c
t_token *expander(t_token *tokenized_tokens, char **env);

// signals.c

void    signals();
void    signal_ctrl_slash(int numsig);
void    signal_ctrl_d(int numsig);
void    signal_ctrl_c(int numsig);

#endif