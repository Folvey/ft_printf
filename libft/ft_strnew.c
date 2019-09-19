/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:22:31 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/15 15:02:17 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = malloc(size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
