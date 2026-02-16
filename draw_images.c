/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:08:25 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/31 11:09:57 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_data *data, t_map_elements	location)
{
	mlx_put_image_to_window(data->mlx, data->win, data->wall_img, \
					location.x * TILE_SIZE, location.y * TILE_SIZE);
}

void	draw_exit_img(t_data *data, t_map_elements	location)
{
	mlx_put_image_to_window(data->mlx, data->win, data->exit_img, \
					location.x * TILE_SIZE, location.y * TILE_SIZE);
}

void	draw_collect_img(t_data *data, t_map_elements	location)
{
	mlx_put_image_to_window(data->mlx, data->win, \
			data->collect_img, location.x * TILE_SIZE, location.y * TILE_SIZE);
}

void	draw_player_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->exit_img, \
				data->x * TILE_SIZE, data->y * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->player_img, \
					data->x * TILE_SIZE, data->y * TILE_SIZE);
}

void	draw_player_img(t_data *data, t_map_elements	location)
{
	mlx_put_image_to_window(data->mlx, data->win, \
		data->player_img, location.x * TILE_SIZE, location.y * TILE_SIZE);
}
