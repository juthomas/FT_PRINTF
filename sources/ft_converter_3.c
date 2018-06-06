/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:49:27 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:41:03 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_fllint_norm_1(t_var *var, long long int type, t_int *st)
{
	if (var->conv == 4 || var->conv == 5 || var->conv == 7 || var->conv == 10
			|| var->conv == 12)
		st->cpylen = ft_numberlen("0123456789", type, var);
	else if (var->conv == 6 || var->conv == 11)
		st->cpylen = ft_numberlen("01234567", type, var);
	else if (var->conv == 8 || var->conv == 9 || var->conv == 3)
		st->cpylen = ft_numberlen("0123456789ABCDEF", type, var);
	else
		var->error = 1;
	if (var->prec % 2 == 1 && type == 0 && var->s_precp == 0)
	{
		if ((var->prec / 256 % 2 == 0 && (var->conv == 8 || var->conv == 9))
				|| (var->conv != 8 && var->conv != 9))
			ft_putchar_printf('0');
		return (1);
	}
	if (var->prec / 256 % 2 == 1 && var->s_precp == 0 && type == 0)
		st->cpylen = 0;
	if (var->prec / 256 % 2 == 1 && (var->conv == 3 || (var->prec % 2 == 1
				&& (var->conv == 8 || var->conv == 9))) && var->s_precp > 0)
		st->cpylen -= 2;
	else if (var->prec / 256 % 2 == 1 && (var->prec % 2 == 1 && var->conv == 6)
			&& var->s_precp > 0)
		st->cpylen += 1;
	return (0);
}

void		ft_fllint_norm_2(t_int *st, t_var *var, int *plen, int *nlen)
{
	if (st->cpylen < var->s_precp)
	{
		*plen = var->s_precp - st->cpylen;
		st->cpylen = var->s_precp;
	}
	if (((var->prec / 64 % 2 == 1 || var->prec / 4 % 2 == 1)
				&& (var->conv == 4 || var->conv == 5 || var->conv == 10))
			|| ((var->conv == 4 || var->conv == 5 || var->conv == 10)
				&& var->negativ) || (var->prec % 2 == 1 && (var->conv == 6)))
		st->cpylen++;
	if (st->cpylen < var->s_precision)
	{
		*nlen = var->s_precision - st->cpylen;
		if (var->prec / 256 % 2 == 1 && var->conv == 3 && var->s_precp > 0
				&& *nlen > 1)
			*nlen = *nlen - 2;
		else if (var->prec / 256 % 2 == 1 && var->conv == 3 && var->s_precp > 0
				&& *nlen == 1)
			*nlen = *nlen - 1;
	}
}

int			ft_fllint_norm_3(t_var *var, long long int *type)
{
	if (var->prec / 4 % 2 == 1 && (var->conv == 4 || var->conv == 5
				|| var->conv == 10))
	{
		if (*type < 0)
		{
			ft_putchar_printf('-');
			*type = *type * (-1);
		}
		else
			ft_putchar_printf('+');
	}
	else if (var->prec / 64 % 2 == 1 && (var->conv == 4 || var->conv == 5
				|| var->conv == 10))
	{
		if (*type < 0)
		{
			ft_putchar_printf('-');
			*type = *type * (-1);
		}
		else
			ft_putchar_printf(' ');
	}
	else
		return (1);
	return (0);
}

void		ft_fllint_norm_4(t_var *var, long long int *type)
{
	if ((var->conv == 4 || var->conv == 5 || var->conv == 10)
			&& *type < 0)
	{
		ft_putchar_printf('-');
		*type = *type * (-1);
	}
	else if ((var->prec % 2 == 1 && (var->conv == 8 || var->conv == 9
					|| var->conv == 3)) || var->conv == 3)
	{
		if (var->conv == 8 || var->conv == 3)
			ft_putstr_printf("0x");
		else
			ft_putstr_printf("0X");
	}
	else if (var->prec % 2 == 1 && (var->conv == 6 || var->conv == 11))
	{
		ft_putchar_printf('0');
	}
}

void		ft_fllint_norm_5(t_var *var, long long int type, int plen, int nlen)
{
	if (var->prec / 256 % 2 == 1)
		ft_s_prec(plen, '0');
	if ((var->conv == 4 || var->conv == 5 || var->conv == 10) && type < 0)
		type = -type;
	if (var->prec / 2 % 2 == 1)
		var->moing = 1;
	else if (var->prec / 8 % 2 == 1)
		ft_s_prec(nlen, '0');
	if (!(var->prec / 256 % 2 == 1 && var->s_precp == 0 && type == 0))
		ft_fullint_final_conv(var, type);
	if (var->moing)
		ft_s_prec(nlen, ' ');
}
