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

static void	parse_flags(t_format *parsed_data, const char **str)
{
	unsigned char c;
	unsigned char flags;

	flags = 0x00;
	while (ft_strchr("# -+0", (c = *(*str)++)))
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
			flags &= ~LEADING_ZEROS;
		}
		else if (c == '0' && !(flags & PADDING_END))
			flags |= LEADING_ZEROS;
		else if (c == '#')
			flags |= ALTERNATIVE_FORM;
	}
	parsed_data->flags = flags;
}

static void	parse_flags2(t_format *parsed_data, const char **str)
{
	unsigned char c;

	if (**str == '*')
	{
		parsed_data->flags |= PADDING_AS_ARG;
		(*str)++;
	}
	else if (ft_isdigit(**str))
		while (ft_isdigit(c = *(*str)++))
			parsed_data->padding = parsed_data->padding * 10 + c - '0';
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			parsed_data->flags |= PRECISION_AS_ARG;
			(*str)++;
		}
		else if (ft_isdigit(**str))
			while (ft_isdigit(c = *(*str)++))
				parsed_data->precision = parsed_data->precision * 10 + c - '0';
	}
}

t_format	*pf_parse(t_format *parsed_data, const char *str)
{
	if (!(parsed_data = malloc(sizeof(t_format))))
		return (NULL);
	parse_flags(parsed_data, &str);
	parse_flags2(parsed_data, &str);
}
