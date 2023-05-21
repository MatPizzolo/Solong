/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:56:43 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:24 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vars static	g_vaars;
int static		**g_matrix;
int static		g_moves;
t_map static	g_maap;

int	move_player(t_image *milei, int move_to, int **matrix, t_map map)
{
	int	moved;

	moved = 0;
	if (move_to == 1)
		moved = move_left(milei, &g_vaars, matrix, map);
	else if (move_to == 2)
		moved = move_right(milei, &g_vaars, matrix, map);
	else if (move_to == 3)
		moved = move_top(milei, &g_vaars, matrix, map);
	else if (move_to == 4)
		moved = move_bottom(milei, &g_vaars, matrix, map);
	return (moved);
}

int	key_hook(int keycode, t_image *milei)
{
	int	last;

	last = g_moves;
	if (keycode == 53)
		close_window(&g_vaars, g_matrix, &g_maap);
	else if (keycode == 13)
		g_moves += move_player(milei, 4, g_matrix, g_maap);
	else if (keycode == 1)
		g_moves += move_player(milei, 3, g_matrix, g_maap);
	else if (keycode == 2)
		g_moves += move_player(milei, 2, g_matrix, g_maap);
	else if (keycode == 0)
		g_moves += move_player(milei, 1, g_matrix, g_maap);
	if (last != g_moves)
	{
		ft_printf("moves: %i\n", g_moves);
		if (check_win(&g_maap, g_matrix))
		{
			ft_printf("YOU WIN\n");
			close_window(&g_vaars, g_matrix, &g_maap);
		}
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_vars	vars;
	t_image	milei;
	t_map	map;
	char	*path_to_file;

	if (argc != 2)
		return (0);
	start_map_struct_vars(&map);
	path_to_file = check_map(argv[1], &map);
	if (!path_to_file)
		return (0);
	vars.mlx = mlx_init();
	g_matrix = start_map(&vars, &milei, path_to_file, &map);
	if (!g_matrix)
		return (close_no_destroy_window(g_matrix, &map), 0);
	if (!is_playable(g_matrix, &map))
		return (close_window_no_free(&vars), 0);
	g_vaars = vars;
	g_maap = map;
	mlx_hook(vars.win, 17, 0, close_window_no_free, &vars);
	mlx_key_hook(vars.win, key_hook, &milei);
	mlx_loop(vars.mlx);
}
