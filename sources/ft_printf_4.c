/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:50 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 13:38:10 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		which_preci_flag_3_5(char *str, t_var *var, int i)
{
	int		u;
	int		cpy;

	if (str[i] == '-')
	{
		var->prec = (var->prec / 2 % 2 == 0) ? var->prec + 2 : var->prec;
		i++;
	}
	u = i;
	while (str[u] >= '0' && str[u] <= '9')
		u++;
	if (str[u] == '$')
		return (u);
	var->prec = (var->prec / 16 % 2 == 0) ? var->prec + 16 : var->prec;
	var->s_precision = ft_atoi(&str[i]);
	cpy = var->s_precision;
	while (cpy / 10 != 0)
	{
		cpy = cpy / 10;
		i++;
	}
	return (i);
}

int		which_preci_flag_4(char *str, t_var *var, int i)
{
	int		u;

	if (str[i] == '$')
	{
		u = i - 1;
		while (str[u] >= '0' && str[u] <= '9')
			u--;
		if (str[u + 1] == '$')
			var->error = 1;
		else if (ft_atoi(&str[u + 1]) > 0)
		{
			var->prec = (var->prec / 128 % 2 == 0) ? var->prec + 128 :
				var->prec;
			var->which_dollard = ft_atoi(&str[u + 1]) - 1;
		}
		else
			var->error = 1;
	}
	return (i + 1);
}

void	which_converter(char *str, t_var *var)
{
	var->conv = 0;
	var->conv = (*str == 's') ? 1 : var->conv;
	var->conv = (*str == 'S') ? 2 : var->conv;
	var->conv = (*str == 'p') ? 3 : var->conv;
	var->conv = (*str == 'd') ? 4 : var->conv;
	var->conv = (*str == 'i') ? 5 : var->conv;
	var->conv = (*str == 'o') ? 6 : var->conv;
	var->conv = (*str == 'u') ? 7 : var->conv;
	var->conv = (*str == 'x') ? 8 : var->conv;
	var->conv = (*str == 'X') ? 9 : var->conv;
	var->conv = (*str == 'D') ? 10 : var->conv;
	var->conv = (*str == 'O') ? 11 : var->conv;
	var->conv = (*str == 'U') ? 12 : var->conv;
	var->conv = (*str == 'c') ? 13 : var->conv;
	var->conv = (*str == 'C') ? 14 : var->conv;
}

char	is_one_of_str(char c, char *str)
{
	unsigned int	i;
	char			ret;

	ret = 0;
	i = 0;
	while (str[i] != '\0' && ret == 0)
	{
		if (str[i] == c)
			ret = 1;
		i++;
	}
	return (ret);
}

void	ft_conversion_1(va_list *ap, t_var *var)
{
	char	type_identifier;

	type_identifier = 0;
	if (var->conv >= 4 && var->conv <= 9 && var->nu_of_h == 0
			&& var->nu_of_l == 0 && var->flag % 2 == 0
			&& var->flag / 2 % 2 == 0)
		type_identifier = 1;
	else if ((var->conv >= 4 && var->conv <= 9
			&& var->nu_of_l % 2 != 0 && var->flag % 2 == 0
			&& var->flag / 2 % 2 == 0) || (var->conv >= 10 && var->conv <= 12)
			|| (var->conv >= 4 && var->conv <= 9
			&& (var->flag % 2 == 1 || var->flag / 2 % 2 == 1)))
		type_identifier = 2;
	else if ((var->conv >= 4 && var->conv <= 9 && var->nu_of_h == 0
			&& var->nu_of_l != 0 && var->nu_of_l % 2 == 0
			&& var->flag % 2 == 0 && var->flag / 2 % 2 == 0))
		type_identifier = 3;
	else if (var->conv >= 4 && var->conv <= 9 && var->nu_of_h == 0
			&& var->nu_of_l == 0 && var->flag % 2 == 1
			&& var->flag / 2 % 2 == 0)
		type_identifier = 4;
	else
		type_identifier = ft_conversion_2(var, type_identifier);
	ft_convert(ap, var, type_identifier);
}
