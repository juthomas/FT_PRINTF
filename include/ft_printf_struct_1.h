/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_1.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:01:28 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:41:45 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_1_H
# define FT_PRINTF_STRUCT_1_H
# include "ft_printf_struct_2.h"

typedef struct		s_var
{
	int				i;
	char			error;
	int				len;
	char			negativ;
	char			moing;
	void			**params;
	unsigned int	beg;
	unsigned int	end;
	short			prec;
	char			conv;
	int				s_precision;
	int				s_precp;
	int				len_of_ret;
	int				flag;
	int				nu_of_h;
	int				nu_of_l;
	int				which_dollard;
	int				dollard_nu;
}					t_var;
#endif
