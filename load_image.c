/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:50:02 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/01 14:58:06 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_imag(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

void	load_image(t_data *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", \
											&data->width, &data->height);
	if (!data->wall_img)
		error_imag("Error wall_im");
	data->collect_img = mlx_xpm_file_to_image(data->mlx, "images/collect.xpm", \
												&data->width, &data->height);
	if (!data->collect_img)
		error_imag("Error collect_img");
	data->player_img = mlx_xpm_file_to_image(data->mlx, "images/player.xpm", \
											&data->width, &data->height);
	if (!data->player_img)
		error_imag("Error player_img");
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", \
										&data->width, &data->height);
	if (!data->player_img)
		error_imag("Error player_img");
}
