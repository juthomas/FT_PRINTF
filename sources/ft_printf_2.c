/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:58:01 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 12:58:51 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_putstr_ret(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (1);
}

int		is_dioux(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		is_signed(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

int		is_unsigned(char c)
{
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		ft_strcmp_flag(char *s1, char *s2, int type, t_var *var)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
		i++;
	if (s2[i] == '\0' && s2[i - 1] == s1[i - 1])
	{
		if (type == 0)
		{
			var->len_of_ret = i;
			return (1);
		}
		else if (type == 1 && is_signed(s1[i]))
		{
			var->len_of_ret = i + 1;
			return (1);
		}
		else if (type == 2 && is_unsigned(s2[i]))
		{
			var->len_of_ret = i + 1;
			return (1);
		}
		return (0);
	}
	return (0);
}
