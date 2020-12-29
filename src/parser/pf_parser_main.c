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

t_format	*pf_parse(t_format *data, const char *str)
{
	if (!(parsed_data = malloc(sizeof(t_format))))
		return (NULL);
	pf_parse_flags(data, &str);
	if (!(pf_parse_width(data, &str) && pf_parse_precision(data, &str)))
	{
		free(data);
		return (NULL);
	}
	return (data);
}
