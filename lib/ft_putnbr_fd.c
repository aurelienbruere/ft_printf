/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <abruere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:06:29 by abruere           #+#    #+#             */
/*   Updated: 2023/04/19 20:59:58 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base_fd(uint64_t nb, int base_len, char *base, int fd)
{
	int	i;
	int	ret_val;

	i = 0;
	if (nb >= (uint64_t)base_len)
		i += ft_putnbr_base_fd(nb / base_len, base_len, base, fd);
	if (i == -1)
		return (i);
	ret_val = write(fd, &base[nb % base_len], 1);
	if (ret_val == -1)
		return (-1);
	i += ret_val;
	return (i);
}

int	ft_putsignednbr_base_fd(long long int nb, int base_len, char *base, int fd)
{
	int	ret_val;
	int	put_ret;

	if (nb >= 0)
		return (ft_putnbr_base_fd(nb, base_len, base, fd));
	ret_val = write(fd, "-", 1);
	if (ret_val == -1)
		return (-1);
	put_ret = 0;
	if (nb <= -base_len)
		put_ret = ft_putnbr_base_fd(nb / -base_len, base_len, base, fd);
	if (put_ret == -1)
		return (-1);
	ret_val += put_ret;
	put_ret = write(fd, &base[-(nb % base_len)], 1);
	if (put_ret == -1)
		return (-1);
	return (ret_val + put_ret);
}
