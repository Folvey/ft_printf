/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editors_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:16:19 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:18:59 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_width_s_simple(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;
	int		len;
	int		j;

	if (!form->width || form->width <= (int)ft_strlen(*stroka))
		return ;
	str_edited = malloc(form->width + 1);
	len = form->width - (int)ft_strlen(*stroka);
	i = 0;
	j = 0;
	while (i < len)
		str_edited[i++] = ' ';
	while (i < form->width)
		str_edited[i++] = (*stroka)[j++];
	str_edited[i] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_width_s_minus(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;

	if (!form->flag.minus || form->width <= (int)ft_strlen(*stroka))
	{
		return ;
	}
	str_edited = ft_strdup(*stroka);
	i = (int)ft_strlen(*stroka);
	while (i < form->width)
		str_edited[i++] = ' ';
	str_edited[i] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_width_s_zero(char **stroka, t_format *form)
{
	char	*str_edited;
	int		i;
	int		j;
	int		len;

	if (!form->flag.zero || form->width <= (int)ft_strlen(*stroka))
	{
		return ;
	}
	str_edited = malloc(form->width + 1);
	i = 0;
	j = 0;
	len = form->width - (int)ft_strlen(*stroka);
	while (i < len)
		str_edited[i++] = '0';
	while (i < form->width)
		str_edited[i++] = (*stroka)[j++];
	str_edited[i] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_width_s(char **stroka, t_format *form)
{
	if (!form->width || form->width <= (int)ft_strlen(*stroka))
	{
		return ;
	}
	edit_width_s_minus(stroka, form);
	edit_width_s_zero(stroka, form);
	edit_width_s_simple(stroka, form);
}

void	edit_output_s(char **stroka, t_format *form)
{
	edit_precision_s(stroka, form);
	edit_width_s(stroka, form);
}
