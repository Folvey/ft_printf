/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:20:09 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:21:52 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reassign_string(char **str, char *new_str)
{
	ft_strdel(str);
	*str = ft_strdup(new_str);
	ft_strdel(&new_str);
}

char	*ft_strrev(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str);
	new_str = malloc(j);
	j--;
	while (j >= 0)
	{
		new_str[i] = str[j];
		i++;
		j--;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

void	uppercase_pls(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (((*str)[i] >= 'a' && (*str)[i] <= 'f') || (*str)[i] == 'x')
			(*str)[i] -= 32;
		i++;
	}
}

void	ft_error(void)
{
	exit(0);
}
