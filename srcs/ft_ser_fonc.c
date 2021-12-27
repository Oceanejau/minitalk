/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ser_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:26:04 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 19:26:10 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	char			result[30];
	int				x;
	unsigned int	nb;

	x = 0;
	if (n == 0)
		write(fd, "0", sizeof(char));
	else
	{
		if (n < 0)
			nb = n * -1;
		else
			nb = n;
		while (nb != 0)
		{
			result[x++] = (nb % 10) + '0';
			nb = nb / 10;
		}
		if (n < 0)
			write(fd, "-", sizeof(char));
		while (--x >= 0)
		{
			write(fd, &result[x], sizeof(char));
		}
	}
}
