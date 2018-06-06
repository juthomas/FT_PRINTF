/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:02:28 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/04 14:49:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft.h"
# include "./ft_printf_struct_1.h"
# define CMP_F ft_strcmp_flag
# define CMP_P ft_strcmp_precision
# define DEFAULT "\033[0;m"
# define WHITE "\033[00;01m"
# define BLACK "\033[00;30m"
# define RED "\033[00;31m"
# define GREEN "\033[00;32m"
# define YELLOW "\033[00;33m"
# define BLUE "\033[00;34m"
# define PURPLE "\033[00;35m"
# define CYAN "\033[00;36m"
# define GREY "\033[00;37m"
# define LIGHT_BLACK "\033[00;90m"
# define LIGHT_RED "\033[00;91m"
# define LIGHT_GREEN "\033[00;92m"
# define LIGHT_YELLOW "\033[00;93m"
# define LIGHT_BLUE "\033[00;94m"
# define LIGHT_PURPLE "\033[00;95m"
# define LIGHT_CYAN "\033[00;96m"
# define LIGHT_GREY "\033[00;97m"
# define BACK_WHITE "\033[00;47m"
# define BACK_BLACK "\033[00;40m"
# define BACK_RED "\033[00;41m"
# define BACK_GREEN "\033[00;42m"
# define BACK_YELLOW "\033[00;43m"
# define BACK_BLUE "\033[00;44m"
# define BACK_PURPLE "\033[00;45m"
# define BACK_CYAN "\033[00;46m"
# define BACK_GREY "\033[00;47m"
# define BACK_DEFAULT "\033[0;m"

char				*g_str;
int					g_len;

void			ft_nb_of_c_to_print(char c, int len);
char			*ft_color(char *str);
char			*ft_multiple_base(char *str, va_list *ap);
void			ft_putstr_i_printf(char *str, int i);
void			ft_putstrlen(char *str, int len);
void			ft_s_prec(int len, char c);
int				ft_printf(char *str, ...);
void			ft_fllint_final_conv(t_var *var, long long int type);
void			ft_fullint_final_conv(t_var *var, unsigned long long type);
long long int	ft_casting_time(long long int mod, int conv, t_var *var);
void			ft_fshort_final_conv(t_var *var, short type);
void			ft_fchar_final_conv(t_var *var, short type);
int				ft_fllint_norm_1(t_var *var, long long int type, t_int *st);
void			ft_fllint_norm_2(t_int *st, t_var *var, int *plen, int *nlen);
int				ft_fllint_norm_3(t_var *var, long long int *type);
void			ft_fllint_norm_4(t_var *var, long long int *type);
void			ft_fllint_norm_5(t_var *var, long long int type, int plen,
					int nlen);
void			ft_fllint(long long int mod, t_var *var, int conv);
void			ft_fchar(char type, t_var *var);
void			ft_fchare_norm_1(t_var *var);
void			ft_fchare(char *type, t_var *var);
void			ft_fwchar(wchar_t type, t_var *var);
void			ft_fwchare_norm_1(wchar_t *type, int i, int *len);
int				ft_fwchare_norm_2(int *len, t_var *var, wchar_t *type, int *u);
void			ft_fwchare_norm_3(t_var *var, int *len_prec);
void			ft_fwchare_norm_4(t_var *var);
void			ft_fwchare(wchar_t *type, t_var *var);
void			ft_putnbr_base_long_long_int(long long int nbr, char *base);
void			ft_putnbr_base_unsi_long_long(unsigned long long int nbr,
					char *base);
void			ft_putwchar_printf(wchar_t wc);
void			ft_putwstr_printf(wchar_t const *wstr);
void			ft_putwchar_fd(wchar_t wc, int fd);
void			ft_putwstr_fd(wchar_t const *wstr, int fd);
int				ft_numberlen(char *base, long long int number, t_var *var);
void			ft_convert(va_list *ap, t_var *var, int conv);
void			ft_putwchar_fd(wchar_t wc, int fd);
int				ft_dollard(char *str);
int				is_printf_char(char c);
int				which_preci_flag_1(char *str, va_list *ap, t_var *var, int i);
int				which_preci_flag_2(char *str, va_list *ap, t_var *var, int i);
int				which_preci_flag_2_5(char *str, va_list *ap, t_var *var, int i);
int				which_preci_flag_3(char *str, t_var *var, int i);
int				which_preci_flag_3_5(char *str, t_var *var, int i);
int				which_preci_flag_4(char *str, t_var *var, int i);
void			ft_conversion_1(va_list *ap, t_var *var);
char			ft_conversion_2(t_var *var, char type_identifier);
char			*is_precision_flag(char *str, va_list *ap, t_var *var);
char			*prec_flag_norm_1(char *str, t_var *var, t_fonc *fonc);
char			*prec_flag_norm_2(t_var *var, t_fonc *fonc);
void			ft_putstr_len(char *str, int len);
char			*go_to_modulo(char *str);
void			is_precision_flag_init(t_fonc *fonc, t_var *var, char *str);
void			which_converter(char *str, t_var *var);
void			ft_init_printf(t_var *var, char *str);
void			**tab_params(va_list *op, int dollard_nu);

#endif
