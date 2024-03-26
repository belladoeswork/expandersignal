/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbella-n <tbella-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:27:47 by tbella-n          #+#    #+#             */
/*   Updated: 2024/03/27 00:27:48 by tbella-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

# include "lumumbash.h"

typedef struct s_global
{
	int			error_num;
	int			stop_heredoc;
	int			in_cmd;
	int			in_heredoc;
}				t_global;

extern t_global	g_global;

#endif
