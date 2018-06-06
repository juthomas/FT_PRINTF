/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:49:41 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:04:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cpy1;
	unsigned char		*cpy2;
	unsigned int		i;

	i = 0;
	cpy1 = (unsigned char *)dst;
	cpy2 = (unsigned char *)src;
	if (cpy1 <= cpy2)
	{
		while (i < len)
		{
			cpy1[i] = cpy2[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			cpy1[len - 1] = cpy2[len - 1];
			len--;
		}
	}
	return (dst);
}
