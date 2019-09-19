/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:26:36 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/18 22:18:47 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_o_spec(va_list ap, t_format *form, char **result)
{
	t_datatype	data;

	if (form->type == 'o' || form->type == 'O')
	{
		if (!pashol_nah3(ap, &data, form, result))
		{
			if (form->typesize.l == 2)
			{
				data.ulli = (va_arg(ap, unsigned long long));
				*result = memory_convert(data.ulli, 8);
			}
			else
			{
				data.ui = (va_arg(ap, unsigned int));
				*result = memory_convert(data.ui, 8);
			}
		}
	}
}

void	memory_specs(va_list ap, t_format *form, char **result)
{
	t_datatype data;

	if (form->type == 'x' || form->type == 'X')
	{
		if (!pashol_nah4(ap, &data, form, result))
		{
			if (form->typesize.j)
			{
				data.uli = (va_arg(ap, unsigned long));
				*result = memory_convert(data.uli, 16);
			}
			else
			{
				data.ui = (va_arg(ap, unsigned int));
				*result = memory_convert(data.ui, 16);
			}
		}
	}
	if (form->type == 'p')
	{
		data.z = (va_arg(ap, size_t));
		*result = memory_convert(data.z, 16);
	}
}

void	get_d_spec(va_list ap, t_format *form, char **result)
{
	int			intik;
	t_datatype	data;

	if (form->type == 'd' || form->type == 'i')
	{
		if (!pashol_nah5(ap, &data, form, result))
		{
			if (form->typesize.j == 1)
			{
				data.j = (va_arg(ap, intmax_t));
				*result = ft_itoa_long(data.j);
			}
			else if (form->typesize.z == 1)
			{
				data.z = (va_arg(ap, ssize_t));
				*result = ft_itoa_long(data.z);
			}
			else
			{
				intik = (va_arg(ap, int));
				*result = ft_itoa(intik);
			}
		}
	}
}

void	get_u_spec(va_list ap, t_format *form, char **result)
{
	t_datatype data;

	if (form->type == 'U')
	{
		data.uli = (va_arg(ap, unsigned long));
		*result = ft_itoa_long(data.uli);
	}
	if (form->type == 'u')
	{
		if (!pashol_nah6(ap, &data, form, result))
		{
			if (form->typesize.j == 1)
			{
				data.j = (va_arg(ap, intmax_t));
				*result = ft_itoa_long(data.j);
			}
			else
			{
				data.ui = (va_arg(ap, unsigned int));
				*result = ft_itoa_long(data.ui);
			}
		}
	}
}

char	*get_spec(va_list ap, t_format *form)
{
	char	*result;
	double	nmb_double;
	size_t	p;
	int		i;

	i = 0;
	p = 0;
	result = NULL;
	if (form->type == '%')
	{
		result = malloc(2);
		result[i++] = '%';
		result[i] = '\0';
	}
	huyak(ap, form, &result);
	memory_specs(ap, form, &result);
	get_o_spec(ap, form, &result);
	get_d_spec(ap, form, &result);
	get_u_spec(ap, form, &result);
	if (form->type == 'f')
	{
		nmb_double = (va_arg(ap, double));
		getdbl(nmb_double, *form, &result);
	}
	return (result);
}
