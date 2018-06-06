/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:34:40 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/29 22:00:19 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_straddc(char *s1, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = NULL;
	cpy = (char *)malloc(sizeof(char) * (g_len + 4));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, s1);
	while (i < g_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = c;
	cpy[i + 1] = '\0';
	return (cpy);
}
