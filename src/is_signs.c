/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:54:40 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:58:13 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_signs(char **stroka, t_format *form)
{
	ft_is_space(stroka, form);
	ft_is_negative(stroka, form);
	ft_is_plus(stroka, form);
}

void	ft_is_space(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_edited = NULL;
	if (*stroka == NULL)
		return ;
	if (**stroka == ' ' && form->type != 'c')
	{
		str_edited = malloc(ft_strlen(*stroka));
		i++;
		while ((*stroka)[i])
		{
			str_edited[j] = (*stroka)[i];
			i++;
			j++;
		}
		str_edited[j] = '\0';
		reassign_string(stroka, str_edited);
	}
}

void	ft_is_negative(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_edited = NULL;
	if (*stroka == NULL)
		return ;
	if (**stroka == '-')
	{
		form->is_negative = 1;
		str_edited = malloc(ft_strlen(*stroka));
		i++;
		while ((*stroka)[i])
		{
			str_edited[j] = (*stroka)[i];
			i++;
			j++;
		}
		str_edited[j] = '\0';
		reassign_string(stroka, str_edited);
	}
}

void	ft_is_plus(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_edited = NULL;
	if (*stroka == NULL)
		return ;
	if (**stroka == '+')
	{
		form->is_plus = 1;
		str_edited = malloc(ft_strlen(*stroka));
		i++;
		while ((*stroka)[i])
		{
			str_edited[j] = (*stroka)[i];
			i++;
			j++;
		}
		str_edited[j] = '\0';
		reassign_string(stroka, str_edited);
	}
}
