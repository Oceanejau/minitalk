/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:21:04 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 20:52:21 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# define BUFFER 2048

typedef struct s_minit
{
	unsigned int	bit;
	char			message[BUFFER];
	int				index;
	int				end;
	int				over;
}				t_minit;

void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

#endif
