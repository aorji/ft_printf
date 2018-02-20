/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:40:49 by aorji             #+#    #+#             */
/*   Updated: 2018/02/17 18:40:51 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_prntf	ft_fill(char c, t_prntf memb, int zero)
{
	if (c == 'h')
		memb.h += 1;
	if (c == 'l')
		memb.l += 1;
	if (c == 'j')
		memb.j = 1;
	if (c == 'z')
		memb.z = 1;
	if (c == '+')
		memb.pluse = 1;
	if (c == ' ')
		memb.space = 1;
	if (c == '#')
		memb.sharp = 1;
	if (c == '-')
		memb.minus = 1;
	if (c >= 48 && c <= 57 && zero == 2)
		memb.precision = memb.precision * 10 + c - 48;
	return (memb);
}

t_prntf			ft_fillflags(char *flags)
{
	t_prntf	memb;
	int		zero;

	memb = (t_prntf){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	zero = 0;
	while (*flags)
	{
		memb = ft_fill(*flags, memb, zero);
		if (*flags == 48 && zero == 0)
		{
			memb.zero = 1;
			zero = 1;
		}
		if (*flags >= 48 && *flags <= 57 && zero != 2)
		{
			memb.width = memb.width * 10 + (*flags) - 48;
			zero = 1;
		}
		if (*flags == '.' && (zero = 2))
			memb.point = 1;
		flags++;
	}
	return (memb);
}
