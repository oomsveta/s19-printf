/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formatter_format_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	pf_format_char(t_format *format, t_u8_vec *buffer, va_list args)
{
	if ((format->flags & DEFINED_WIDTH && !pf_pad(buffer, format->width, ' '))
		|| !u8_vec_push(buffer, va_arg(args, int))
		|| (format->flags & (DEFINED_WIDTH | PADDING_END)
		&& !pf_pad(buffer, format->width, ' ')))
		return (0);
	return (1);
}
