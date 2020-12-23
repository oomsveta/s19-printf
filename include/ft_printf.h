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
#define FT_PRINTF_H

#include "libft.h"

/*
** Flag constants for the parser
** |PA|P|WA|W|#|0|-|+|Sp|
*/

# define LEADING_SPACE		0x01
# define LEADING_PLUS		0x02
# define PADDING_END		0x04
# define LEADING_ZEROS		0x08
# define ALTERNATIVE_FORM	0x10
# define DEFINED_WIDTH		0x20
# define WIDTH_AS_ARG		0x40
# define DEFINED_PRECISION	0x80
# define PRECISION_AS_ARG	0x100

/*
** Struct to save parsed data
*/

typedef struct	s_format
{
	unsigned short int	flags;
	int					width;
	int					precision;
}				t_format;

int				ft_printf(const char *format, ...);
int				pf_int_to_str(t_u8_vec *vec, unsigned int n);
void	pf_parse_flags(t_format *parsed_data, const char **str);
void	pf_parse_width(t_format *parsed_data, const char **str);
t_format	*pf_parse(t_format *parsed_data, const char *str);

#endif
