/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosto_poh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:07:49 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 15:10:38 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	prosto_nah(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.l == 2 && ++flag)
	{
		data->ulli = (va_arg(ap, unsigned long long int));
		*result = ft_itoa_uns_long(data->ulli);
	}
	else if (form->typesize.l == 1 && ++flag)
	{
		data->uli = (va_arg(ap, unsigned long int));
		*result = ft_itoa_uns_long(data->uli);
	}
	return (flag);
}

int	prosto_nah2(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.l == 1 && ++flag)
	{
		data->l = (va_arg(ap, long));
		*result = ft_itoa_long(data->l);
	}
	else if (form->typesize.l == 2 && ++flag)
	{
		data->ll = (va_arg(ap, long long));
		*result = ft_itoa_long(data->ll);
	}
	return (flag);
}

int	prosto_nah3(va_list ap, t_datatype *data, t_format *form, char **result)
{
	int flag;

	flag = 0;
	if (form->typesize.z == 1 && ++flag)
	{
		data->z = (va_arg(ap, size_t));
		*result = ft_itoa_uns_long(data->z);
	}
	else if (form->typesize.h == 2 && ++flag)
	{
		data->uschar = (va_arg(ap, int));
		*result = ft_itoa_uns_long(data->uschar);
	}
	return (flag);
}
