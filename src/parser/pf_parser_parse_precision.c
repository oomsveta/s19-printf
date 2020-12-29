/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_parse_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	pf_parse_precision(t_format *format, const char **str)
{
	int prec;
	int limit;

	if (**str != '.')
		return (1);
	format->flags |= DEFINED_PRECISION;
	prec = 0;
	if (*++(*str) == '*')
		flags |= PRECISION_AS_ARG;
	else
	{
		limit = INT_MAX / 10;
		while (ft_isdigit(**str))
			if (prec > limit || (prec = prec * 10 + *(*str)++ - '0') < 0)
				return (0);
	}
	format->precision = prec;
	return (1);
}
