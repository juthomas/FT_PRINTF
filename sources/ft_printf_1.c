/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:16 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 12:56:35 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr_i_printf(char *str, int i)
{
	int u;

	u = 0;
	while (str[u] != '\0' && u < i)
		ft_putchar_printf(str[u++]);
}

void	ft_putstr_len(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
		ft_putchar(str[i++]);
}

void	ft_putstr_error(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

int		ft_baselen(char *str)
{
	int		ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int		ft_numberlen(char *base, long long int number, t_var *var)
{
	int			len;
	int			ibase;

	var->negativ = 0;
	ibase = ft_baselen(base);
	len = 0;
	if (number < 0)
	{
		number = -number;
		var->negativ = 1;
	}
	while (number / ibase != 0)
	{
		len++;
		number = number / ibase;
	}
	if ((var->prec % 2 == 1 && (var->conv == 8 || var->conv == 9))
			|| var->conv == 3)
		len = len + 2;
	return (len + 1);
}
