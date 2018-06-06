/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:02:06 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 13:40:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		ft_conversion_2(t_var *var,
		char type_identifier)
{
	if (var->conv >= 4 && var->conv <= 9 && var->nu_of_h % 2 == 1
			&& var->nu_of_l == 0 && var->flag % 2 == 0
			&& var->flag / 2 % 2 == 0)
		type_identifier = 5;
	else if ((var->conv >= 4 && var->conv <= 9 && var->nu_of_h != 0
			&& var->nu_of_h % 2 == 0 && var->nu_of_l == 0 && var->flag % 2 == 0
			&& var->flag / 2 % 2 == 0)
			|| (var->conv == 13 && var->nu_of_h == 0 && var->nu_of_l == 0
			&& var->flag % 2 == 0 && var->flag / 2 % 2 == 0))
		type_identifier = 6;
	else if ((var->conv == 14) || (var->conv == 13 && var->nu_of_l % 2 == 1))
		type_identifier = 7;
	else if (var->conv == 1 && var->nu_of_h == 0 && var->nu_of_l == 0
			&& var->flag % 2 == 0 && var->flag / 2 % 2 == 0)
		type_identifier = 8;
	else if ((var->conv == 2) || (var->conv == 1 && var->nu_of_l % 2 == 1))
		type_identifier = 9;
	else if (var->conv == 3)
		type_identifier = 10;
	return (type_identifier);
}

char		*go_to_modulo(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	return (&str[i]);
}

int			is_c_exist(char c, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		is_precision_flag_init(t_fonc *fonc, t_var *var, char *str)
{
	var->prec = 0;
	var->nu_of_h = 0;
	var->nu_of_l = 0;
	var->error = 0;
	var->s_precision = 0;
	var->s_precp = 0;
	fonc->i = 0;
	fonc->tmp = ft_strnew(0);
	fonc->tmp = ft_strdup(str);
	fonc->u = 0;
}

char		*prec_flag_norm_2(t_var *var, t_fonc *fonc)
{
	if (fonc->tmp[fonc->u + 1] != '\0')
	{
		var->moing = 0;
		if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
				&& var->prec / 16 % 2 == 1)
			ft_s_prec(var->s_precision - 1, ' ');
		else if (var->prec / 2 % 2 == 1)
			var->moing = 1;
		else if (var->prec / 8 % 2 == 1)
			ft_s_prec(var->s_precision - 1, '0');
		ft_putchar_printf(fonc->tmp[fonc->u + 1]);
		if (var->moing == 1)
			ft_s_prec(var->s_precision - 1, ' ');
		var->prec = 0;
		return (&fonc->tmp[fonc->u + 1]);
	}
	else
	{
		return (&fonc->tmp[fonc->u + 1]);
		var->prec = 0;
		return (++fonc->tmp);
	}
}
