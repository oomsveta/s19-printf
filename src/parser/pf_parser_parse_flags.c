/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	pf_parse_flags(t_format *format, const char **str)
{
	unsigned short int	flags;
	unsigned char		c;

	flags = 0x00;
	while (ft_strchr("# -+0I'", (c = *++(*str))))
	{
		if (c == ' ' && !(flags & LEADING_PLUS))
			flags |= LEADING_SPACE;
		else if (c == '+')
		{
			flags &= ~LEADING_SPACE;
			flags |= LEADING_PLUS;
		}
		else if (c == '-')
		{
			flags |= PADDING_END;
			flags &= ~PAD_WITH_ZEROS;
		}
		else if (c == '0' && !(flags & PADDING_END))
			flags |= PAD_WITH_ZEROS;
		else if (c == '#')
			flags |= ALTERNATIVE_FORM;
	}
	format->flags = flags;
}
