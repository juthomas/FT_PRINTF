/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:39 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:40:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			ft_nb_of_c_to_print(char c, int len)
{
	while (len-- > 0)
		ft_putchar_printf(c);
}

void			ft_s_prec(int len, char c)
{
	while (len-- > 0)
		ft_putchar_printf(c);
}

void			ft_fllint_final_conv(t_var *var, long long int type)
{
	if (var->conv == 4 || var->conv == 5 || var->conv == 7 || var->conv == 10
			|| var->conv == 12)
		ft_putnbr_base_long_long_int(type, "0123456789");
	else if (var->conv == 6 || var->conv == 11)
		ft_putnbr_base_long_long_int(type, "01234567");
	else if (var->conv == 8 || var->conv == 3)
		ft_putnbr_base_long_long_int(type, "0123456789abcdef");
	else if (var->conv == 9)
		ft_putnbr_base_long_long_int(type, "0123456789ABCDEF");
}

void			ft_fullint_final_conv(t_var *var, unsigned long long int type)
{
	if (var->conv == 4 || var->conv == 5 || var->conv == 7 || var->conv == 10
			|| var->conv == 12)
		ft_putnbr_base_unsi_long_long(type, "0123456789");
	else if (var->conv == 6 || var->conv == 11)
		ft_putnbr_base_unsi_long_long(type, "01234567");
	else if (var->conv == 8 || var->conv == 3)
		ft_putnbr_base_unsi_long_long(type, "0123456789abcdef");
	else if (var->conv == 9)
		ft_putnbr_base_unsi_long_long(type, "0123456789ABCDEF");
}

long long int	ft_casting_time(long long int mod, int conv, t_var *var)
{
	long long int	type;

	type = 0;
	if (conv == 1 && (var->conv == 4 || var->conv == 5 || var->conv == 10))
		type = (int)mod;
	else if (conv == 2 && (var->conv == 4 || var->conv == 5 || var->conv == 10))
		type = (long int)mod;
	else if ((conv == 3 || conv == 4) && (var->conv == 4 || var->conv == 5
				|| var->conv == 10))
		type = (long long int)mod;
	else if (conv == 5 && (var->conv == 4 || var->conv == 5 || var->conv == 10))
		type = (short)mod;
	else if (conv == 6 && (var->conv == 4 || var->conv == 5 || var->conv == 10))
		type = (char)mod;
	else if (conv == 1)
		type = (unsigned int)mod;
	else if (conv == 2)
		type = (unsigned long int)mod;
	else if (conv == 3 || conv == 4 || conv == 10)
		type = (unsigned long long int)mod;
	else if (conv == 5)
		type = (unsigned short)mod;
	else if (conv == 6)
		type = (unsigned char)mod;
	return (type);
}
