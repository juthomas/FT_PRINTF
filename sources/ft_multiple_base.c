/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:43:22 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 12:48:23 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ft_get_char_base(int base)
{
	char			*char_base;
	char			*refer_base;
	int				i;

	i = 0;
	char_base = (char*)malloc(base + 1);
	refer_base = ft_strdup("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0");
	while (i < base)
	{
		char_base[i] = refer_base[i];
		i++;
	}
	char_base[i] = '\0';
	return (char_base);
}

static void		ft_convert_multiple_base(int base, long long int number)
{
	char	*char_base;

	char_base = ft_get_char_base(base);
	ft_putnbr_base_long_long_int(number, char_base);
	free(char_base);
}

static int		ft_get_base(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[0] > '9' || str[0] < '0')
		return (0);
	return (ft_atoi(str));
}

char			*ft_multiple_base(char *str, va_list *ap)
{
	unsigned char	i;

	i = 0;
	if (ft_get_base(str + 1) <= 1 || ft_get_base(str + 1) > 36)
	{
		ft_putchar_printf('#');
		return (&str[0]);
	}
	else
	{
		ft_convert_multiple_base(ft_get_base(str + 1),
				va_arg(*ap, long long int));
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		return (&str[i - 1]);
	}
	ft_putchar_printf('#');
	return (&str[0]);
}
