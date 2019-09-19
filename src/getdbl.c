/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:53:17 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/21 19:04:21 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nuh_nuh_i_nah_nah(long double d, t_sukadbl *dbl)
{
	dbl->nmb = ft_itoa_long(d);
	dbl->tmp = ft_strjoin(dbl->save, dbl->nmb);
	free(dbl->nmb);
	free(dbl->save);
	dbl->save = ft_strdup(dbl->tmp);
	free(dbl->tmp);
}

void	local_nah(long double d, t_format form, char **result, t_sukadbl *dbl)
{
	while (dbl->i < form.precision)
	{
		d = d * 10;
		nuh_nuh_i_nah_nah(d, dbl);
		d = d - (long)d;
		dbl->i++;
	}
	d = d * 10;
	if (d > 5)
	{
		if (dbl->save[dbl->len] < '9')
			dbl->save[dbl->len] += 1;
		else
		{
			while (dbl->save[dbl->len] == '9')
				dbl->save[dbl->len--] = '0';
			dbl->save[dbl->len] += 1;
		}
	}
	*result = ft_strdup(dbl->save);
	free(dbl->save);
}

void	local_nah2(long double d, t_sukadbl *dbl)
{
	while (dbl->i < 6)
	{
		d = d * 10;
		nuh_nuh_i_nah_nah(d, dbl);
		d = d - (long)d;
		dbl->i++;
	}
	dbl->len = (int)ft_strlen(dbl->save) - 1;
}

void	dbl_grow(long double d, t_format form, char **result)
{
	t_sukadbl dbl;

	dbl = initd(1, 0);
	if (d < 0)
		d *= -1;
	if (form.precision >= 0)
		local_nah(d, form, result, &dbl);
	else
	{
		local_nah2(d, &dbl);
		d = d * 10;
		if (d > 5)
		{
			if (dbl.save[dbl.len] < '9')
				dbl.save[dbl.len] += 1;
			else
			{
				while (dbl.save[dbl.len] == '9')
					dbl.save[dbl.len--] = '0';
				dbl.save[dbl.len] += 1;
			}
		}
		*result = ft_strdup(dbl.save);
		free(dbl.save);
	}
}

void	getdbl(long double d, t_format form, char **result)
{
	int		i;
	char	*tmp;
	int		tmp_len;
	char	save[2];
	char	*str;

	str = NULL;
	form.precision > 23 ? form.precision = 16 : 0;
	i = 1;
	d = d * 10;
	tmp = ft_itoa_long(d);
	tmp_len = (int)ft_strlen(tmp) - 1;
	save[0] = tmp[tmp_len];
	tmp[tmp_len++] = '.';
	save[1] = tmp[tmp_len];
	tmp[tmp_len] = save[0];
	tmp_len++;
	tmp[tmp_len] = save[1];
	d = d - (long long)d;
	dbl_grow(d, form, result);
	str = ft_strjoin(tmp, *result);
	free(*result);
	*result = ft_strdup(str);
	free(tmp);
	free(str);
}
