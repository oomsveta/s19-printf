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

int	pf_parse(t_format **pfrmt, const char **pstr, t_u8_vec *buf, va_list args)
{
	t_format	*format;

	free(*pfrmt);
	if (!(*pfrmt = malloc(sizeof(t_format))))
		return (0);
	format = *pfrmt;
	pf_parse_flags(format, pstr);
	if (!(pf_parse_width(format, pstr, args)
		&& pf_parse_precision(format, pstr, args)))
		return (0);
	pf_parse_size(format, pstr);
	if (ft_strchr("cspdiuxX%", (format->type = *(*pstr)++)))
	{
		if (!pf_format(format, buf, args))
			return (0);
	}
	else if (!pf_print_as_it(format, buf))
		return (0);
	return (1);
}
