/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:46:24 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 16:46:26 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_printable(wchar_t *t, int len)
{
	int i;

	i = 0;
	while (len)
	{
		if (t[i] > 255)
			return (0);
		len--;
	}
	return (1);
}
