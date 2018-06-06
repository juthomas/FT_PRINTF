/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:59:11 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 13:00:31 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		is_printf_char(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '#' || c == '-'
			|| c == '+' || (c >= '0' && c <= '9') || c == '*' || c == ' '
			|| c == '$' || c == '.')
		return (1);
	else if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (2);
	else
		return (0);
}

int		which_preci_flag_1(char *str, va_list *ap, t_var *var, int i)
{
	if (str[i] == 'h')
		var->nu_of_h++;
	else if (str[i] == 'l')
		var->nu_of_l++;
	else if (str[i] == 'j')
		var->flag = (var->flag % 2 == 0) ? var->flag + 1 : var->flag;
	else if (str[i] == 'z')
		var->flag = (var->flag / 2 == 0) ? var->flag + 2 : var->flag;
	else if (str[i] == '#')
		var->prec = (var->prec % 2 == 0) ? var->prec + 1 : var->prec;
	else if (str[i] == '-')
		var->prec = (var->prec / 2 % 2 == 0) ? var->prec + 2 : var->prec;
	else if (str[i] == '+')
		var->prec = (var->prec / 4 % 2 == 0) ? var->prec + 4 : var->prec;
	else
		return (which_preci_flag_2(str, ap, var, i));
	return (i + 1);
}

int		which_preci_flag_2(char *str, va_list *ap, t_var *var, int i)
{
	if (str[i] == '*')
	{
		var->prec = (var->prec / 16 % 2 == 0) ? var->prec + 16 : var->prec;
		var->s_precision = va_arg(*ap, int);
		if (var->s_precision < 0)
		{
			var->s_precision = -var->s_precision;
			var->prec = (var->prec / 2 % 2 == 0) ? var->prec + 2 : var->prec;
		}
	}
	else if (str[i] == ' ')
		var->prec = (var->prec / 64 % 2 == 0) ? var->prec + 64 : var->prec;
	else if (str[i] == '.')
	{
		var->prec = (var->prec / 256 % 2 == 0) ? var->prec + 256 : var->prec;
		var->s_precp = 0;
		i = which_preci_flag_2_5(str, ap, var, i);
	}
	else
		return (which_preci_flag_3(str, var, i));
	return (i + 1);
}

int		which_preci_flag_2_5(char *str, va_list *ap, t_var *var, int i)
{
	int		tab[2];

	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i = i + 1;
		tab[0] = 1;
		while (str[tab[0]] >= '0' && str[tab[0]] <= '9')
			tab[0]++;
		tab[1] = ft_atoi(&str[i]);
		var->s_precp = tab[1];
		while (tab[1] / 10 != 0)
		{
			tab[1] = tab[1] / 10;
			i++;
		}
	}
	else if (str[i + 1] == '*')
	{
		var->prec = (var->prec / 256 % 2 == 0) ? var->prec + 256 : var->prec;
		var->s_precp = va_arg(*ap, int);
		if (var->s_precp < 0)
			var->prec = var->prec / 512 % 2 == 0 ? var->prec + 512 : var->prec;
		i++;
	}
	return (i);
}

int		which_preci_flag_3(char *str, t_var *var, int i)
{
	int		u;

	if ((str[i] >= '1' && str[i] <= '9') || str[i] == '-')
		i = which_preci_flag_3_5(str, var, i);
	else if (str[i] == '0')
	{
		u = i;
		while (str[u] >= '0' && str[u] <= '9')
			u++;
		if (str[u] == '$')
			return (u);
		var->prec = (var->prec / 8 % 2 == 0) ? var->prec + 8 : var->prec;
	}
	else
		return (which_preci_flag_4(str, var, i));
	return (i + 1);
}
