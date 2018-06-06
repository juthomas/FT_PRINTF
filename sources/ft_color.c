/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:19:18 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/28 12:54:21 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_cmp_color(char *str, char *color)
{
	unsigned int	i;

	i = 0;
	while (color[i] != 0 && str[i] != 0)
	{
		if ((str[i] == '_' && color[i] == '_') || (str[i] == color[i])
			|| (str[i] - 32 == color[i] && color[i] != '}'))
			i++;
		else
			return (0);
	}
	if (str[i] != '\0' && str[i] == '}')
		return (1);
	return (0);
}

static int		find_color_3(char *str)
{
	if (ft_cmp_color(str, "BACK_WHITE"))
		ft_putstr_printf(BACK_WHITE);
	else if (ft_cmp_color(str, "BACK_BLACK"))
		ft_putstr_printf(BACK_BLACK);
	else if (ft_cmp_color(str, "BACK_RED"))
		ft_putstr_printf(BACK_RED);
	else if (ft_cmp_color(str, "BACK_GREEN"))
		ft_putstr_printf(BACK_GREEN);
	else if (ft_cmp_color(str, "BACK_YELLOW"))
		ft_putstr_printf(BACK_YELLOW);
	else if (ft_cmp_color(str, "BACK_BLUE"))
		ft_putstr_printf(BACK_BLUE);
	else if (ft_cmp_color(str, "BACK_PURPLE"))
		ft_putstr_printf(BACK_PURPLE);
	else if (ft_cmp_color(str, "BACK_CYAN"))
		ft_putstr_printf(BACK_CYAN);
	else if (ft_cmp_color(str, "BACK_GREY"))
		ft_putstr_printf(BACK_GREY);
	else if (ft_cmp_color(str, "BACK_DEFAULT"))
		ft_putstr_printf(BACK_DEFAULT);
	else
		return (0);
	return (1);
}

static int		find_color_2(char *str)
{
	if (ft_cmp_color(str, "LIGHT_BLACK"))
		ft_putstr_printf(LIGHT_BLACK);
	else if (ft_cmp_color(str, "LIGHT_RED"))
		ft_putstr_printf(LIGHT_RED);
	else if (ft_cmp_color(str, "LIGHT_GREEN"))
		ft_putstr_printf(LIGHT_GREEN);
	else if (ft_cmp_color(str, "LIGHT_YELLOW"))
		ft_putstr_printf(LIGHT_YELLOW);
	else if (ft_cmp_color(str, "LIGHT_BLUE"))
		ft_putstr_printf(LIGHT_BLUE);
	else if (ft_cmp_color(str, "LIGHT_PURPLE"))
		ft_putstr_printf(LIGHT_PURPLE);
	else if (ft_cmp_color(str, "LIGHT_CYAN"))
		ft_putstr_printf(LIGHT_CYAN);
	else if (ft_cmp_color(str, "LIGHT_GREY"))
		ft_putstr_printf(LIGHT_GREY);
	else
		return (find_color_3(str));
	return (1);
}

static int		find_color_1(char *str)
{
	if (ft_cmp_color(str, "DEFAULT") || ft_cmp_color(str, "EOC"))
		ft_putstr_printf(DEFAULT);
	else if (ft_cmp_color(str, "WHITE"))
		ft_putstr_printf(WHITE);
	else if (ft_cmp_color(str, "BLACK"))
		ft_putstr_printf(BLACK);
	else if (ft_cmp_color(str, "RED"))
		ft_putstr_printf(RED);
	else if (ft_cmp_color(str, "GREEN"))
		ft_putstr_printf(GREEN);
	else if (ft_cmp_color(str, "YELLOW"))
		ft_putstr_printf(YELLOW);
	else if (ft_cmp_color(str, "BLUE"))
		ft_putstr_printf(BLUE);
	else if (ft_cmp_color(str, "PURPLE"))
		ft_putstr_printf(PURPLE);
	else if (ft_cmp_color(str, "CYAN"))
		ft_putstr_printf(CYAN);
	else
		return (find_color_2(str));
	return (1);
}

char			*ft_color(char *str)
{
	unsigned char	i;

	i = 0;
	if (find_color_1(str + 1) == 0)
	{
		ft_putchar_printf('{');
		return (&str[0]);
	}
	else
	{
		while (str[i] != '\0' && str[i] != '}')
			i++;
		if (str[i] == '}')
			return (&str[i]);
	}
	ft_putchar_printf('{');
	return (&str[0]);
}
