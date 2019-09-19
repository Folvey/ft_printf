/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:03:54 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:04:14 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_precision_basic(char **stroka, t_format *form)
{
	int		i;
	int		j;
	int		strlen;
	char	*str_edited;

	i = 0;
	j = 0;
	strlen = (int)ft_strlen(*stroka);
	if (!form->precision || form->precision <= strlen)
		return ;
	if (form->is_negative)
		str_edited = malloc(form->precision + 2);
	else
		str_edited = malloc(form->precision + 1);
	while (j < form->precision - strlen)
	{
		str_edited[j++] = '0';
	}
	while (i < strlen)
		str_edited[j++] = (*stroka)[i++];
	str_edited[j] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_precision(char **stroka, t_format *form)
{
	edit_precision_basic(stroka, form);
}
