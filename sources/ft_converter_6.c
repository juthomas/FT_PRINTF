/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:04:55 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:43:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_fwchare_norm_3(t_var *var, int *len_prec)
{
	if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
			&& var->prec / 16 % 2 == 1)
		ft_s_prec(var->s_precision - *len_prec, ' ');
	else if (var->prec / 2 % 2 == 1)
		var->moing = 1;
	else if (var->prec / 8 % 2 == 1)
		ft_s_prec(var->s_precision - *len_prec, '0');
}

void		ft_fwchare_norm_4(t_var *var)
{
	if (var->prec / 256 % 2 == 1)
	{
		if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
				&& var->prec / 16 % 2 == 1)
			ft_s_prec(var->s_precision, ' ');
		else if (var->prec / 2 % 2 == 1)
			ft_s_prec(var->s_precision, ' ');
		else if (var->prec / 8 % 2 == 1)
			ft_s_prec(var->s_precision, '0');
		else
			ft_putstr_i_printf("(null)", var->s_precp);
	}
	else
		ft_putstr_printf("(null)");
}
