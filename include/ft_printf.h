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
*/

# define LEADING_SPACE		0x01
# define LEADING_PLUS		0x02
# define PADDING_END		0x04
# define LEADING_ZEROS		0x08
# define ALTERNATIVE_FORM	0x10
# define PADDING_AS_ARG		0x20
# define PRECISION_AS_ARG	0x40

/*
** Struct to save parsed data
*/

typedef struct	s_format
{
	unsigned char	flags;
	int				padding;
	int				precision;
}				t_format;

int				ft_printf(const char *format, ...);
int				pf_int_to_str(t_u8_vec *vec, unsigned int n);
unsigned char	parse_flags(const char *str);

#endif
