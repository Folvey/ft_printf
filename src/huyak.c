/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huyak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:01:34 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/20 19:46:32 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		huyak(va_list ap, t_format *form, char **result)
{
	char	*tmp;
	char	c;
	int		i;

	i = 0;
	if (form->type == 's')
	{
		tmp = (va_arg(ap, char*));
		if (!tmp)
			*result = ft_strdup("(null)");
		else
			*result = ft_strdup(tmp);
	}
	if (form->type == 'c')
	{
		c = (va_arg(ap, int));
		if (c == '\0')
			result = NULL;
		else
		{
			*result = malloc(1);
			(*result)[i] = c;
		}
	}
}

t_norm		init(int i, int j, int n)
{
	t_norm norm;

	norm.i = i;
	norm.is_negative = n;
	norm.j = j;
	return (norm);
}

t_sukadbl	initd(int i, int len)
{
	t_sukadbl d;

	d.i = i;
	d.len = len;
	d.save = malloc(1);
	*(d.save) = '\0';
	d.tmp = malloc(1);
	*(d.tmp) = '\0';
	d.nmb = malloc(1);
	*(d.nmb) = '\0';
	return (d);
}

int			ft_check_length(long long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_check_uns_length(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}
