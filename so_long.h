/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:42:44 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/03 17:28:08 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
1
# include "./mlx/mlx.h"
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 60
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	int		fd;
	int		x;
	int		y;
	int		width;
	int		height;
	int		map_height;
	int		map_width;
	char	**map;
	int		move_count;
	int		count_collect;
	int		is_valid;
	char	**copy_map;
}	t_data;

typedef struct s_map_elements
{
	int	exit;
	int	collect;
	int	start_pos;
	int	y;
	int	x;
}	t_map_elements;

typedef struct map_dimen
{
	int		fd;
	char	*line;
	char	*last_line;
	int		line_width;
	int		width;
	int		height;
}	t_map_dimen;

// error check
void	check_fd(void);
void	check_first_line(char *line, int *width, int fd);
void	check_last_line(char *line, char *last_line, int *width);
void	check_left_right(char *line, char *last_line, int line_width, int fd);
void	check_for_null(char *line);
void	check_line_width(char *line, char *last_line, int fd, int *width);
void	check_valid_map(char *line, char *last_line, int *width, int fd);

//free memory
void	free_map_helper(t_data *data);
void	free_check_map(t_data *data);
void	call_free_map(t_data *data);
void	free_get_next_line(char *line, int fd);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *ptr, size_t len);
void	*ft_memset(void *ptr, int c, size_t len);

// map
void	get_map_dimension(const char *filename, int *width, int *height);
void	move_player(t_data *data, int new_x, int new_y);
void	draw_map(t_data *data);
void	load_map(const char *filename, t_data *data);
int		count_collect(t_data *data);
void	copy_map(t_data *data);
void	validate_path(t_data *data, int y, int x);
int		validate_map(const char *line, int *width);
int		validate_map_elements(const char *filename);
int		validate_file_extention(const char *filename);

//helper fun
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *s1, const char *s2);

//images
void	load_image(t_data *data);
void	draw_wall(t_data *data, t_map_elements	location);
void	draw_exit_img(t_data *data, t_map_elements	location);
void	draw_collect_img(t_data *data, t_map_elements	location);
void	draw_player_exit(t_data *data);
void	draw_player_img(t_data *data, t_map_elements	location);

void	free_get_next_line(char *line, int fd);

#endif