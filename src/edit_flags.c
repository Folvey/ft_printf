/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:57:23 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/18 22:35:27 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	edit_flags_plus(char **stroka, t_format *form)
{
	t_norm norm;

	norm = init(0, 0, 0);
	if (!form->flag.plus)
		return ;
	if ((*stroka)[norm.i] == '-')
	{
		norm.i++;
		norm.is_negative = 1;
		norm.str_edited = malloc(sizeof(ft_strlen(*stroka) + 1));
		norm.str_edited[norm.j++] = '-';
	}
	else
		norm.str_edited = malloc(sizeof(ft_strlen(*stroka) + 2));
	if (norm.is_negative == 0)
	{
		norm.str_edited[norm.j++] = '+';
		while ((*stroka)[norm.i])
			norm.str_edited[norm.j++] = (*stroka)[norm.i++];
	}
	if (norm.is_negative == 1)
		while ((*stroka)[norm.i])
			norm.str_edited[norm.j++] = (*stroka)[norm.i++];
	norm.str_edited[norm.j] = '\0';
	reassign_string(stroka, norm.str_edited);
}

void	edit_flags_space(char **stroka, t_format *form)
{
	int		i;
	int		j;
	char	*str_edited;

	i = 0;
	j = 0;
	if (!form->flag.space || form->flag.plus || (*stroka)[i] == '-')
		return ;
	if ((*stroka)[i] == '+')
		i++;
	str_edited = malloc(ft_strlen(*stroka) + 2);
	str_edited[j++] = ' ';
	while ((*stroka)[i])
	{
		str_edited[j] = (*stroka)[i];
		j++;
		i++;
	}
	str_edited[j] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_flags_sharp(char **stroka, t_format *form)
{
	int		i;
	int		j;
	char	*str_edited;

	i = 0;
	j = 0;
	if (!form->flag.sharp)
		return ;
	if (!ft_strcmp("0", *stroka))
		return ;
	str_edited = malloc(ft_strlen(*stroka) + 2);
	str_edited[j++] = '0';
	while ((*stroka)[i])
	{
		str_edited[j] = (*stroka)[i];
		j++;
		i++;
	}
	str_edited[j] = '\0';
	reassign_string(stroka, str_edited);
}

void	edit_flags(char **stroka, t_format *form)
{
	edit_flags_plus(stroka, form);
	edit_flags_space(stroka, form);
	if (form->type == 'o' || form->type == 'O')
		edit_flags_sharp(stroka, form);
}
