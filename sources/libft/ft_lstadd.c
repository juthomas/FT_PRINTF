/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:27:13 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:02:32 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	t_list	*old;

	old = *alst;
	*alst = elem;
	elem->next = old;
}
