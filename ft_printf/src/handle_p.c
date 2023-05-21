/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/03 13:14:30 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*cut_zeroes(char *s)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] == '0')
		i++;
	result = (char *)malloc(16 + 1);
	if (!result)
		return (write(1, "-1", 2), NULL);
	if (i != 0)
		ft_strlcpy(result, (s + i), 16);
	return (result);
}

int	ft_strlen_no_zeroes(char *s)
{
	int		i;

	i = 0;
	while (s[i] == '0')
		i++;
	return (i);
}

char	*creating_buffer(void *s)
{
	unsigned long long int	p;
	int						i;
	char					*buffer_hex;

	buffer_hex = (char *)malloc(17);
	buffer_hex[16] = '\0';
	p = (unsigned long long int)s;
	i = 15;
	while (i >= 0)
	{
		buffer_hex[i--] = "0123456789abcdef"[p & 15];
		p >>= 4;
	}
	return (buffer_hex);
}

int	handle_pvoid(void *s)
{
	char					*buffer_hex;
	char					*result;
	int						i;
	int						len;

	i = 0;
	if (s == NULL)
		return (i = handle_string("0x0"), i);
	buffer_hex = creating_buffer(s);
	i = ft_strlen_no_zeroes(buffer_hex);
	len = ft_strlen((buffer_hex + i)) + 3;
	result = (char *)malloc(len);
	ft_strlcpy(result, "0x", 3);
	ft_strlcat(result, (buffer_hex + i), (ft_strlen((buffer_hex + i)) + 3));
	free(buffer_hex);
	handle_string(result);
	i = ft_strlen(result);
	free(result);
	return (i);
}
