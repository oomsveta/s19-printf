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

int free_all(t_format *format, t_u8_vec *buffer)
{
	free(format);
	free(buffer->content);
	free(buffer);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_u8_vec	*buffer;
	t_format	*format;
	va_list		args;
	int			ret;

	if (!(buffer = u8_vec_new(0x200)))
		return (0);
	va_start(args, str);
	format = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			if (!(format = pf_parse(format, str)))
				return (free_all(format, buffer));
		}
		if (!u8_vec_push(buffer, *str++))
			return (0);
	}
	va_end(args);
	ret = write(STDOUT, buffer->content, buffer->length);
	free_all(format, buffer);
	return (ret);
}
