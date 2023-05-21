/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:08:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/04 02:20:58 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_left(t_image *milei, t_vars *vars, int **matrix, t_map map)
{
	int	moved;
	int	x;
	int	y;

	if (!check_collectables(&map, matrix)
		&& (matrix[(milei->y_pos / 50)][(milei->x_pos / 50) - 1] == 4))
		return (0);
	if (matrix[(milei->y_pos / 50)][(milei->x_pos / 50) - 1] == 1)
		return (0);
	moved = 1;
	put_street(*vars, milei->x_pos, milei->y_pos);
	matrix[(milei->y_pos / 50)][(milei->x_pos / 50) - 1] = 2;
	milei->x_pos -= 50;
	x = milei->x_pos;
	y = milei->y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, milei->img, x, y);
	return (moved);
}

int	move_right(t_image *milei, t_vars *vars, int **matrix, t_map map)
{
	int	moved;
	int	x;
	int	y;

	if (!check_collectables(&map, matrix)
		&& (matrix[(milei->y_pos / 50)][(milei->x_pos / 50) + 1] == 4))
		return (0);
	if (matrix[(milei->y_pos / 50)][(milei->x_pos / 50) + 1] == 1)
		return (0);
	moved = 1;
	put_street(*vars, milei->x_pos, milei->y_pos);
	matrix[(milei->y_pos / 50)][(milei->x_pos / 50) + 1] = 2;
	milei->x_pos += 50;
	x = milei->x_pos;
	y = milei->y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, milei->img, x, y);
	return (moved);
}

int	move_top(t_image *milei, t_vars *vars, int **matrix, t_map map)
{
	int	moved;
	int	x;
	int	y;

	if (!check_collectables(&map, matrix)
		&& (matrix[(milei->y_pos / 50) + 1][(milei->x_pos / 50)] == 4))
		return (0);
	if (matrix[(milei->y_pos / 50) + 1][(milei->x_pos / 50)] == 1)
		return (0);
	moved = 1;
	put_street(*vars, milei->x_pos, milei->y_pos);
	matrix[(milei->y_pos / 50) + 1][(milei->x_pos / 50)] = 2;
	milei->y_pos += 50;
	x = milei->x_pos;
	y = milei->y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, milei->img, x, y);
	return (moved);
}

int	move_bottom(t_image *milei, t_vars *vars, int **matrix, t_map map)
{
	int	moved;
	int	x;
	int	y;

	if (!check_collectables(&map, matrix)
		&& (matrix[(milei->y_pos / 50) - 1][(milei->x_pos / 50)] == 4))
		return (0);
	if (matrix[(milei->y_pos / 50) - 1][(milei->x_pos / 50)] == 1)
		return (0);
	moved = 1;
	put_street(*vars, milei->x_pos, milei->y_pos);
	matrix[(milei->y_pos / 50) - 1][(milei->x_pos / 50)] = 2;
	milei->y_pos -= 50;
	x = milei->x_pos;
	y = milei->y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, milei->img, x, y);
	return (moved);
}
