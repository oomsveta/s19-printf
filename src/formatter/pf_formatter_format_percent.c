/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formatter_format_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
** The percentage type formatting isn't affected by any flag. The 'format' and
** 'args' arguments are provided to be consistent with the other formatting
** functions.
*/

int	pf_format_percent(t_format *format, t_u8_vec *buffer, va_list args)
{
	(void)format;
	(void)args;
	return (u8_vec_push(buffer, '%'));
}
