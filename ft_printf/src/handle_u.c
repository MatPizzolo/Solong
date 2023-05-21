/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:22:43 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/09 16:44:13 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	alocating_nums_long(unsigned int s, char *a, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		a[i] = (s % 10) + '0';
		s /= 10;
		i--;
	}
	a[len] = '\0';
}

int	count_digits_long(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	handle_u(unsigned int s)
{
	int		i;
	int		len;
	char	*a;

	i = handle_zero(s);
	if (i)
		return (i);
	len = count_digits_long(s);
	a = malloc(len + 1);
	alocating_nums_long(s, a, len);
	i = 0;
	while (i < len)
	{
		write(1, &a[i], 1);
		i++;
	}
	free(a);
	return (len);
}
