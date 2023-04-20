/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:37 by abruere           #+#    #+#             */
/*   Updated: 2023/02/25 20:59:26 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*b;

	if (count > 0 && size > SIZE_MAX / count)
		return (NULL);
	b = malloc(count * size);
	if (!b)
		return (NULL);
	ft_memset(b, 0, count * size);
	return ((void *)b);
}
