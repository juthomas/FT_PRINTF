/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:58:42 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/27 18:20:20 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_dollard_while(char *str, unsigned int tab[2]
		, char *fin, int *nb)
{
	tab[0]++;
	while (is_printf_char(str[tab[0]]) == 1 && str[tab[0]] != '$')
		tab[0]++;
	if (str[tab[0]++] == '$')
	{
		tab[1] = tab[0] - 2;
		while (str[tab[1]] >= '0' && str[tab[1]] <= '9')
			tab[1]--;
		if (str[tab[1] + 1] == '$')
			*fin = 1;
		else if (*nb < ft_atoi(&str[tab[1] + 1]))
			*nb = ft_atoi(&str[tab[1] + 1]);
		if (*fin == 0)
		{
			while (is_printf_char(str[tab[0]]) == 1)
				tab[0]++;
			if (is_printf_char(str[tab[0]] == 0))
				*nb = 0;
		}
	}
	*fin = 0;
}

int				ft_dollard(char *str)
{
	unsigned int	tab[2];
	char			fin;
	int				nb;

	nb = 0;
	fin = 0;
	tab[0] = 0;
	while (str[tab[0]] != '\0')
	{
		if (str[tab[0]] == '%')
		{
			ft_dollard_while(str, tab, &fin, &nb);
		}
		tab[0]++;
	}
	return (nb);
}
