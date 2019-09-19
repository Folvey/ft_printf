/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:14:42 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:15:17 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	safely_typesizes(t_format *form)
{
	if (form->typesize.l > 0)
	{
		form->typesize.h = 0;
	}
}

void	safely_flags(t_format *form)
{
	if (form->type == 'd' || form->type == 'i')
		form->flag.sharp = 0;
	if (form->type == 'o' || form->type == 'x' || form->type == 'X')
	{
		form->flag.space = 0;
		form->flag.plus = 0;
	}
	if (form->type == 'u')
	{
		form->flag.sharp = 0;
		form->flag.space = 0;
		form->flag.plus = 0;
	}
	if (form->type == 'p' || form->type == 'c' || form->type == '%')
	{
		form->flag.sharp = 0;
		form->flag.space = 0;
		form->flag.zero = 0;
		form->flag.plus = 0;
		form->precision = -1;
	}
	safely_typesizes(form);
}

void	editor(char **stroka, t_format *form)
{
	safely_flags(form);
	select_editors(stroka, form);
}

void	place_sharp(char **stroka, t_format *form)
{
	char *str_edited;

	if (form->type == 'x' || form->type == 'X')
	{
		if (form->flag.zero)
			form->width -= 2;
		else
		{
			if (ft_strcmp(*stroka, "0"))
			{
				str_edited = ft_strjoin("0x", *stroka);
				reassign_string(stroka, str_edited);
			}
		}
	}
}

void	edit_output(char **stroka, t_format *form)
{
	edit_flags(stroka, form);
	ft_is_signs(stroka, form);
	edit_precision(stroka, form);
	edit_signs(stroka, form);
	edit_width(stroka, form);
}
