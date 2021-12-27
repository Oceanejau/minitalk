/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:28:57 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 20:39:03 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "minitalk_bonus.h"

void	ft_recu(int signal)
{
	(void)signal;
	ft_putstr_fd("Reçu\n", 1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_sendchar(int pid, unsigned char str)
{
	unsigned int	x;

	x = 1 << 15;
	while (x)
	{
		if (str & x)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Erreur PID\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Erreur PID\n");
		}
		x = x >> 1;
		usleep(60);
	}
}

void	ft_handler(int pid, char *str)
{
	while (*str)
	{
		ft_sendchar(pid, *str);
		str++;
	}
	ft_sendchar(pid, *str);
	return ;
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("/client [PID] [str]\n", 1);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	ft_putstr_fd("PID client = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_recu);
	ft_handler(pid, argv[2]);
	return (0);
}
