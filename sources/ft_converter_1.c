/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:08:35 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:40:37 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_fwchare(wchar_t *type, t_var *var)
{
	int				len;
	unsigned int	i;
	int				u;
	int				len_prec;

	i = 0;
	len = 0;
	var->moing = 0;
	if (type != NULL)
	{
		ft_fwchare_norm_1(type, i, &len);
		len_prec = len;
		if (var->prec / 256 % 2 == 1 && len > var->s_precp && var->s_precp >= 0)
			len_prec = ft_fwchare_norm_2(&len, var, type, &u);
		ft_fwchare_norm_3(var, &len_prec);
	}
	if (type == 0)
		ft_fwchare_norm_4(var);
	else
		ft_putwstr_len_printf(type, len);
	if (var->moing == 1)
		ft_s_prec(var->s_precision - len_prec, ' ');
	var->prec = 0;
}

void		ft_get_type(va_list *ap, t_var *var, int conv)
{
	if (var->conv == 13 && var->nu_of_l % 2 == 0)
		ft_fchar(va_arg(*ap, int), var);
	else if (conv == 3 || conv == 2 || conv == 1 || conv == 5 || conv == 6
			|| conv == 4 || conv == 10)
		ft_fllint(va_arg(*ap, long long int), var, conv);
	else if (conv == 8)
		ft_fchare(va_arg(*ap, char*), var);
	else if (conv == 7)
		ft_fwchar(va_arg(*ap, wchar_t), var);
	else if (conv == 9)
		ft_fwchare(va_arg(*ap, wchar_t*), var);
}

void		ft_give_type(t_var *var, int conv)
{
	if (var->conv == 13 && var->nu_of_l % 2 == 0)
		ft_fchar((int)var->params[var->which_dollard], var);
	else if (conv == 3 || conv == 2 || conv == 1 || conv == 5 || conv == 6
			|| conv == 4 || conv == 10)
		ft_fllint((long long int)var->params[var->which_dollard]
				, var, conv);
	else if (conv == 8)
		ft_fchare((char*)var->params[var->which_dollard], var);
	else if (conv == 7)
		ft_fwchar((wchar_t)var->params[var->which_dollard], var);
	else if (conv == 9)
		ft_fwchare((wchar_t*)var->params[var->which_dollard], var);
}

void		ft_convert(va_list *ap, t_var *var, int conv)
{
	if (var->prec / 128 % 2 != 1)
		ft_get_type(ap, var, conv);
	else
		ft_give_type(var, conv);
}
