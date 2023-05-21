/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:49:36 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/10 12:01:06 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ACCES NO SE PUEDE USAR !!!!!!
// PROBAR CON UN OPEN SI EL FD ES -1 ...

int	put_street(t_vars vars, int x_pos, int y_pos)
{
	char	*relative_path;
	t_image	street;
	int		fd;

	relative_path = "assets/Tile.xpm";
	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nTile file could not be opened\n"), 1);
	close(fd);
	street = ft_new_sprite(vars.mlx, relative_path);
	street.x_pos = x_pos;
	street.y_pos = y_pos;
	mlx_put_image_to_window(vars.mlx, vars.win, street.img, x_pos, y_pos);
	return (0);
}

int	put_wall(t_vars *vars, int x_pos, int y_pos)
{
	char	*relative_path;
	t_image	wall;
	int		fd;

	relative_path = "assets/Box.xpm";
	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nWall file could not be opened\n"), 1);
	close(fd);
	wall = ft_new_sprite(vars->mlx, relative_path);
	wall.x_pos = x_pos;
	wall.y_pos = y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, wall.img, x_pos, y_pos);
	return (0);
}

int	put_coleccionable(t_vars *vars, int x_pos, int y_pos)
{
	char	*relative_path;
	t_image	bomb;
	int		fd;

	relative_path = "assets/Bomb.xpm";
	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nBomb file could not be opened\n"), 1);
	close(fd);
	bomb = ft_new_sprite(vars->mlx, relative_path);
	bomb.x_pos = x_pos;
	bomb.y_pos = y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, bomb.img, x_pos, y_pos);
	return (0);
}

int	put_exit_map(t_vars *vars, int x_pos, int y_pos)
{
	char	*relative_path;
	t_image	bank;
	int		fd;

	relative_path = "assets/central-bank.xpm";
	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nBank file could not be opened\n"), 1);
	close(fd);
	bank = ft_new_sprite(vars->mlx, relative_path);
	bank.x_pos = x_pos;
	bank.y_pos = y_pos;
	mlx_put_image_to_window(vars->mlx, vars->win, bank.img, x_pos, y_pos);
	return (0);
}
