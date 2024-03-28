/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasha <tasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:15:22 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/28 02:05:51 by tasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lumumbash.h"

// int	ft_safe_dup2(int oldfd, int newfd)
// {
// 	if (dup2(oldfd, newfd) == -1)
// 	{
// 		perror("dup2");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (newfd);
// }

// int	ft_safe_close(int fd)
// {
// 	if (close(fd) == -1)
// 	{
// 		perror("close");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (fd);
// }

// int	ft_safe_open(const char *pathname, int flags, mode_t mode)
// {
// 	int	fd;

// 	fd = open(pathname, flags, mode);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 		// exit -1;
// 	}
// 	return (fd);
// }
