/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

unsigned char	parse_flags(const char *str)
{
	unsigned char flags;
	unsigned char c;

	flags = 0x00;
	while (ft_strchr("# -+0", (c = *str++)))
	{
		if (c == ' ' && !(flags & LEADING_PLUS))
			flags |= LEADING_SPACE;
		if (c == '+')
		{
			flags &= ~LEADING_SPACE;
			flags |= LEADING_PLUS;
		}
		if (c == '-')
		{
			flags |= PADDING_END;
			flags &= ~LEADING_ZEROS;
		}
		if (c == '0' && !(flags & PADDING_END))
			flags |= LEADING_ZEROS;
		if (c == '#')
			flags |= ALTERNATIVE;
	}
	return (flags);
}
