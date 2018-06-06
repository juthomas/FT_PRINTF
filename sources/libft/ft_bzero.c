/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:57:06 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:12:22 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*cpy;

	cpy = s;
	i = 0;
	while (i < n)
	{
		cpy[i] = '\0';
		i++;
	}
	s = cpy;
}
