/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:04:48 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:53:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_loop(t_var *var, char *str, va_list *ap)
{
	while (str[var->i] != '\0')
	{
		if (str[var->i] == '%')
		{
			str = is_precision_flag(&str[var->i], ap, var);
			var->i = 0;
			var->negativ = 0;
			var->s_precision = 0;
			var->s_precp = 0;
		}
		else if (str[var->i] == '{')
		{
			str = ft_color(&str[var->i]);
			var->i = 0;
		}
		else if (str[var->i] == '#')
		{
			str = ft_multiple_base(&str[var->i], ap);
			var->i = 0;
		}
		else
			ft_putchar_printf(str[var->i]);
		var->i++;
	}
}

int		ft_printf(char *rstr, ...)
{
	va_list		ap;
	va_list		op;
	t_var		*var;
	char		*str;

	var = (t_var*)malloc(sizeof(*var));
	str = ft_strdup(rstr);
	if (str[0] == '\0' || (str[0] == '%' && str[1] == '\n'))
		return (0);
	ft_init_printf(var, str);
	va_start(ap, rstr);
	va_start(op, rstr);
	if ((var->dollard_nu = ft_dollard(str)) != 0)
		var->params = tab_params(&op, var->dollard_nu);
	ft_printf_loop(var, str, &ap);
	va_end(op);
	va_end(ap);
	ft_putstr_len(g_str, g_len);
	var->i = ft_strlen(g_str);
	ft_strdel(&g_str);
	free(var);
	return (g_len);
}
