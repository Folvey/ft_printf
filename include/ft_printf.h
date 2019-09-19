/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:15:35 by jstoneha          #+#    #+#             */
/*   Updated: 2019/03/20 20:03:50 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

typedef enum				e_check
{
	CHECK,
	REPLACE
}							t_check;

typedef struct				s_sukadbl
{
	int						i;
	int						len;
	char					*tmp;
	char					*nmb;
	char					*save;
}							t_sukadbl;

typedef struct				s_norm
{
	char					*str_edited;
	int						i;
	int						j;
	int						is_negative;
}							t_norm;

typedef struct				s_norm_h
{
	char					*str_edited;
	int						i;
	int						j;
	int						shift;
	int						strlen;
}							t_norm_h;

typedef struct				s_datatype
{
	long					l;
	long long				ll;
	unsigned int			ui;
	unsigned long long		ull;
	unsigned long int		uli;
	unsigned long long int	ulli;
	short					shortik;
	unsigned short			ushortik;
	signed char				schar;
	unsigned char			uschar;
	intmax_t				j;
	size_t					z;
}							t_datatype;

typedef struct				s_typesize
{
	int						h;
	int						l;
	int						l_uppercase;
	int						j;
	int						z;
}							t_typesize;

typedef struct				s_flags
{
	int						zero;
	int						minus;
	int						plus;
	int						sharp;
	int						space;
}							t_flags;

typedef struct				s_format
{
	t_typesize				typesize;
	t_flags					flag;
	int						width;
	int						precision;
	char					size;
	char					type;
	int						is_negative;
	int						is_plus;
}							t_format;

/*
**--------------------- ft_printf ---------------------
*/

int							ft_printf(const char *format, ...);
int							primary_print(t_format *form, va_list ap);

/*
**--------------------- temp ---------------------
*/

int							ft_ati(const char **str);
int							write_before(const char **format);
char						*ft_itoa_long(long long n);
char						*ft_itoa_uns_long(unsigned long long n);
char						*ft_itoa_uns(unsigned short n);
int							ft_check_length(long long n);
int							ft_check_uns_length(unsigned long long n);

/*
**--------------------- struct_null ---------------------
*/

void						format_null(t_format *form);
t_typesize					typesize_null(void);
t_flags						flag_null(void);

/*
**--------------------- general ---------------------
*/

void						reassign_string(char **str, char *new_str);
char						*ft_strrev(char *str);
void						uppercase_pls(char **str);
void						ft_error(void);

/*
**--------------------- verify_format ---------------------
*/

int							verify_format(const char **format, t_format *form);
int							verify_flags(const char **format, t_format *form);
int							verify_width(const char **format, t_format *form);
int							verify_precision(const char **format,
		t_format *form);
int							verify_type(const char **format, t_format *form);
int							verify_type_size(const char **format,
		t_format *form);

/*
** --------------------- get_spec ---------------------
*/

char						*get_spec(va_list ap, t_format *form);
void						memory_specs(va_list ap, t_format *form,
		char **result);
void						huyak(va_list ap, t_format *form, char **result);
void						get_d_spec(va_list ap, t_format *form,
		char **result);
void						get_u_spec(va_list ap, t_format *form,
		char **result);

/*
** --------------------- memory_convert ---------------------
*/

char						*memory_convert(unsigned long long int nmb,
		int nmb_system);
void						convert_in_binary(unsigned long long int nmb,
		char **memory);
void						convert_in_hex(unsigned long long int nmb,
		char **memory);
char						convert_nmb_to_letter(unsigned long long int nmb);
void						convert_in_octal(unsigned long long int nmb,
		char **memory);

/*
** --------------------- double ---------------------
*/
void						getdbl(long double d, t_format form, char **result);

/*
** --------------------- editors_s ---------------------
*/

void						edit_output_s(char **stroka, t_format *form);
void						edit_precision_s(char **stroka, t_format *form);
void						edit_width_s(char **stroka, t_format *form);

/*
** --------------------- editors ---------------------
*/

void						editor(char **stroka, t_format *form);
void						edit_output(char **stroka, t_format *form);
void						place_sharp(char **stroka, t_format *form);
void						safely_flags(t_format *form);

/*
** selectors
*/

void						select_editors(char **stroka, t_format *form);
void						edit_output_x(char **stroka, t_format *form);
void						edit_output_p(char **stroka, t_format *form);

/*
** flags
*/
void						edit_flags(char **stroka, t_format *form);
void						edit_flags_space(char **stroka, t_format *form);
void						edit_flags_plus(char **stroka, t_format *form);

/*
** signs
*/

void						ft_is_signs(char **stroka, t_format *form);
void						ft_is_space(char **stroka, t_format *form);
void						ft_is_negative(char **stroka, t_format *form);
void						ft_is_plus(char **stroka, t_format *form);

/*
**  precision
*/

void						edit_precision(char **stroka, t_format *form);
void						edit_precision_basic(char **stroka, t_format *form);

/*
** signs rework
*/

void						edit_signs(char **stroka, t_format *form);

/*
**  width
*/

void						edit_width(char **stroka, t_format *form);
void						edit_width_basic(char **stroka,
		t_format *form, char sign);
void						edit_width_minus(char **stroka,
		t_format *form, char sign);
/*
**--------------------- DOROGA CREATES POD LEGS IDUSCHEVO ---------------------
*/
void						pashol_nah(const char **format, t_format *form);
void						pashol_nah2(const char **format, t_format *form);
int							pashol_nah3(va_list ap, t_datatype *data,
		t_format *form, char **result);
int							pashol_nah4(va_list ap, t_datatype *data,
		t_format *form, char **result);
int							pashol_nah5(va_list ap, t_datatype *data,
		t_format *form, char **result);
int							pashol_nah6(va_list ap, t_datatype *data,
		t_format *form, char **result);

/*
**--------------------- PROSTO NE PIZDI, TUT VSE PONYATNO ---------------------
*/

int							prosto_nah(va_list ap, t_datatype *data,
		t_format *form, char **result);
int							prosto_nah2(va_list ap, t_datatype *data,
		t_format *form, char **result);
int							prosto_nah3(va_list ap, t_datatype *data,
		t_format *form, char **result);

void						huyak(va_list ap, t_format *form, char **result);
t_norm						init(int i, int j, int n);
t_sukadbl					initd(int i, int len);
t_norm_h					new_init(int i, int j, int sh);

#endif
