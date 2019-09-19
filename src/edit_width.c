/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:13:41 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 14:56:06 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_width(char **stroka, t_format *form)
{
	if (form->flag.minus)
	{
		if (form->flag.zero)
			edit_width_minus(stroka, form, '0');
		edit_width_minus(stroka, form, ' ');
	}
	else
	{
		if (form->flag.zero)
			edit_width_basic(stroka, form, '0');
		edit_width_basic(stroka, form, ' ');
	}
}

int		skip_signs(char **stroka, char *str_edited, t_format *form)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (form->flag.zero && (form->type == 'd' || form->type == 'i')
			&& (*stroka)[i] == '-')
	{
		str_edited[j++] = '-';
		i++;
	}
	if (form->flag.zero && (form->type == 'd' || form->type == 'i')
			&& (*stroka)[i] == '+')
	{
		str_edited[j++] = '+';
		i++;
	}
	if (form->flag.zero && (form->type == 'd' || form->type == 'i')
			&& (*stroka)[i] == ' ')
	{
		str_edited[j++] = ' ';
		i++;
	}
	return (i);
}

void	ft_shift(int shift, int *i, int *j, int *strlen)
{
	i += shift;
	j += shift;
	strlen += shift;
}

void	edit_width_basic(char **stroka, t_format *form, char sign)
{
	t_norm_h	h;

	h = new_init(0, 0, 0);
	h.strlen = (int)ft_strlen(*stroka);
	if (!form->width || form->width <= h.strlen)
		return ;
	h.str_edited = malloc(form->width + 1);
	h.strlen = form->width - h.strlen;
	if (skip_signs(stroka, h.str_edited, form))
	{
		h.shift = skip_signs(stroka, h.str_edited, form);
		h.i += h.shift;
		h.j += h.shift;
		h.strlen += h.shift;
	}
	while (h.j < h.strlen)
		if (form->precision < 0 || form->type == 'f')
			h.str_edited[h.j++] = sign;
		else
			h.str_edited[h.j++] = ' ';
	while ((*stroka)[h.i])
		h.str_edited[h.j++] = (*stroka)[h.i++];
	h.str_edited[h.j] = '\0';
	reassign_string(stroka, h.str_edited);
}

void	edit_width_minus(char **stroka, t_format *form, char sign)
{
	char	*str_edited;
	int		strlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_edited = NULL;
	strlen = (int)ft_strlen(*stroka);
	if (!form->width || form->width <= strlen)
		return ;
	str_edited = malloc(form->width + 1);
	strlen = form->width - strlen;
	while ((*stroka)[i])
		str_edited[j++] = (*stroka)[i++];
	while (j < form->width)
	{
		if (sign == '0' && form->precision < 0)
			str_edited[j++] = sign;
		else
			str_edited[j++] = ' ';
	}
	str_edited[j] = '\0';
	reassign_string(stroka, str_edited);
}
