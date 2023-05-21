/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:30:32 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/11 12:43:41 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_map_vars(char **title, int *i, int *z)
{
	*title = "Destruyendo el banco central";
	*i = -1;
	*z = 0;
}

void	fill_matrix_row(char *line, int *matrix_row, int row_len)
{
	int	i;

	i = 0;
	while (i < row_len && line[i])
	{
		if (line[i] == '1')
			matrix_row[i] = 1;
		else if (line[i] == '0')
			matrix_row[i] = 8;
		else if (line[i] == 'C')
			matrix_row[i] = 3;
		else if (line[i] == 'E')
			matrix_row[i] = 4;
		else if (line[i] == 'P')
			matrix_row[i] = 2;
		i++;
	}
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	start_map_struct_vars(t_map *map)
{
	map->row_len = 0;
	map->rows = 0;
	map->is_player = 0;
	map->is_exit = 0;
	map->is_collectable = 0;
	map->is_non_valid_char = 0;
}
