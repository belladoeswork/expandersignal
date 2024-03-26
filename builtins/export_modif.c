/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:52:24 by aguede            #+#    #+#             */
/*   Updated: 2024/03/26 21:52:28 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

char	*ft_update(char *key_update, char *value)
{
	char	*p1;
	char	*p2;
	char	*updated;

	p1 = ft_strdup(key_update);
	p2 = ft_strdup(value);
	updated = ft_strjoin(p1, p2);
	free(p1);
	free(p2);
	return (updated);
}

char	**ft_modify_env_var(char **minishellenviron, char *key, char *value)
{
	char		*key_update;
	char		**str;
	char		*updated;
	t_lists_env	list_env;

	list_env = ft_split_lists_env(minishellenviron);
	key_update = ft_create_new_key(key);
	updated = ft_update(key_update, value);
	str = populate_str(minishellenviron, key, updated, list_env);
	free(key_update);
	free(updated);
	return (str);
}
