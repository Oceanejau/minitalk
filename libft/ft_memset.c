/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:13:22 by ojauregu          #+#    #+#             */
/*   Updated: 2021/12/27 17:13:53 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				index;
	unsigned char		*p;

	p = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		p[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
