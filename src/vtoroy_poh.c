/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtoroy_poh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:08:22 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 15:11:52 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			pashol_nah6(va_list ap, t_datatype *data,
		t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.h == 1 && ++flag)
	{
		data->ushortik = (va_arg(ap, int));
		*result = ft_itoa_uns_long(data->ushortik);
	}
	else if ((flag = prosto_nah3(ap, data, form, result)))
		;
	else if (form->type == 'U')
	{
		data->uli = (va_arg(ap, unsigned long));
		*result = ft_itoa_long(data->uli);
	}
	else
		flag = prosto_nah(ap, data, form, result);
	return (flag);
}

int			verify_width(const char **format, t_format *form)
{
	int i;

	i = 0;
	if (**format >= '1' && **format <= '9')
	{
		form->width = ft_ati(format);
		i++;
	}
	return (i);
}

t_norm_h	new_init(int i, int j, int sh)
{
	t_norm_h h;

	h.i = i;
	h.j = j;
	h.shift = sh;
	h.str_edited = NULL;
	return (h);
}

void		edit_precision_s(char **stroka, t_format *form)
{
	int		i;
	char	*str_edited;

	i = 0;
	if (form->precision < 0 || *stroka == NULL)
	{
		return ;
	}
	str_edited = malloc(form->precision + 1);
	while (i < form->precision)
	{
		str_edited[i] = (*stroka)[i];
		i++;
	}
	str_edited[i] = '\0';
	reassign_string(stroka, str_edited);
}
