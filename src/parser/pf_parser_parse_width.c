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

int	pf_parse_width(t_format *format, const char **str)
{
	int width;
	int limit;

	if (ft_isdigit(**str))
	{
		width = 0;
		format->flags |= DEFINED_WIDTH;
		limit = INT_MAX / 10;
		while (ft_isdigit(**str))
			if (width > limit || (width = width * 10 + *(*str)++ - '0') < 0)
				return (0);
		format->width = width;
	}
	else if (**str == '*')
	{
		(*str)++;
		format->flags |= WIDTH_AS_ARG | DEFINED_WIDTH;
	}
	return (1);
}
