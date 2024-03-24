#include "lumumbash.h"

static int	ft_export_error_msg(char *identifier)
{
	ft_putstr_fd("lumumbash: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

// static void	ft_export_list(t_minishell *minishell)
// {
// 	t_env	*list;
// 	size_t	i;

// 	list = minishell->envlst;
// 	while (list)
// 	{
// 		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
// 		{
// 			printf("declare -x %s=\"", list->key);
// 			i = 0;
// 			while ((list->value)[i])
// 			{
// 				if ((list->value)[i] == '$' || (list->value)[i] == '"')
// 					printf("\\%c", (list->value)[i++]);
// 				else
// 					printf("%c", (list->value)[i++]);
// 			}
// 			printf("\"\n");
// 		}
// 		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
// 			printf("declare -x %s\n", list->key);
// 		list = list->next;
// 	}
// }

// static t_env	*ft_envlst_new(char *key, char *value)
// {
// 	t_env	*new;

// 	new = (t_env *)ft_calloc(1, sizeof(t_env));
// 	if (!new)
// 		return (NULL);
// 	new->key = ft_collector(ft_strdup(key), false);
// 	if (value)
// 		new->value = ft_collector(ft_strdup(value), false);
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_update_envlst(char *key, char *value, bool create,
// 		t_minishell *minishell)
// {
// 	t_env	*envlst;

// 	envlst = minishell->envlst;
// 	while (envlst)
// 	{
// 		if (!ft_strcmp(key, envlst->key))
// 		{
// 			if (value)
// 				envlst->value = ft_collector(ft_strdup(value), false);
// 			return ;
// 		}
// 		envlst = envlst->next;
// 	}
// 	if (create)
// 		ft_envlst_back(ft_envlst_new(key, value), minishell);
// }

// int	ft_export(char **argv, t_minishell *minishell)
// {
// 	int		i;
// 	int		exit_s;
// 	char	*key;

// 	exit_s = 0;
// 	i = 1;
// 	if (!argv[1])
// 		return (ft_export_list(minishell), 0);
// 	while (argv[i])
// 	{
// 		if (ft_keycheck(argv[i]) == 0)
// 			exit_s = ft_export_error_msg(argv[i]);
// 		else
// 		{
// 			key = ft_extract_key(argv[i]);
// 			if (ft_env_entry_exists(key, minishell))
// 				ft_update_envlst(key, ft_extract_value(argv[i]), false, minishell);
// 			else
// 				ft_update_envlst(key, ft_extract_value(argv[i]), true, minishell);
// 		}
// 		i++;
// 	}
// 	return (exit_s);
// }

int 	ft_strlen_double_pers(char **str)
{
	int i;
	printf("inside ft_strlen_double_pers\n");
	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	ft_modif_env_var(t_lists_env envi, char *key, char *value, t_minishell *minishell)
{
	int i;
	int j;
	int k;
	char *key_update;
	char **new_environ;

	i = 0;
	j = 0;
	k = 0;
	new_environ = calloc(ft_strlen_double_pers(minishell->environ) + 2, sizeof(char *));
	printf("inside ft_modif_env_var\n");
	key_update = calloc(ft_strlen(key) + 2, sizeof(char));
	if(!key_update)
		exit(EXIT_FAILURE);
	while(key[j] != 0)
	{
		key_update[j] = key[j];
		j++;
	}
	key_update[j] = '=';
	j++;
	key_update[j] = 0;
	printf("key_update is : %s\n", key_update);
	while(envi.p1[i] != NULL)
	{
		if (ft_strncmp(key, envi.p1[i], ft_strlen(envi.p1[i])) == 0)
			break;
		i++;
	}
	printf("i is : %d, key_update is : %s, value is %s\n", i, key_update, value);
	while(minishell->environ[k] != NULL)
	{
		new_environ[k] = ft_strdup(minishell->environ[k]);
		k++;
	}
	new_environ[k] = ft_strjoin(key_update, value);
	k++;
	new_environ[k] = NULL;
	//free(minishell->environ);
	minishell->environ= new_environ;
	printf("minishell->environ[%d] = %s\n", i, minishell->environ[i]);
	ft_print_double_d(minishell->environ, "export end", -1);
}

void	ft_add_env_var(char *key, char *value, int true_or_false, t_minishell *minishell)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t_lists_env list_env;
	char *key_update;
	char	**str;

	list_env = ft_split_lists_env(minishell->environ);
	key_update = calloc(ft_strlen(key) + 2, sizeof(char));
	if(!key_update)
		exit(EXIT_FAILURE);
// todo if true_or_false == 1
// todo if true_or_false == 0
	if(true_or_false == 1)
	{
		while(key[j] != 0)
		{
			key_update[j] = key[j];
			j++;
		}
		key[j] = '=';
		j++;
		key[j] = 0;
		str = calloc(ft_strlen_double_pers(minishell->environ) + 2, sizeof(char *));
		if(!str)
			exit(EXIT_FAILURE);
		while(minishell->environ[i] != NULL)
		{
			str[i] = ft_strdup(minishell->environ[i]);
			i++;
		}
 		str[i] = ft_strjoin(ft_strdup(key_update), ft_strdup(value)) ;
		// strjoin = VAR=therese
		i++;
		str[i] = NULL;
		minishell->environ = str;
	}
	else if (true_or_false == 0)
	{
		ft_modif_env_var(list_env, key, value, minishell);
	}
	// todo free list_env
	// todo free key_update
}


// je vais envoyer la liste faite dans l'expander dans minishell struct; // ou alors j'utilise juste les deux fonctions
// ensuite dans export je vais envoyer mon minishell reference
// dedans je check avec ft_strcmp si la valeur existe deja
// si elle existe je vais juste aller a l'index de la env var qui existe et je vais la remplacer par ft_strjoin de la list_splittee part1 a l'index et la part d'apres quon evoie a export
// si elle n'existe pas je vais juste dupliquer la liste et rajouter la nouvelle variable
int ft_key_check(char *key, t_minishell *minishell)
{
	int i;
	char **env = minishell->environ;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp(key, env[i] + 1) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_export(char **argv, t_minishell **minishell)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	printf("inside export\n");
	// ! I just do not understand that
	if (!argv[1])
		return (1);
		//return (ft_export_list(minishell), 0);
	// !
	while (argv[i])
	{
		if (ft_keycheck(argv[i]) == 0)
		{
			exit_s = ft_export_error_msg(argv[i]);
			//printf("ft_keycheck is not passed\n");
		}
		else
		{
			key = ft_extract_key(argv[i]);
			//printf("this is the key : %s\n", key);
			if (!ft_key_check(key, *minishell))
			{
				//printf("key exists\n");
				ft_add_env_var(key, ft_extract_value(argv[i]), 0, *minishell);
			}
			else
			{
				//printf("key did not exist yet\n");
				ft_add_env_var(key, ft_extract_value(argv[i]), 1, *minishell);
			}
		}
		i++;
	}

	return (exit_s);
}

// todo free everything
// todo norminette
// todo make sure to do for unexistant var