/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	pf_parse(t_format **pfrmt, const char **pstr, t_u8_vec *buf, va_list args)
{
	const char	*str;
	t_format	*format;

	free(*pfrmt);
	if (!(*pfrmt = malloc(sizeof(t_format))))
		return (0);
	str = *pstr;
	format = *pfrmt;
	pf_parse_flags(format, &str);
	if (!(pf_parse_width(format, &str) && pf_parse_precision(format, &str)))
		return (0);
	pf_parse_size(format, &str);
	if (ft_strchr("cspdiuxX%", *str))
	{
		format->type = *str;
		*pstr = ++str;
		if (!pf_format(format, buf, args))
			return (0);
	}
	else
		format->type = '\0';
	return (1);
}
