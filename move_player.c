/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:40:33 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/01 15:00:09 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_is_reached(t_data *data)
{
	ft_printf("You won!");
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

void	reach_e(t_data *data, int new_x, int new_y)
{
	if (data->count_collect == 0)
	{
		exit_is_reached(data);
		exit (0);
	}
	else
	{
		ft_printf("collect c\n");
		data->map[data->y][data->x] = '0';
		data->map[new_y][new_x] = 'K';
		data->x = new_x;
		data->y = new_y;
		data->move_count++;
		// ft_printf("Step: %d\n", data->move_count);
		mlx_clear_window(data->mlx, data->win);
		draw_map(data);
		return ;
	}
}

void	reach_k(t_data *data, int new_x, int new_y)
{
	data->map[data->y][data->x] = 'E';
	data->map[new_y][new_x] = 'P';
	data->x = new_x;
	data->y = new_y;
	data->move_count++;
	// ft_printf("Step: %d\n", data->move_count);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}

void	move_player(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] != '1')
	{
		
		if (data->map[new_y][new_x] == 'C')
			data->count_collect--;
		if (data->map[new_y][new_x] == 'E')
			reach_e(data, new_x, new_y);
		else if (data->map[data->y][data->x] == 'K')
			reach_k(data, new_x, new_y);
		else
		{
			data->map[data->y][data->x] = '0';
			data->map[new_y][new_x] = 'P';
			data->x = new_x;
			data->y = new_y;
			data->move_count++;
			mlx_clear_window(data->mlx, data->win);
			draw_map(data);
		}
		ft_printf("Step: %d\n", data->move_count);
	}
}
