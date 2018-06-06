/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:25:08 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:57:47 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_fllint(long long int mod, t_var *var, int conv)
{
	t_int			st;
	long long int	type;
	int				nlen;
	int				plen;

	type = ft_casting_time(mod, conv, var);
	plen = 0;
	nlen = 0;
	var->moing = 0;
	if (ft_fllint_norm_1(var, type, &st))
		return ;
	ft_fllint_norm_2(&st, var, &plen, &nlen);
	if (var->error == 0)
	{
		if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
				&& var->prec / 16 % 2 == 1)
			ft_s_prec(nlen, ' ');
		if (ft_fllint_norm_3(var, &type))
			ft_fllint_norm_4(var, &type);
		ft_fllint_norm_5(var, type, plen, nlen);
	}
}

void		ft_fchar(char type, t_var *var)
{
	var->moing = 0;
	if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
			&& var->prec / 16 % 2 == 1)
		ft_s_prec(var->s_precision - 1, ' ');
	else if (var->prec / 2 % 2 == 1)
		var->moing = 1;
	else if (var->prec / 8 % 2 == 1)
		ft_s_prec(var->s_precision - 1, '0');
	ft_putchar_printf(type);
	if (var->moing == 1)
		ft_s_prec(var->s_precision - 1, ' ');
	var->prec = 0;
}
