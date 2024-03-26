/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:17:02 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:18:53 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// void    signal_ctrl_c(int numsig)
// {
//     printf("received sigkill\n");
//     printf("lumumbash$ :");
//     (void)numsig;
// }

// void    signal_ctrl_d(int numsig)
// {
//     printf("received EOF\n");
//     printf("lumumbash$ :");
//     (void)numsig;
// }

// void    signal_ctrl_slash(int numsig)
// {
//     printf("received SIGQUIT\n");
//     printf("lumumbash$ :");
//     (void)numsig;
// }

// void    signals()
// {
//     signal(SIGINT, signal_ctrl_c);
//     signal(EOF, signal_ctrl_d);
//     signal(SIGQUIT, signal_ctrl_slash);
// }
// ! UPDATE THE EXITVALUES
// void ft_signal_ctrl_c(int numsig)
// {
//     g_global.error_num = 130;
//     printf("\nReceived SIGINT and exit status is : %d\n",g_global.error_num);
//     printf("lumumbash$ ");

//     fflush(stdout); // Flush the output buffer
//     (void)numsig; // Unused parameter
// }

// void ft_signal_ctrl_d(int numsig)
// {
//     g_global.error_num = 131;
//     printf("\nReceived SIGQUIT and exit status is : %d\n",g_global.error_num);
//     exit(EXIT_SUCCESS); // Exit the shell gracefully
//     (void)numsig; // Unused parameter
// }

// void ft_signal_ctrl_slash(int numsig)
// {
//     g_global.error_num = 131;
//     printf("\nReceived SIGQUIT and exit status is : %d\n",g_global.error_num);
//     printf("lumumbash$ ");
//     fflush(stdout); // Flush the output buffer
//     exit(EXIT_SUCCESS);
//     (void)numsig; // Unused parameter
//

void	ft_signal_ctrl_c(int numsig)
{
	g_global.error_num = 130;
	// printf("\nReceived SIGINT and exit status is : %d\n",g_global.error_num);
	// printf("lumumbash$ ");
	write(STDOUT_FILENO, "\nlumumbash$ ", 13);
	fflush(stdout); // Flush the output buffer
	(void)numsig;   // Unused parameter
}

void	ft_signal_ctrl_d(int numsig)
{
	g_global.error_num = 131;
	write(STDOUT_FILENO, "\nReceived SIGQUIT\n", 43);
	// printf("\nReceived SIGQUIT and exit status is : %d\n",g_global.error_num);
	exit(EXIT_SUCCESS); // Exit the shell gracefully
	(void)numsig;       // Unused parameter
}

void	ft_signal_ctrl_slash(int numsig)
{
	g_global.error_num = 131;
	printf("\nReceived SIGQUIT and exit status is : %d\n", g_global.error_num);
	// printf("lumumbash$ ");
	fflush(stdout); // Flush the output buffer
	exit(EXIT_SUCCESS);
	(void)numsig; // Unused parameter
}

void	ft_signals(void)
{
	signal(SIGINT, ft_signal_ctrl_c);
	// signal(SIGQUIT, ft_signal_ctrl_slash);
	signal(SIGQUIT, SIG_IGN);
	// signal(SIG, ft_signal_ctrl_d);
}