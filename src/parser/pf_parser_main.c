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

t_format	*pf_parse(t_format *format, const char *str)
{
	if (!(format = malloc(sizeof(t_format))))
		return (NULL);
	pf_parse_flags(format, &str);
	if (!(pf_parse_width(format, &str) && pf_parse_precision(format, &str)))
	{
		free(format);
		return (NULL);
	}
	pf_parse_size(format, &str);
	return (format);
}
