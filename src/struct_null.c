/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:10:44 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 22:10:58 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flag_null(void)
{
	t_flags	a;

	a.sharp = 0;
	a.minus = 0;
	a.plus = 0;
	a.space = 0;
	a.zero = 0;
	return (a);
}

t_typesize	typesize_null(void)
{
	t_typesize a;

	a.h = 0;
	a.j = 0;
	a.l = 0;
	a.l_uppercase = 0;
	a.z = 0;
	return (a);
}

void		format_null(t_format *form)
{
	int i;

	i = 0;
	form->flag = flag_null();
	form->typesize = typesize_null();
	form->precision = -1;
	form->size = 0;
	form->type = 0;
	form->width = 0;
	form->is_negative = 0;
	form->is_plus = 0;
}
