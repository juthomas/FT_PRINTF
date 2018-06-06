/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:46:44 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/23 18:09:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putwchar_printf(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putchar_printf(wc);
	else if (wc <= 0x7FF)
	{
		ft_putchar_printf((wc / 0x40) + 0xC0);
		ft_putchar_printf((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar_printf((wc / 0x1000) + 0xE0);
		ft_putchar_printf(((wc / 0x40) & 0x3F) + 0x80);
		ft_putchar_printf((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putchar_printf((wc / 0x40000) + 0xF0);
		ft_putchar_printf(((wc / 0x1000) & 0x3F) + 0x80);
		ft_putchar_printf(((wc / 0x40) & 0x3F) + 0x80);
		ft_putchar_printf((wc & 0x3F) + 0x80);
	}
}
