/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:51:01 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/19 14:32:41 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(t_format *form)
{
	int	len;

	len = 1;
	if (form->width > 0)
	{
		form->width -= 1;
		while (form->width--)
		{
			ft_putchar(' ');
			len++;
		}
	}
	ft_putchar('\0');
	return (len);
}

int	obnulyay_na_null(char **stroka, t_check flag)
{
	char *str;

	str = *stroka;
	if (flag == CHECK)
	{
		while (*str)
		{
			if (*str == ' ' || *str == '0')
				str++;
			else
				return (0);
		}
		return (1);
	}
	else
	{
		while (*str)
		{
			if (*str == '0')
				*str = ' ';
			str++;
		}
		return (2);
	}
}

int	takaya_problema(t_format *form, char **stroka, int len)
{
	if (form->type == 'o' && form->flag.sharp && !form->precision &&
		!ft_strcmp("0", *stroka) && !form->width)
		;
	else if ((form->type == 'x' || form->type == 'o' || form->type == 'O'
				|| form->type == 'd' || form->type == 'i'
				|| form->type == 'u') && len == 1 &&
			**stroka == '0' && form->precision == 0 && !form->width)
	{
		ft_strdel(stroka);
		return (0);
	}
	return (1);
}

int	primary_print(t_format *form, va_list ap)
{
	char	*stroka;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = NULL;
	len = 0;
	tmp = get_spec(ap, form);
	stroka = ft_strdup(tmp);
	free(tmp);
	editor(&stroka, form);
	len = (int)ft_strlen(stroka);
	if (len == 0 && form->type == 'c')
		len = ft_putnstr(form);
	if (!takaya_problema(form, &stroka, len))
		return (0);
	if (form->width && !form->precision
			&& obnulyay_na_null(&stroka, CHECK) == 1)
		obnulyay_na_null(&stroka, REPLACE);
	ft_putstr(stroka);
	ft_strdel(&stroka);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_format	form;
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		len += write_before(&format);
		if (*format == '%')
		{
			format_null(&form);
			if (verify_format(&format, &form))
				len += primary_print(&form, ap);
		}
	}
	va_end(ap);
	return (len);
}
