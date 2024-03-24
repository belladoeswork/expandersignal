#include "lumumbash.h"
#include "expander.h"

t_global g_global;

static void	ft_init_minishell(t_minishell *minishell, char **env)
{    
    memset(minishell, 0, sizeof(t_minishell));
    minishell->environ = env;
    minishell->line = NULL;  
    tcgetattr(STDIN_FILENO, &(minishell->original_term));
}


static void	start_execution(t_minishell *minishell)
{
	ft_init_tree(minishell->ast);

	minishell->exit_s = exec_node(minishell->ast, false);
	ft_clear_ast((&minishell->ast), minishell); // minishell or NULL?
}

// void print_lumumbash() {
//     printf("\033[1;31m"); // Start color code for red
//     printf(" __       __    __  .___  ___.  __    __  .___  ___. .______        ___           _______. __    __  \n");
//     printf("|  |     |  |  |  | |   \\/   | |  |  |  | |   \\/   | |   _  \\      /   \\         /       ||  |  |  | \n");
//     printf("|  |     |  |  |  | |  \\  /  | |  |  |  | |  \\  /  | |  |_)  |    /  ^  \\       |   (----`|  |__|  | \n");
//     printf("|  |     |  |  |  | |  |\\/|  | |  |  |  | |  |\\/|  | |   _  <    /  /_\\  \\       \\   \\    |   __   | \n");
//     printf("|  `----.|  `--'  | |  |  |  | |  `--'  | |  |  |  | |  |_)  |  /  _____  \\  .----)   |   |  |  |  | \n");
//     printf("|_______| \\______/  |__|  |__|  \\______/  |__|  |__| |______/  /__/     \\__\\ |_______/    |__|  |__| \n");
//     printf("\033[0m"); // Reset color to default
// }

#include <stdio.h>

void print_lumumbash() {
    printf("\033[0;31m"); // Set text color to red
    printf(" __       __    __  .___  ___.  __    __  .___  ___. .______        ___           _______. __    __  \n");
    printf("|  |     |  |  |  | |   \\/   | |  |  |  | |   \\/   | |   _  \\      /   \\         /       ||  |  |  | \n");
    printf("|  |     |  |  |  | |  \\  /  | |  |  |  | |  \\  /  | |  |_)  |    /  ^  \\       |   (----`|  |__|  | \n");
    printf("\033[0;32m"); // Set text color to green
    printf("|  |     |  |  |  | |  |\\/|  | |  |  |  | |  |\\/|  | |   _  <    /  /_\\  \\       \\   \\    |   __   | \n");
    printf("|  `----.|  `--'  | |  |  |  | |  `--'  | |  |  |  | |  |_)  |  /  _____  \\  .----)   |   |  |  |  | \n");
    printf("\033[0;33m"); // Set text color to yellow
    printf("|_______| \\______/  |__|  |__|  \\______/  |__|  |__| |______/  /__/     \\__\\ |_______/    |__|  |__| \n");
    printf("\033[0m"); // Reset text color
}



int	main(int argc, char **argv, char **env)
{
	((void)argc, (void)argv);
    t_minishell minishell;
	t_token		*new_tokens;

	print_lumumbash();
	signals();
	ft_init_minishell(&minishell, env);
	while (1)
	{
		minishell.line = readline(PROMPT);
		if (!minishell.line)
			(clean_shell(&minishell),
				ft_putstr_fd("exit\n", 1), exit(minishell.exit_s));
		if (minishell.line[0])
			add_history(minishell.line);
		minishell.tokens = tokenize(minishell.
		line);
		if (!minishell.tokens)
			continue ;
		new_tokens = minishell.tokens;
		minishell.tokens = expander(new_tokens, minishell.environ);
		minishell.ast = ft_parse(&minishell);
		if (minishell.parse_error.type)
		{
			handle_parse_error(&minishell);
			continue ;
		}
		start_execution(&minishell);
	}
	collector(NULL, true);
	return (clean_shell(&minishell), minishell.exit_s);
}
