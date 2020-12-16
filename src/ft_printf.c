/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int pf_format(char c, va_list args, t_u8_vec *buffer)
{
	if (c == '%')
		return (u8_vec_push(buffer, '%'));
	if (c == 'c')
		return (u8_vec_push(buffer, (unsigned char)va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (pf_int_to_str(buffer, va_arg(args, int)));
}

int	ft_printf(const char *format, ...)
{
	t_u8_vec	*buffer;
	va_list		args;
	int			ret;

	if (!(buffer = u8_vec_new(0x200)))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_strchr("dsupixcX%", format[1]))
			{
				if (!pf_format(format[1], args, buffer)) {
					return (-1); // TODO: free buffer
				}
				format += 2;
			}
		}
		if (!u8_vec_push(buffer, *format++))
			return (-1);
	}
	va_end(args);
	ret = write(STDOUT, buffer->content, buffer->length);
	// TODO: free buffer
	return (ret);
}
