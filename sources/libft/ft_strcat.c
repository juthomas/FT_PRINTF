/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 16:30:31 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:07:42 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int u;

	u = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0')
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}
