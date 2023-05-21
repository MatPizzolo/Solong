/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:13:07 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/10 16:30:14 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_vars *vars, int **matrix, t_map *map)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_matrix(matrix, map);
	exit(EXIT_FAILURE);
	return (0);
}

int	close_no_destroy_window(int **matrix, t_map *map)
{
	free_matrix(matrix, map);
	exit(EXIT_FAILURE);
	return (0);
}

int	close_window_no_free(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_FAILURE);
	return (0);
}
