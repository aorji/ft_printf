/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <aorji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:55:21 by aorji             #+#    #+#             */
/*   Updated: 2019/08/21 21:10:10 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	while (*s1)
	{
		new[i++] = *s1++;
	}
	while (*s2)
	{
		new[i++] = *s2++;
	}
	new[i] = '\0';
	return (new);
}

char		*fstrjoin(char const *s1, char const *s2, size_t len1, size_t len2)
{
	char	*new;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (0);
	while (i < len1)
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (i < len1 +len2)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
