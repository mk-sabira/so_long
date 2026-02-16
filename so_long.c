/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:43:21 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/03 17:25:07 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_mlx(t_data *data)
{
	int	win_width;
	int	win_height;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error data.mlx");
		exit (1);
	}
	win_width = data->map_width * TILE_SIZE;
	win_height = data->map_height * TILE_SIZE;
	data->win = mlx_new_window(data->mlx, win_width, win_height, "so_long");
	if (!data->win)
	{
		ft_printf("Error data.win");
		exit (1);
	}
}

int	close_window(t_data *data)
{
	ft_printf("ESC or X: Bye!");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_hook(int key_data, t_data *data)
{
	if (key_data == KEY_ESC)
		close_window(data);
	else if (key_data == KEY_A || key_data == LEFT)
		move_player(data, data->x - 1, data->y);
	else if (key_data == KEY_D || key_data == RIGHT)
		move_player(data, data->x + 1, data->y);
	else if (key_data == KEY_W || key_data == UP)
		move_player(data, data->x, data->y - 1);
	else if (key_data == KEY_S || key_data == DOWN)
		move_player(data, data->x, data->y + 1);
	return (0);
}

void	player_initial_position(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
			{
				data->y = y;
				data->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc == 2)
	{
		data.count_collect = 0;
		data.is_valid = 0;
		data.move_count = 0;
		get_map_dimension(arv[1], &data.map_width, &data.map_height);
		load_map(arv[1], &data);
		copy_map(&data);
		player_initial_position(&data);
		validate_path(&data, data.y, data.x);
		if (!data.is_valid)
			return (free_check_map(&data), ft_printf("MAP is not valid\n"), 1);
		initialize_mlx(&data);
		load_image(&data);
		draw_map(&data);
		count_collect(&data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_hook(data.win, 2, 0L, key_hook, &data);
		mlx_loop(data.mlx);
	}
	if (arc != 2)
		return (ft_printf("Arguments must be 2!"), 1);
	call_free_map(&data);
	return (0);
}
