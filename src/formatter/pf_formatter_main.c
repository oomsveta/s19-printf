/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_formatter_main.c                                :+:      :+:    :+:   */
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
** Use a struct to emulate a dictionary which maps every type specifier to its
** handling function.
**
** Mandatory types: cspdiuxX% ; bonuses: nfge
*/

t_pf_handler g_handlers[] =
{
	{	'%', &pf_format_percent		},
	{	'c', &pf_format_char		},
	{	's', &pf_format_str			},
	{	'\0', NULL					}
};

int	pf_format(t_format *format, t_u8_vec *buffer, va_list args)
{
	char	type;
	int		i;

	type = format->type;
	i = 0;
	while (g_handlers[i].type)
	{
		if (g_handlers[i].type == type)
		{
			if (!g_handlers[i].handler(format, buffer, args))
				return (0);
			break ;
		}
		i++;
	}
	return (1);
}
