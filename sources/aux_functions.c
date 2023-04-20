/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:26:28 by abruere           #+#    #+#             */
/*   Updated: 2023/04/20 14:48:59 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putc(char c, int *e, int fd)
{
	int	ret_val;

	ret_val = write(fd, &c, 1);
	if (ret_val == -1)
		*e = -1;
	return (ret_val);
}

int	ft_puts(char *str, int *e, int fd)
{
	int	ret_val;

	if (!str)
		return (ft_puts("(null)", e, fd));
	ret_val = write(fd, str, ft_strlen(str));
	if (ret_val == -1)
		*e = -1;
	return (ret_val);
}

int	ft_putdiu(long long n, char flag, int *e, int fd)
{
	int	ret_val;

	if (flag == 'u')
		ret_val = ft_putnbr_base_fd(n, 10, "0123456789", fd);
	else
		ret_val = ft_putsignednbr_base_fd(n, 10, "0123456789", fd);
	if (ret_val == -1)
		*e = -1;
	return (ret_val);
}

int	ft_putx(uint64_t nb, char flag, int *e, int fd)
{
	int	ret_val;

	if (flag == 'x')
		ret_val = ft_putnbr_base_fd(nb, 16, "0123456789abcdef", fd);
	else
		ret_val = ft_putnbr_base_fd(nb, 16, "0123456789ABCDEF", fd);
	if (ret_val == -1)
		*e = -1;
	return (ret_val);
}

int	ft_putp(long long int nb, int *e, int fd)
{
	if (nb == 0)
		return (ft_puts("(nil)", e, fd));
	ft_puts("0x", e, fd);
	return (2 + ft_putx(nb, 'x', e, fd));
}
