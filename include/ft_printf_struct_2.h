/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_2.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:20 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:41:59 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_2_H
# define FT_PRINTF_STRUCT_2_H
# include <stdint.h>
# include "ft_printf_struct_3.h"

typedef struct		s_int
{
	char			sign;
	int				len;
	int				cpylen;
	int				nlen;
	int				plen;
}					t_int;

typedef struct		s_conv
{
	long long int	type;
	char			sign;
	int				len;
	int				cpylen;

}					t_conv;

typedef struct		s_fonc
{
	int				i;
	char			*tmp;
	int				u;
	char			*nstr;
}					t_fonc;
#endif
