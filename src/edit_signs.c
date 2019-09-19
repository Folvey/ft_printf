/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_signs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:04:57 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 21:07:11 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_signs(char **stroka, t_format *form)
{
	char	*str_edited;
	int		strlen;

	strlen = (int)ft_strlen(*stroka);
	str_edited = NULL;
	if (form->is_negative)
	{
		str_edited = ft_strjoin("-", *stroka);
		reassign_string(stroka, str_edited);
	}
	if (form->is_plus && form->type != 'o')
	{
		str_edited = ft_strjoin("+", *stroka);
		reassign_string(stroka, str_edited);
	}
	if (form->flag.space && !form->is_negative &&
			!form->is_plus && form->type != 'o')
	{
		str_edited = ft_strjoin(" ", *stroka);
		reassign_string(stroka, str_edited);
	}
	if (form->flag.sharp)
		place_sharp(stroka, form);
}
