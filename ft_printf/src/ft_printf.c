/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:20:50 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/20 18:27:19 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_format_handler(va_list lst_args, const char format)
{
	int	length_result;

	length_result = 0;
	if (format == 'c')
		length_result += handle_char(va_arg(lst_args, int));
	else if (format == 's')
		length_result += handle_string(va_arg(lst_args, char *));
	else if (format == 'p')
		length_result += handle_pvoid(va_arg(lst_args, void *));
	else if (format == 'i' || format == 'd')
		length_result += handle_int(va_arg(lst_args, int));
	else if (format == 'u')
		length_result += handle_u(va_arg(lst_args, unsigned int));
	else if (format == 'x')
		length_result += handle_hexadecimal(va_arg(lst_args, unsigned int));
	else if (format == 'X')
		length_result += handle_hexadecimal_x(va_arg(lst_args, unsigned int));
	else if (format == '%')
		length_result += handle_wtf();
	return (length_result);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst_args;
	int		length_result;
	int		i;

	va_start(lst_args, s);
	length_result = 0;
	i = 0;
	if (!s)
		return (write(1, "-1", 2), 2);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{	
			length_result += ft_format_handler(lst_args, s[i + 1]);
			i++;
		}
		else
		{
			length_result++;
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(lst_args);
	return (length_result);
}
