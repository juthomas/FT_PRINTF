/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:01:36 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/29 22:01:59 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putwstr_fd(wchar_t const *wstr, int fd)
{
	while (*wstr)
		ft_putwchar_fd(*wstr++, fd);
}
