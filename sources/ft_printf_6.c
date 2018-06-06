/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:05:38 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:49:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*prec_flag_norm_1(char *str, t_var *var, t_fonc *fonc)
{
	if (str[0] == '%')
	{
		var->moing = 0;
		if (var->prec / 2 % 2 != 1 && var->prec / 8 % 2 != 1
				&& var->prec / 16 % 2 == 1)
			ft_s_prec(var->s_precision - 1, ' ');
		else if (var->prec / 2 % 2 == 1)
			var->moing = 1;
		else if (var->prec / 8 % 2 == 1)
			ft_s_prec(var->s_precision - 1, '0');
		ft_putchar_printf('%');
		if (var->moing == 1)
			ft_s_prec(var->s_precision - 1, ' ');
		var->prec = 0;
		return (go_to_modulo(fonc->tmp + 1));
	}
	else
		return (prec_flag_norm_2(var, fonc));
}

char	*is_precision_flag(char *str, va_list *ap, t_var *var)
{
	t_fonc			fonc;

	is_precision_flag_init(&fonc, var, str);
	str++;
	while (is_printf_char(str[fonc.u]) == 1 && var->error == 0)
		fonc.u = which_preci_flag_1(str, ap, var, fonc.u);
	fonc.nstr = ft_strnew(0);
	fonc.nstr = ft_strcpy(fonc.nstr, &str[fonc.u]);
	str = &str[fonc.u];
	if (var->error != 0)
		return (str);
	if (is_printf_char(str[fonc.i]) == 2)
	{
		which_converter(str, var);
		if (var->prec / 8 % 2 == 1 && var->prec / 256 % 2 == 1 &&
				var->prec / 512 % 2 == 0 && (var->conv != 1
				&& var->conv != 2 && var->conv != 13 && var->conv != 14))
			var->prec -= 8;
		ft_conversion_1(ap, var);
		return (str);
	}
	else
		return (prec_flag_norm_1(str, var, &fonc));
}

void	**tab_params(va_list *op, int dollard_nu)
{
	void	**params;
	int		i;

	i = 0;
	if ((params = (void**)malloc(sizeof(void*) * dollard_nu)) == 0)
		return (NULL);
	while (i < dollard_nu)
	{
		params[i] = va_arg(*op, void *);
		i++;
	}
	return (params);
}

void	ft_init_printf(t_var *var, char *str)
{
	g_len = 0;
	str = ft_strnew(0);
	var->len = 0;
	var->i = 0;
	var->flag = 0;
	var->nu_of_h = 0;
	var->nu_of_l = 0;
	g_str = ft_strnew(0);
}
