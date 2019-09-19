/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:21:03 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/18 15:39:54 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!len)
		return (dest);
	while (i < len)
	{
		((unsigned char *)dest)[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
