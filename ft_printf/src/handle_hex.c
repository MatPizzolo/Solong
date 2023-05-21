/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:58:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/20 18:25:26 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hexa_len(unsigned int decimal)
{
	int		i;

	i = 0;
	if (decimal < 0)
	{
		decimal *= -1;
		i++;
	}
	while (decimal != 0)
	{
		decimal = decimal / 16;
		i++;
	}
	return (i);
}

void	to_hexa(unsigned int decimal, char *hexa_n, int len)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	temp = 0;
	if (decimal < 0)
	{
		hexa_n[i] = '-';
		decimal *= -1;
		i++;
	}
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa_n[i++] = temp;
		decimal = decimal / 16;
	}
	len = 0;
}

int	handle_hexadecimal(unsigned int s)
{
	int		i;
	int		len;
	char	*a;

	i = handle_zero(s);
	if (i)
		return (i);
	len = hexa_len(s);
	a = (char *)malloc(len + 1);
	if (!a)
		return (0);
	to_hexa(s, a, len);
	if (s < 0)
		reverse_str(a + 1, len);
	else
		reverse_str(a, len);
	i = 0;
	while (i < len)
	{	
		write(1, &a[i], 1);
		i++;
	}
	free(a);
	return (len);
}

void	to_hexa_x(unsigned int decimal, char *hexa_n)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	temp = 0;
	if (decimal < 0)
	{
		hexa_n[i] = '-';
		decimal *= -1;
		i++;
	}
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_n[i++] = temp;
		decimal = decimal / 16;
	}
}

int	handle_hexadecimal_x(unsigned int s)
{
	int		i;
	int		len;
	char	*a;

	i = handle_zero(s);
	if (i)
		return (i);
	len = hexa_len(s);
	a = malloc(len + 1);
	if (!a)
		return (0);
	to_hexa_x(s, a);
	if (s < 0)
		reverse_str(a + 1, len);
	else
		reverse_str(a, len);
	i = 0;
	while (i < len)
	{	
		write(1, &a[i], 1);
		i++;
	}
	free(a);
	return (len);
}
