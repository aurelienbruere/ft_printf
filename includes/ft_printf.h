/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:15:28 by abruere           #+#    #+#             */
/*   Updated: 2023/04/20 14:56:28 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *str, ...);

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *msg, int fd);
void	ft_parsing(int *i, int e, const char *s, va_list args);
int		ft_putc(char c, int *e, int fd);
int		ft_puts(char *str, int *e, int fd);
int		ft_putp(long long p, int *e, int fd);
int		ft_putx(uint64_t nb, char flag, int *e, int fd);
int		ft_putdiu(long long n, char flag, int *e, int fd);
int		ft_putnbr_base_fd(uint64_t nb, int base_len, char *base, int fd);
int		ft_putsignednbr_base_fd(long long nb, int base_len, char *base, int fd);

#endif
