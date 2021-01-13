/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formatter_format_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** char formatting is affected by '-' flag and width
*/

// TODO: Handle size modifier (l)
int	pf_format_char(t_format *format, t_u8_vec *buffer, va_list args)
{
	if (((format->flags & WIDTH_OR_PAD_END) == DEFINED_WIDTH
		&& !pf_pad(buffer, format->width, ' '))
		|| !u8_vec_push(buffer, va_arg(args, int))
		|| ((format->flags & WIDTH_OR_PAD_END) == WIDTH_OR_PAD_END
		&& !pf_pad(buffer, format->width, ' ')))
		return (0);
	return (1);
}
