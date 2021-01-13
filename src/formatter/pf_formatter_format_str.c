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

/*
** string formatting is affected by '-' flag, width and precision
*/
// TODO: Handle size modifier (l)
// Awful!!! TODO: Refactor 😾
int	pf_format_str(t_format *format, t_u8_vec *buffer, va_list args)
{
	char	*str;
	size_t	length;
	size_t	i;

	str = va_arg(args, char*);
	length = ft_strlen(str);
	i = 0;
	if (format->flags & DEFINED_PRECISION)
		length = min(format->precision, length);
	if ((format->flags & WIDTH_OR_PAD_END) == DEFINED_WIDTH
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	while (i < length)
		if (!u8_vec_push(buffer, str[i++]))
			return (0);
	if ((format->flags & WIDTH_OR_PAD_END) == WIDTH_OR_PAD_END
		&& !pf_pad(buffer, format->width - length, ' '))
		return (0);
	return (1);
}
