/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by lwicket           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_int_to_str(t_u8_vec *vec, unsigned int n)
{
	char buffer[10];
	int i;

	i = 0;
	if (n >> 31)
	{
		if (!u8_vec_push(vec, '-'))
			return (0);
		n = -n;
	}
	if (!n && !u8_vec_push(vec, '0'))
		return (0);
	while (n)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i--)
		if (!u8_vec_push(vec, buffer[i]))
			return (0);
	return (1);
}
