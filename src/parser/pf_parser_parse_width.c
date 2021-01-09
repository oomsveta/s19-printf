/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_parse_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	pf_parse_width(t_format *format, const char **str, va_list args)
{
	int width;
	int limit;

	if (ft_isdigit(**str))
	{
		format->flags |= DEFINED_WIDTH;
		width = 0;
		limit = INT_MAX / 10;
		while (ft_isdigit(**str))
			if (width > limit || (width = width * 10 + *(*str)++ - '0') < 0)
				return (0);
		format->width = width;
	}
	else if (**str == '*')
	{
		format->flags |= WIDTH_AS_ARG | DEFINED_WIDTH;
		if ((format->width = va_arg(args, int)) < 0)
		{
			format->flags |= PADDING_END;
			format->width = -format->width;
		}
		(*str)++;
	}
	return (1);
}
