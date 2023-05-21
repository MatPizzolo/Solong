/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:33:59 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/12 09:46:31 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
// # include <unistd.h>

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
	char	*pixels;
	int		x_size;
	int		y_size;
	int		y_pos;
	int		x_pos;
}				t_image;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct m_map {
	int	row_len;
	int	rows;
	int	is_player;
	int	is_exit;
	int	is_collectable;
	int	is_non_valid_char;
}				t_map;

int		move_player(t_image *milei, int move_to, int **matrix, t_map map);

int		close_window(t_vars *vars, int **matrix, t_map *map);

int		close_window_no_free(t_vars *vars);

int		close_no_destroy_window(int **matrix, t_map *map);

t_image	ft_new_sprite(void *mlx, char *path);

int		**start_map(t_vars *vars, t_image *milei,
			char *path_to_file, t_map *map);

int		put_street(t_vars vars, int x_position, int y_position);

int		put_wall(t_vars *vars, int x_position, int y_position);

int		put_coleccionable(t_vars *vars, int x_position, int y_position);

int		put_exit_map(t_vars *vars, int x_position, int y_position);

int		put_player(t_image *milei, t_vars vars, int x_pos, int y_pos);

char	*check_map(char	*path_to_file, t_map *map);

int		is_playable(int	**matrix, t_map *map);

int		check_win(t_map *map, int **matrix);

int		check_collectables(t_map *map, int **matrix);

int		move_left(t_image *milei, t_vars *vars, int **matrix, t_map map);

int		move_right(t_image *milei, t_vars *vars, int **matrix, t_map map);

int		move_top(t_image *milei, t_vars *vars, int **matrix, t_map map);

int		move_bottom(t_image *milei, t_vars *vars, int **matrix, t_map map);

void	free_matrix(int	**matrix, t_map *map);

int		check_row_len(char	*line, int len);

int		check_last_line(char *path, t_map *map);

void	start_map_vars(char **title, int *i, int *z);

void	fill_matrix_row(char *line, int *matrix_row, int row_len);

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

void	start_map_struct_vars(t_map *map);

int		check_win_two(t_map *map, int **matrix);

int		*where_is_p(int **matrix, t_map *map);

int		p_if_possible(int y, int x, int **t_matrix, t_map *map);

void	explore_board(int *p_pos, int **t_matrix, t_map *map);

#endif
