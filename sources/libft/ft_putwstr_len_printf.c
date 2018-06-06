/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_len_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:57:36 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/29 22:00:41 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putwstr_len_printf(wchar_t const *wstr, int i)
{
	int u;

	u = 0;
	while (wstr[u] != '\0' && u < i)
		ft_putwchar_printf(wstr[u++]);
}
