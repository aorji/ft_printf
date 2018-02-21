/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:56:36 by aorji             #+#    #+#             */
/*   Updated: 2018/02/19 20:56:37 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_buf(const char **format, char **buf)
{
	char	*tmp;
	char	*sub;

	*buf = ft_strnew(1);
	while (**format != '%' && **format)
	{
		tmp = *buf;
		sub = ft_strsub(*format, 0, 1);
		*buf = ft_strjoin(*buf, sub);
		ft_strdel(&sub);
		ft_strdel(&tmp);
		(*format)++;
	}
	if (**format == '%' && ft_strlen(*format) == 1)
		return (0);
	if (!**format)
		return (ft_return(*buf));
	if (**format == '%')
		(*format)++;
	return (-1);
}

int	ft_add_buf(int a, int j, char **buf, const char **format)
{
	t_prntf	flags;
	char	*tmp;
	int		u;

	u = 1;
	if ((ft_check_midle(ft_strsub(*format, 0, j)) >= 0))
	{
		while (j && !(u = 0))
		{
			a = ft_check_midle(ft_strsub(*format, 0, j));
			if (a >= 0)
			{
				tmp = ft_strsub(*format, 0, a + 1);
				flags = ft_fillflags(tmp);
				while (!ft_not_flag(*tmp))
					tmp++;
				*buf = ft_strjoin(*buf, ft_full_input(flags, tmp));
				*format += a + 1;
				if (!**format)
					return (-1);
			}
			j--;
		}
	}
	return (u);
}

int	ft_positon(int *a, int *j, const char **format)
{
	*j = ft_proc_position(*format);
	*a = ft_pos_kod(*format);
	if (*a >= 0 && *j > *a)
		*j = *a;
	if (j < 0)
		return (g_i);
	else
		return (-1);
}

int	ft_not_flag(char c)
{
	if (c != 'h' && c != 'l' && c != 'j' && c != 'z' && c != '#' && c != '0'
		&& c != '-' && c != '+' && c != ' ' && c != '%' && c != '.'
		&& !(c >= 48 && c <= 57) && c != 's' && c != 'S' && c != 'c' && c != 'C'
		&& c != 'x' && c != 'X' && c != 'p' && c != 'd' && c != 'i' && c != 'o'
		&& c != 'O' && c != 'u' && c != 'U' && c != '%' && c != 'D' && c != '-'
		&& c != '+' && c != '@' && c != 'n' && c != 'b')
		return (1);
	return (0);
}
