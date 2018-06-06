/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_3.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:38:30 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:41:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_3_H
# define FT_PRINTF_STRUCT_3_H
# include <stdint.h>

typedef struct		s_type
{
	int				t_int;
	long int		t_long_int;
	long long int	t_long_long_int;
	intmax_t		t_intmax_t;
	short			t_short;
	char			t_char;
	char			*t_char_p;
	int				t_wint_t;
	wchar_t			*t_wchar_tx;
	void			*t_void_p;
}					t_type;
#endif
