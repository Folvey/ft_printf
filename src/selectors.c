/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:08:22 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/17 22:08:36 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_output_p(char **stroka, t_format *form)
{
	char *new_str;

	edit_flags(stroka, form);
	ft_is_signs(stroka, form);
	edit_precision(stroka, form);
	edit_signs(stroka, form);
	new_str = ft_strjoin("0x", *stroka);
	reassign_string(stroka, new_str);
	edit_width(stroka, form);
}

void	edit_output_x(char **stroka, t_format *form)
{
	char *str_edited;

	str_edited = NULL;
	edit_flags(stroka, form);
	ft_is_signs(stroka, form);
	edit_precision(stroka, form);
	edit_signs(stroka, form);
	edit_width(stroka, form);
	if (form->type == 'X')
		uppercase_pls(stroka);
	if (form->flag.zero && form->flag.sharp)
	{
		str_edited = ft_strjoin("0x", *stroka);
		reassign_string(stroka, str_edited);
	}
}

void	select_editors(char **stroka, t_format *form)
{
	if (*stroka == NULL)
		return ;
	if (form->type == 's')
		edit_output_s(stroka, form);
	else if (form->type == 'p')
		edit_output_p(stroka, form);
	else if (form->type == 'x' || form->type == 'X')
		edit_output_x(stroka, form);
	else
		edit_output(stroka, form);
}
