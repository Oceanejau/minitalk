/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:16:23 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 19:47:44 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# define BUFFER 2048
# include <unistd.h>
# include <stdlib.h>

typedef struct s_minit
{
	unsigned int	bit;
	char			message[BUFFER];
	int				index;
	int				end;
	int				over;
}				t_minit;

t_minit			g_minit;
#endif
