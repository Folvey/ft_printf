/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:13:49 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/18 15:29:24 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			is_negative;

	i = 0;
	num = 0;
	is_negative = 1;
	while (str[i] && (str[i] == '\v' || str[i] == '\f' ||
				str[i] == '\r' || str[i] == '\t'
	|| str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num != num * 10 / 10)
			return (is_negative < 0 ? 0 : -1);
	}
	return (num * is_negative);
}
