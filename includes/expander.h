/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:27:06 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/27 00:53:43 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "lumumbash.h"
# include "parser.h"
# include "tokenizer.h"
# include <ctype.h>
# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_lists_env
{
	char	**p1;
	char	**p2;
}			t_lists_env;


// ! export.c
int	ft_export(char **argv, t_minishell **minishell);
char	**populate_str(char **minishellenviron, char *key, char *update,
		t_lists_env list_env);
// export_utils.c

char	**duplicate_environ(char **minishellenviron, char *key_update,
		char *value);
void	ft_free_lists_env(t_lists_env envi);
int	ft_key_check(char *key, t_minishell *minishell);
char	*ft_create_new_key(char *key);


//export_modif.c
char	**ft_modify_env_var(char **minishellenviron, char *key, char *value);
// utils
int ft_my_strlen(long number);
char *ft_strdup(const char *s1);

//utils part 2
int	ft_strlen_double(char **str);
void	ft_free_tmp(char *str, int c, int check);
int	ft_dollar(char *str);
int	ft_digit_or_q(char *str, char c);
int	ft_countword(char *str, char c, char *tmp);

// size_t		ft_strlen(const char *s);
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
void	ft_free_new_str_str(char ***new_str_str);
void	ft_free_envi(char **part1, char **part2);
// expand_tilde.c
char *ft_expand_tilde(char *str, char **p1, char **p2);


// tester_functions.c
void		ft_print_double_d(char **str, char *from, int n);
int			ft_count_number_of_words(char ***triple_d_str);
//char		*ft_strcat(char *dest, char *src);
char		*ft_itoa(int n);
void		ft_free_everything(t_lists_env envi, char **div_by_quote, char **clean);
// char		*ft_strcat(char *dest, char *src);
// void	ft_free_everything(t_lists_env envi,char **div_by_quote,char **clean, char *expanded_tilde);
void	ft_free_everything(t_lists_env envi,char **div_by_quote,char **clean);
// expand_assemble.c
char		*ft_expand_assemble(char **str, char **b_equal, char **a_equal);

// ft_split_bis.c
int	count_words(char *str, char c);

char	*ft_fill_the_word(char *str, int end, char *lst);
char	**ft_allocate_memory(char *str, char c);

//expander utils 2.c
int	find_next_word_length(char *str, char c);

//expander_helpers.c
char	**ft_string_to_double_d(char *str);

#endif