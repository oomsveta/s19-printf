/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/*
** Flag constants for the parser
** |P|W|#|0|-|+|Sp|
*/

# define LEADING_SPACE		0x01
# define LEADING_PLUS		0x02
# define PADDING_END		0x04
# define PAD_WITH_ZEROS		0x08
# define ALTERNATIVE_FORM	0x10
# define DEFINED_WIDTH		0x20
# define DEFINED_PRECISION	0x40

/*
** (DEFINED_WIDTH | PADDING_END) would be better, but the Norm forbids it
*/

# define WIDTH_OR_PAD_END	0x24

/*
** Size constants
*/

enum	e_size { H = 1, HH, L, LL };

/*
** Struct to save parsed data
*/

struct	s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	unsigned char	size;
	char			type;
};
typedef struct s_format	t_format;

/*
** "Dictionary" to map every type specifier to its handling function
*/

struct	s_pf_handler
{
	char	type;
	int		(*handler)(t_format *, t_u8_vec *, va_list);
};
typedef struct s_pf_handler	t_pf_handler;

/*
** Main functions
*/

int		ft_printf(const char *format, ...);
int		pf_parse(t_format **pf, const char **ps, t_u8_vec *b, va_list v);
int		pf_format(t_format *format, t_u8_vec *buffer, va_list args);

/*
** Parsing functions
*/

void	pf_parse_flags(t_format *format, const char **str);
int		pf_parse_width(t_format *format, const char **str, va_list args);
int		pf_parse_precision(t_format *format, const char **str, va_list args);
void	pf_parse_size(t_format *format, const char **str);

/*
** Formatting functions
*/

int		pf_format_char(t_format *format, t_u8_vec *buffer, va_list args);
int		pf_format_percent(t_format *format, t_u8_vec *buffer, va_list args);
int		pf_format_str(t_format *format, t_u8_vec *buffer, va_list args);

/*
** Utils
*/

int		pf_pad(t_u8_vec *vec, int width, char c);
int		pf_print_as_it(t_format *format, t_u8_vec *buffer);
int		pf_push_int(t_u8_vec *vec, unsigned int n);

#endif
