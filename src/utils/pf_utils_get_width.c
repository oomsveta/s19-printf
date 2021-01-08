/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_get_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_get_width(t_format *format, va_list args, int default_width)
{
	unsigned short int	flags;
	int					width;

	flags = format->flags;
	if (flags & DEFINED_WIDTH)
	{
		if (flags & WIDTH_AS_ARG)
		{
			width = va_arg(args, int);
			if (width < 0)
			{
				format->flags |= PADDING_END;
				width = -width;
			}
			format->width = width;
		}
	}
	else
		format->width = default_width;
	return (format->width);
}
