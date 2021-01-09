/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_print_as_it.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Flags order: hash, space, plus, minus, zero
** … what about non-standard flags? (I')
*/

static int	push_flags(t_format *format, t_u8_vec *buffer)
{
	unsigned short int flags;

	flags = format->flags;
	if ((flags & ALTERNATIVE_FORM && !u8_vec_push(buffer, '#'))
		|| (flags & LEADING_SPACE && !u8_vec_push(buffer, ' '))
		|| (flags & LEADING_PLUS && !u8_vec_push(buffer, '+'))
		|| (flags & PADDING_END && !u8_vec_push(buffer, '-'))
		|| (flags & PAD_WITH_ZEROS && !u8_vec_push(buffer, '0')))
		return (0);
	return (1);
}

static int	push_width(t_format *format, t_u8_vec *buffer)
{
	if (!(format->flags & DEFINED_WIDTH))
		return (1);
	if (!pf_push_int(buffer, format->width))
		return (0);
	return (1);
}

static int	push_precision(t_format *format, t_u8_vec *buffer)
{
	if (!(format->flags & DEFINED_PRECISION))
		return (1);
	if (!(u8_vec_push(buffer, '.') || pf_push_int(buffer, format->precision)))
		return (0);
	return (1);
}

/*
* AWFUL!!! TODO: Find a better idea
*/

static int	push_size(t_format *format, t_u8_vec *buffer)
{
	char size;

	if (!(size = format->size))
		return (1);
	if (size == H || size == HH)
	{
		if (!u8_vec_push(buffer, 'h'))
			return (0);
	}
	if (size == HH)
	{
		if (!u8_vec_push(buffer, 'h'))
			return (0);
	}
	else if (size == L || size == LL)
	{
		if (!u8_vec_push(buffer, 'l'))
			return (0);
	}
	if (size == LL)
	{
		if (!u8_vec_push(buffer, 'l'))
			return (0);
	}
	return (1);
}

/*
** If the conversion type is unknown, print the format specifier as it.
*/

int			pf_print_as_it(t_format *format, t_u8_vec *buffer)
{
	ft_putstr("print as it");
	if (!(u8_vec_push(buffer, '%')
		&& push_flags(format, buffer)
		&& push_width(format, buffer)
		&& push_precision(format, buffer)
		&& push_size(format, buffer)
		&& u8_vec_push(buffer, format->type)))
		return (0);
	return (1);
}
