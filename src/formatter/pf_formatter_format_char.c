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
	int	width;

	if (format->flags & DEFINED_WIDTH)
	{
		width = pf_get_width(format, args, 1);
		if (format->flags & PADDING_END)
		{
			if (!u8_vec_push(buffer, va_arg(args, int)))
				return (0);
			while (width-- > 1)
				if (!u8_vec_push(buffer, ' '))
					return (0);
		}
		else
		{
			while (width-- > 1)
				if (!u8_vec_push(buffer, ' '))
					return (0);
			if (!u8_vec_push(buffer, va_arg(args, int)))
				return (0);
		}
	}
	else
		return (u8_vec_push(buffer, va_arg(args, int)));
	return (1);
}
