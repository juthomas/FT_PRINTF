/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:59:14 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:04:04 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*cpy1;
	unsigned char		*cpy2;

	cpy1 = (unsigned char*)s1;
	cpy2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (cpy1[i] != cpy2[i])
			return ((int)((unsigned char)cpy1[i] - (unsigned char)cpy2[i]));
		i++;
	}
	return (0);
}
