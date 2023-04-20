/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <abruere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:24:05 by abruere           #+#    #+#             */
/*   Updated: 2023/04/20 14:55:53 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	l_s1;
	char	*s;
	size_t	i;

	l_s1 = ft_strlen(s1);
	s = ft_calloc(1, l_s1 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < l_s1)
	{
		s[i] = s1[i];
		i++;
	}
	return (s);
}
