/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@ssh.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:12:02 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:03:35 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (ret != NULL)
	{
		ft_bzero(ret, size);
		return (ret);
	}
	return (NULL);
}
