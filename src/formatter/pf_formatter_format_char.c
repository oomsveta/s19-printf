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

/*
** char formatting is affected by '-' flag and width
*/

int	pf_format_char(t_format *format, t_u8_vec *buffer, va_list args)
{
	unsigned char	mbchar[4];
	size_t			length;
	size_t			i;

	length = format->size == L ? utf32_to_utf8(mbchar, va_arg(args, int)) : 1;
	i = 0;
	if ((format->flags & WIDTH_OR_PAD_END) == DEFINED_WIDTH
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	if (format->size == L)
		while (i < length)
		{
			if (!u8_vec_push(buffer, mbchar[i++]))
				return (0);
		}
	else if (!u8_vec_push(buffer, va_arg(args, int)))
		return (0);
	if ((format->flags & WIDTH_OR_PAD_END) == WIDTH_OR_PAD_END
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	return (1);
}
