/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:17:58 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 22:19:05 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_uns(unsigned short n)
{
	char	*str;
	int		len;

	len = ft_check_uns_length(n);
	if (n == 65535)
		return (ft_strdup("65535"));
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa_uns_long(unsigned long long n)
{
	char	*str;
	int		len;

	len = ft_check_uns_length(n);
	if (n == 18446744073709551615ULL)
		return (ft_strdup("18446744073709551615"));
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa_long(long long n)
{
	char	*str;
	int		len;

	len = ft_check_length(n);
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int		ft_ati(const char **str)
{
	long long	num;
	int			is_negative;

	num = 0;
	is_negative = 1;
	while (**str == '\v' || **str == '\f' || **str == '\r' || **str == '\t'
			|| **str == '\n' || **str == ' ')
		(*str)++;
	if (**str == '-')
		is_negative = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
		if (num != num * 10 / 10)
			return (is_negative < 0 ? 0 : -1);
	}
	return ((int)num * is_negative);
}

int		write_before(const char **format)
{
	int	len;

	len = 0;
	while (**format != '%' && **format != '\0')
	{
		write(1, &(**format), 1);
		(*format)++;
		len++;
	}
	return (len);
}
