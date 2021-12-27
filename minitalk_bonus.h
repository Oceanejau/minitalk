/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:19:35 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 17:42:48 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include "./libft/libft.h"
# define BUFFER 2048

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
