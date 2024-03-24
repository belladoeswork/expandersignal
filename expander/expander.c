/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:41 by aguede            #+#    #+#             */
/*   Updated: 2024/03/24 23:28:40 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	ft_check_if_expand(char *str, char **p1)
{
	int	i;

	i = 0;
	if (str[0] == '$')
	{
		while (p1[i] != NULL)
		{
			if ((ft_strncmp(str + 1, p1[i], ft_strlen(p1[i])) == 0 && (ft_strlen(p1[i]) == (ft_strlen(str) - 1))) || str[1] == '?')
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_check_dollar_word_expand(char **dollar_separated_str, char **p1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dollar_separated_str[i] != NULL)
	{
		if (dollar_separated_str[i][0] == '$')
		{
			if (ft_check_if_expand(dollar_separated_str[i], p1))
				j++;
		}
		i++;
	}
	return (j);
}

int	ft_check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

t_token	*ft_expander(t_token *tokens, char **env)
{
	t_lists_env	envi;
	char		**div_by_quote = NULL;
	t_token		*head;
	char		**div_by_doll = NULL;
	char		**clean = NULL;
	char		*expanded_tilde;

	envi = ft_split_lists_env(env);
	head = tokens;
	while (tokens != NULL)
	{
		if(tokens->type == TOKEN_WORD)
		{
			expanded_tilde = ft_expand_tilde(tokens->value, envi.p1, envi.p2);
			if (tokens->type == TOKEN_WORD
				&& ft_check_dollar(tokens->value))
			{
				div_by_quote = ft_new_ft_split(expanded_tilde, '\'');
				//div_by_quote = new_ft_split(tokens->value, '\'');
				//ft_print_double_d(div_by_quote, "expander after div_by_quote", -1);
				div_by_doll = ft_split_double(div_by_quote, '$');
				ft_print_double_d(div_by_doll, "expander after div_by_doll", -1);
				// if ((check_dollar_word_expand(div_by_doll, envi.p1)) >= 1)
				// {
					// todo clean doit ft_double_strdup div_by_doll comme ca je peux free_double_d div by doll a la fin
					clean = ft_remove_wrong_env_var(div_by_doll, envi.p1);
					ft_print_double_d(clean, "expander after remove_wrong_env_var", -1);
					// todo egalement double ft_strdup clean dans expand and assemble
					tokens->value = ft_expand_assemble(clean, envi.p1, envi.p2);
					// ! normally the rest of the code will handle freeing tokens-> value
				// }
				// todo use a ft_double_strdup to send div_by_doll
				// todo free div_by_doll
			}
			else
				tokens->value = expanded_tilde;
			if (ft_strncmp(tokens->value, expanded_tilde, ft_strlen(expanded_tilde) != 0))
				free(expanded_tilde);
		}
		tokens = tokens->next;
		// if (expanded_tilde)
		// {
		// 	if (ft_strncmp(tokens->prev->value, expanded_tilde, ft_strlen(tokens->prev->value) != 0))
		// 		free(expanded_tilde);
		// }
	}
	ft_free_everything(envi, div_by_quote, clean);//, expanded_tile);
	return (head);
}

// echo hello users 'hi' how are you '$USER' doing $SHELL $USERT oh $hey jjk
// echo hello users 'hi' $?GFG$123 orhh $SHELL $tacruquoi
// valgrind --leak-check=full --track-origins=yes ./lumumbash 2>&1 | tee valgrind.txt
// issues : 
// rest of minishell :


// fixing signals, norminette and leaks
