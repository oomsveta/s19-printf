/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_parse_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse_size(t_format *format, const char **str)
{
	if (**str == 'h')
	{
		if (*++(*str) == 'h')
		{
			format->size = HH;
			(*str)++;
		}
		else
			format->size = H;
	}
	else if (**str == 'l')
	{
		if (*++(*str) == 'l')
		{
			format->size = LL;
			(*str)++;
		}
		else
			format->size = L;
	}
	else
		format->size = 0;
}
