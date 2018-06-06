/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:46:44 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/23 18:08:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 0x7F)
		ft_putchar_fd(wc, fd);
	else if (wc <= 0x7FF)
	{
		ft_putchar_fd((wc / 0x40) + 0xC0, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar_fd((wc / 0x1000) + 0xE0, fd);
		ft_putchar_fd(((wc / 0x40) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putchar_fd((wc / 0x40000) + 0xF0, fd);
		ft_putchar_fd(((wc / 0x1000) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((wc / 0x40) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
}
