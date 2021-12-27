/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:20:09 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 17:45:23 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_run(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (!g_minit.bit)
	{
		g_minit.bit = 1 << 15;
		g_minit.index += 1;
	}
	g_minit.message[g_minit.index] += g_minit.bit;
	g_minit.bit >>= 1;
	if (g_minit.index == BUFFER - 2 && !g_minit.bit)
		g_minit.over = 1;
}

void	ft_stop(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_minit.bit)
	{
		g_minit.bit = 1 << 15;
		g_minit.index += 1;
	}
	g_minit.bit >>= 1;
	if (g_minit.index == BUFFER - 2 && !g_minit.bit)
		g_minit.over = 1;
	else if (!g_minit.message[g_minit.index] && !g_minit.bit)
	{
		g_minit.end = 1;
		kill(info->si_pid, SIGUSR1);
	}
}

void	print_it(struct sigaction *on, struct sigaction *off)
{
	if (sigaction(SIGUSR1, on, NULL) != 0)
	{
		ft_putstr_fd("Erreur SIG1\n", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, off, NULL) != 0)
	{
		ft_putstr_fd("Erreur SIG2\n", 2);
		exit(1);
	}
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_bzero(g_minit.message, BUFFER);
	g_minit.bit = 1 << 15;
	g_minit.index = 0;
	g_minit.end = 0;
	g_minit.over = 0;
	return ;
}

void	ft_handler(void)
{
	while (1)
	{
		pause();
		if (g_minit.end || g_minit.over)
		{
			ft_putstr_fd(g_minit.message, 1);
			ft_bzero(g_minit.message, BUFFER);
			g_minit.bit = 1 << 15;
			g_minit.index = 0;
			if (g_minit.end)
				ft_putchar_fd('\n', 1);
			g_minit.end = 0;
			g_minit.over = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	on;
	struct sigaction	off;

	on.sa_sigaction = ft_run;
	on.sa_flags = SA_SIGINFO;
	off.sa_sigaction = ft_stop;
	off.sa_flags = SA_SIGINFO;
	print_it(&on, &off);
	ft_handler();
	return (0);
}
