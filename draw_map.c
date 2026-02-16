/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:45:28 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/31 11:10:07 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	t_map_elements	location;

	location.y = 0;
	while (location.y < data->map_height)
	{
		location.x = 0;
		while (location.x < data->map_width)
		{
			if (data->map[location.y][location.x] == '1')
				draw_wall(data, location);
			else if (data->map[location.y][location.x] == 'E')
				draw_exit_img(data, location);
			else if (data->map[location.y][location.x] == 'K')
				draw_player_exit(data);
			else if (data->map[location.y][location.x] == 'C')
				draw_collect_img(data, location);
			else if (data->map[location.y][location.x] == 'P')
				draw_player_img(data, location);
			location.x++;
		}
		location.y++;
	}
}
