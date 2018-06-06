/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:51:18 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/12 13:53:46 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		ft_putstr_len_printf(char const *s, int len)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		ft_putchar_printf(s[i]);
		i++;
	}
}
