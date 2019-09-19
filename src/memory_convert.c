/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:02:15 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/18 22:37:14 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_in_octal(unsigned long long int nmb, char **memory)
{
	char	*kek;
	char	*hex;
	int		flag;

	flag = 0;
	kek = "012345678";
	hex = &(*memory)[127];
	*hex = '\0';
	hex--;
	if (nmb == 0 && ++flag)
		*hex = '0';
	while (nmb > 0)
	{
		*hex = kek[nmb % 8];
		hex--;
		nmb /= 8;
	}
	if (!flag)
		*memory = hex + 1;
	else
		*memory = hex;
}

char	convert_nmb_to_letter(unsigned long long int nmb)
{
	char chr;

	chr = '\0';
	if (nmb % 16 == 10)
		chr = 'a';
	if (nmb % 16 == 11)
		chr = 'b';
	if (nmb % 16 == 12)
		chr = 'c';
	if (nmb % 16 == 13)
		chr = 'd';
	if (nmb % 16 == 14)
		chr = 'e';
	if (nmb % 16 == 15)
		chr = 'f';
	return (chr);
}

void	convert_in_hex(unsigned long long int nmb, char **memory)
{
	int		flag;
	char	*kek;
	char	*hex;

	flag = 0;
	kek = "0123456789abcdef";
	hex = &(*memory)[127];
	*hex-- = '\0';
	if (nmb == 0 && ++flag)
		*hex = '0';
	while (nmb > 0)
	{
		*hex = kek[nmb % 16];
		hex--;
		nmb /= 16;
	}
	if (!flag)
		*memory = hex + 1;
	else
		*memory = hex;
}

void	convert_in_binary(unsigned long long int nmb, char **memory)
{
	int		i;
	char	chr;

	i = 0;
	chr = '\0';
	while (nmb >= 2)
	{
		if (nmb % 2 == 0)
			chr = '0';
		else if (nmb % 2 == 1)
			chr = '1';
		(*memory)[i++] = chr;
		nmb /= 2;
	}
	if (nmb == 1)
		(*memory)[i++] = '1';
	else if (nmb == 0)
		(*memory)[i++] = '0';
	(*memory)[i] = '\0';
}

char	*memory_convert(unsigned long long int nmb, int nmb_system)
{
	char	*memory;
	int		len;
	char	*result;
	char	*mem;

	len = 0;
	memory = malloc(128);
	mem = memory;
	if (nmb_system == 8)
		convert_in_octal(nmb, &memory);
	if (nmb_system == 16)
		convert_in_hex(nmb, &memory);
	if (nmb_system == 2)
		convert_in_binary(nmb, &memory);
	result = ft_strdup(memory);
	free(mem);
	return (result);
}
