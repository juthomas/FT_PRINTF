/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:44:15 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 13:39:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_fchare_norm_1(t_var *var)
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

void		ft_fchare(char *type, t_var *var)
{
	int		len;

	len = 0;
	var->moing = 0;
	if (type != NULL)
	{
		len = ft_strlen(type);
		if (var->prec / 256 % 2 == 1 && len > var->s_precp && var->s_precp >= 0)
			len = var->s_precp;
		if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
				&& var->prec / 16 % 2 == 1)
			ft_s_prec(var->s_precision - len, ' ');
		else if (var->prec / 2 % 2 == 1)
			var->moing = 1;
		else if (var->prec / 8 % 2 == 1)
			ft_s_prec(var->s_precision - len, '0');
	}
	if (type == 0)
		ft_fchare_norm_1(var);
	else
		ft_putstr_len_printf(type, len);
	if (var->moing == 1)
		ft_s_prec(var->s_precision - len, ' ');
	var->prec = 0;
}

void		ft_fwchar(wchar_t type, t_var *var)
{
	int			len;

	len = 0;
	if (type <= 0X7F)
		len = 0;
	else if (type <= 0X7FF)
		len = 1;
	else if (type <= 0XFFFF)
		len = 2;
	else if (type <= 0X10FFFF)
		len = 3;
	var->moing = 0;
	if (var->prec / 2 % 2 == 1)
		var->moing = 1;
	else if (var->prec / 8 % 2 == 1)
		ft_s_prec(len, '0');
	else if (var->prec / 16 % 2 == 1)
		ft_s_prec(len, ' ');
	ft_putwchar_printf(type);
	if (var->moing)
		ft_s_prec(len, ' ');
}

void		ft_fwchare_norm_1(wchar_t *type, int i, int *len)
{
	while (type[i] != 0)
	{
		if (type[i] <= 0X7F)
			*len = *len + 1;
		else if (type[i] <= 0X7FF)
			*len = *len + 2;
		else if (type[i] <= 0XFFFF)
			*len = *len + 3;
		else if (type[i] <= 0X10FFFF)
			*len = *len + 4;
		i++;
	}
}

int			ft_fwchare_norm_2(int *len, t_var *var, wchar_t *type, int *u)
{
	int i;
	int len_prec;

	i = 0;
	*len = 0;
	while (type[*len] != 0 && var->s_precp > i)
	{
		*u = 0;
		if (type[*len] <= 0X7F)
			*u = *u + 1;
		else if (type[*len] <= 0X7FF)
			*u = *u + 2;
		else if (type[*len] <= 0XFFFF)
			*u = *u + 3;
		else if (type[*len] <= 0X10FFFF)
			*u = *u + 4;
		*len = *len + 1;
		i += *u;
	}
	if (i > var->s_precp)
		*len = *len - 1;
	if (i > var->s_precp)
		i -= *u;
	len_prec = i;
	return (len_prec);
}
