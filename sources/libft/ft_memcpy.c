/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 17:51:12 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:04:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int		u;
	char				*cpy1;
	const char			*cpy2;

	u = 0;
	cpy1 = (char*)dst;
	cpy2 = (const char*)src;
	while (u < n)
	{
		cpy1[u] = cpy2[u];
		u++;
	}
	return ((void *)cpy1);
}
