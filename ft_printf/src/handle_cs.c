/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:32:31 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/09 17:08:41 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_char(int s)
{
	return (write(1, &s, 1), 1);
}

int	handle_string(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	handle_wtf(void)
{	
	char	c;
	int		j;
	int		handle_write;

	c = '%';
	j = c;
	handle_write = write(1, &j, 1);
	if (handle_write < 0)
		return (-1);
	return (1);
}
