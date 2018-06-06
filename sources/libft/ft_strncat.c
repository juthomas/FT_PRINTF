/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 16:38:20 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:12:45 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int u;

	u = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0' && u < nb)
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	dest[i] = '\0';
	return (dest);
}
