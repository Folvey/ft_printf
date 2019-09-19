/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:25:47 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 14:43:47 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verify_flags(const char **format, t_format *form)
{
	int i;

	i = 0;
	while (**format == '-' || **format == '+' || **format == ' '
			|| **format == '#' || **format == '0')
	{
		if (**format == '0')
			form->flag.zero = 1;
		if (**format == '-')
			form->flag.minus = 1;
		if (**format == '+')
			form->flag.plus = 1;
		if (**format == '#')
			form->flag.sharp = 1;
		if (**format == ' ')
			form->flag.space = 1;
		(*format)++;
		i++;
	}
	if (form->flag.plus)
		form->flag.space = 0;
	if (form->flag.minus)
		form->flag.zero = 0;
	return (i);
}

int	verify_precision(const char **format, t_format *form)
{
	int i;

	i = 0;
	if (**format == '.')
	{
		(*format)++;
		form->precision = ft_ati(format);
		i++;
	}
	return (i);
}

int	verify_type(const char **format, t_format *form)
{
	char	*types_stock;
	char	*types_stock_save;
	int		i;

	i = 0;
	types_stock = ft_strdup("csdiuUxXeEfgGpoO%");
	types_stock_save = types_stock;
	while (*types_stock && **format != *types_stock)
	{
		types_stock++;
	}
	if (**format == *types_stock)
	{
		form->type = *types_stock;
		(*format)++;
		i++;
	}
	free(types_stock_save);
	return (i);
}

int	verify_type_size(const char **format, t_format *form)
{
	int	i;

	i = 0;
	while (**format == 'l' || **format == 'h' || **format == 'L' ||
			**format == 'j' || **format == 'z' || **format == 't')
	{
		pashol_nah(format, form);
		pashol_nah2(format, form);
	}
	return (i);
}

int	verify_format(const char **format, t_format *form)
{
	int i;

	(*format)++;
	i = 0;
	while (!form->type)
	{
		i = 0;
		i += verify_flags(format, form);
		i += verify_width(format, form);
		i += verify_precision(format, form);
		i += verify_type_size(format, form);
		i += verify_type(format, form);
		if (i == 0)
		{
			format_null(form);
			break ;
		}
	}
	return (i);
}
