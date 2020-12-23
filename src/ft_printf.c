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
#include <stdio.h> // TODO: remove

int	ft_printf(const char *format, ...)
{
	t_u8_vec	*buffer;
	t_format	*parsed_data;
	va_list		args;
	int			ret;

	if (!(buffer = u8_vec_new(0x200)))
		return (0);
	va_start(args, format);
	parsed_data = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			free(parsed_data);
			if (!(parsed_data = pf_parse(parsed_data, format + 1)))
				return (0); // TODO: free buffer
		}
		if (!u8_vec_push(buffer, *format++))
			return (0);
	}
	va_end(args);
	ret = write(STDOUT, buffer->content, buffer->length);
	// TODO: free buffer
	return (ret);
}
