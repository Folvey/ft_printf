/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perviy_poh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:21:47 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 15:10:04 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pashol_nah(const char **format, t_format *form)
{
	if (**format == 'l')
	{
		if (form->typesize.l < 2)
			form->typesize.l = 1;
		(*format)++;
		if (**format == 'l')
		{
			form->typesize.l = 2;
			(*format)++;
		}
	}
	if (**format == 'h')
	{
		if (form->typesize.h < 2)
			form->typesize.h = 1;
		(*format)++;
		if (**format == 'h')
		{
			form->typesize.h = 2;
			(*format)++;
		}
	}
}

void	pashol_nah2(const char **format, t_format *form)
{
	if (**format == 'L')
	{
		form->typesize.l_uppercase = 1;
		(*format)++;
	}
	if (**format == 'j')
	{
		form->typesize.j = 1;
		(*format)++;
	}
	if (**format == 'z')
	{
		form->typesize.z = 1;
		(*format)++;
	}
	if (**format == 't')
	{
		form->typesize.z = 1;
		(*format)++;
	}
}

int		pashol_nah3(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.h == 1 && ++flag)
	{
		data->ushortik = (va_arg(ap, int));
		*result = memory_convert(data->ushortik, 8);
	}
	else if (form->typesize.h == 2 && ++flag)
	{
		data->uschar = (unsigned char)va_arg(ap, long);
		*result = memory_convert(data->uschar, 8);
	}
	else if (form->typesize.l == 1 && ++flag)
	{
		data->ulli = (va_arg(ap, unsigned long));
		*result = memory_convert(data->ulli, 8);
	}
	return (flag);
}

int		pashol_nah4(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.h == 1 && ++flag)
	{
		data->ushortik = (va_arg(ap, int));
		*result = memory_convert(data->ushortik, 16);
	}
	else if (form->typesize.h == 2 && ++flag)
	{
		data->uschar = (va_arg(ap, int));
		*result = memory_convert(data->uschar, 16);
	}
	else if (form->typesize.l == 1 && ++flag)
	{
		data->uli = (va_arg(ap, unsigned long int));
		*result = memory_convert(data->uli, 16);
	}
	else if (form->typesize.l == 2 && ++flag)
	{
		data->ull = (va_arg(ap, unsigned long long));
		*result = memory_convert(data->ull, 16);
	}
	return (flag);
}

int		pashol_nah5(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.h == 1 && ++flag)
	{
		data->shortik = (va_arg(ap, int));
		*result = ft_itoa(data->shortik);
	}
	else if (form->typesize.h == 2 && ++flag)
	{
		data->schar = (va_arg(ap, int));
		*result = ft_itoa(data->schar);
	}
	else
		flag = prosto_nah2(ap, data, form, result);
	return (flag);
}
