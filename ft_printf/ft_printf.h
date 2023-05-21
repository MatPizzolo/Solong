/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:05:37 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:56 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(char const *s, ...);

int		ft_format_handler(va_list lst_args, const char format);

int		handle_char(int s);

int		handle_string(char *s);

int		handle_pvoid(void *s);

char	*cut_zeroes(char *s);

int		handle_int(int s);

int		handle_u(unsigned int s);

int		count_digits(int n);

int		handle_zero(int s);

void	alocating_nums(int s, char *a, int len);

int		handle_hexadecimal(unsigned int s);

void	to_hexa(unsigned int decimal, char *hexa_n, int len);

int		handle_hexadecimal_x(unsigned int s);

void	to_hexa_x(unsigned int decimal, char *hexa_n);

int		handle_decimal_ns(int s);

int		handle_wtf(void);

void	reverse_str(char *str, int xx);

size_t	ft_strllen(const char *s, int len);

#endif