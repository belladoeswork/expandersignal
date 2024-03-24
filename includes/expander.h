#ifndef EXPANDER_H
# define EXPANDER_H

# include "lumumbash.h"
# include <ctype.h>
# include <dirent.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_lists_env
{
	char	**p1;
	char	**p2;
}			t_lists_env;

// utils
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
// int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strncpy(char *dst, const char *src, size_t size);

char		*ft_find_env_var_part2(char *str);
char		**ft_split_bis(char *str, char c);
char		**ft_new_ft_split(char *str, char c);
char		**ft_split_double(char **str, char c);
int			ft_check_if_expand(char *str, char **before_equal);
char		**ft_remove_wrong_env_var(char **str, char **before_equal);
t_lists_env	ft_split_lists_env(char **env);
t_token		*ft_expander(t_token *tokenized_tokens, char **env);

// ft_frees.c
void		ft_free_double_d(char **str);

// expand_tilde.c
char *ft_expand_tilde(char *str, char **p1, char **p2);

// tester_functions.c
void		ft_print_double_d(char **str, char *from, int n);
int			ft_count_number_of_words(char ***triple_d_str);
char		*ft_strcat(char *dest, char *src);
void	ft_free_everything(t_lists_env envi,char **div_by_quote,char **clean);

// expand_assemble.c
char		*ft_expand_assemble(char **str, char **b_equal, char **a_equal);

#endif