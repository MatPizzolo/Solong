/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:22:43 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/21 15:18:54 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	allocating_special_nums(int *s, char *a, int *i)
{
	if (*s == 0)
	{
		a[0] = *s + '0';
		(*i)++;
	}
	if (*s < 0)
	{
		a[0] = '-';
		*s *= -1;
		(*i)++;
	}
}

void	alocating_nums(int s, char *a, int len)
{
	int	i;

	i = 0;
	allocating_special_nums(&s, a, &i);
	i = len - 1;
	while (i > -1)
	{
		if (i == 0)
		{
			if (!(a[0] == '-'))
				a[i] = (s % 10) + '0';
		}
		else
			a[i] = (s % 10) + '0';
		s /= 10;
		i--;
	}
	a[len] = '\0';
}

int	handle_zero(int s)
{
	if (s != 0)
		return (0);
	return (write(1, "0", 1), 1);
}

int	handle_min(int s)
{
	int	i;

	i = 0;
	if (s == -2147483648)
		i = handle_string("-2147483648");
	return (i);
}

int	handle_int(int s)
{
	int		i;
	int		len;
	char	*a;

	i = handle_min(s);
	if (i)
		return (i);
	i = handle_zero(s);
	if (i)
		return (i);
	len = count_digits(s);
	a = malloc(len + 1);
	alocating_nums(s, a, len);
	i = 0;
	while (i < len)
	{	
		write(1, &a[i], 1);
		i++;
	}
	free(a);
	return (len);
}
