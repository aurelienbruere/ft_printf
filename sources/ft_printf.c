/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:26:28 by abruere           #+#    #+#             */
/*   Updated: 2023/04/20 16:34:18 by abruere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parsing(int *i, int e, const char *s, va_list args)
{
	while (*s && e != -1)
	{
		if (s[0] == '%' && s[1] != '\0' && ft_strchr("cspdiuxX%", s[1]))
		{
			if (s[1] == 'c')
				*i += ft_putc(va_arg(args, int), &e, 1);
			else if (s[1] == 's')
				*i += ft_puts(va_arg(args, char *), &e, 1);
			else if (s[1] == 'p')
				*i += ft_putp(va_arg(args, uint64_t), &e, 1);
			else if (s[1] == 'd' || s[1] == 'i')
				*i += ft_putdiu(va_arg(args, int), s[1], &e, 1);
			else if (s[1] == 'u')
				*i += ft_putdiu(va_arg(args, unsigned), s[1], &e, 1);
			else if (s[1] == 'x' || s[1] == 'X')
				*i += ft_putx(va_arg(args, unsigned), s[1], &e, 1);
			else if (s[1] == '%')
				*i += ft_putc(s[1], &e, 1);
			s += 2;
		}
		else
			*i += ft_putc(s++[0], &e, 1);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		e;
	char	*t;
	va_list	args;

	if (!s)
		return (-1);
	t = ft_strdup(s);
	if (!t)
		return (-1);
	i = 0;
	if (ft_strlen(t) == 1 && t[0] == '%')
		return (free(t), -1);
	else if (ft_strlen(t) >= 2 && t[ft_strlen(t) - 2] != '%'
		&& t[ft_strlen(t) - 1] == '%')
		return (free(t), -1);
	free(t);
	e = 1;
	va_start(args, s);
	ft_parsing(&i, e, s, args);
	va_end(args);
	return (i);
}
