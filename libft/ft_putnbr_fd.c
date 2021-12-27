/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:13:02 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 17:13:11 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
