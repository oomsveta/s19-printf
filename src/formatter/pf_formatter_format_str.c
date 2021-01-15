/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formatter_format_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	mbslen(const wchar_t *wstr)
{
	size_t ret;
	wchar_t c;

	ret = 0;
	if (wstr)
		while ((c = *wstr++))
		{
			if (c <= 0x7F)
				ret += 1;
			else if (c <= 0x7FF)
				ret += 2;
			else if (c <= 0xFFFF)
				ret += 3;
			else if (c <= 0x10FFFF)
				ret += 4;
		}
	return (ret);
}

static int	push_wstr(t_u8_vec *vec, const wchar_t *wstr, size_t size)
{
	size_t			amount_of_bytes;
	size_t			i;
	unsigned char	buffer[4];

	while (size-- > 1)
	{
		amount_of_bytes = utf32_to_utf8(buffer, *wstr++);
		i = 0;
		while (i < amount_of_bytes)
			if (!u8_vec_push(vec, buffer[i++]))
				return (0);
	}
	return (1);
}

/*
** string formatting is affected by '-' flag, width and precision
** Awful!!! TODO: Refactor 😾
*/

int				pf_format_str(t_format *format, t_u8_vec *buffer, va_list args)
{
	void	*str;
	size_t	length;
	size_t	i;

	str = va_arg(args, void*);
	length = (format->size == L ? mbslen(str) : ft_strlen(str));
	i = 0;
	if (format->flags & DEFINED_PRECISION)
		length = min(format->precision, length);
	if ((format->flags & WIDTH_OR_PAD_END) == DEFINED_WIDTH
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	if (format->size == L)
	{
		if (!push_wstr(buffer, str, length))
			return (0);
	}
	else
		while (i < length)
			if (!u8_vec_push(buffer, ((char*)str)[i++]))
				return (0);
	if ((format->flags & WIDTH_OR_PAD_END) == WIDTH_OR_PAD_END
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	return (1);
}
