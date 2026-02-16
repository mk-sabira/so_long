/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:17:37 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/02 11:14:40 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_data *data)
{
	int	i;

	i = 0;
	data->copy_map = ft_calloc(data->map_height + 1, sizeof (char *));
	if (!data->copy_map)
	{
		ft_printf("Error in Allocating mem");
		exit(1);
	}
	while (i < data->map_height)
	{
		data->copy_map[i] = ft_calloc((data->map_width + 2), sizeof (char));
		if (!data->copy_map[i])
		{
			free_check_map(data);
			exit(1);
		}
		ft_strcpy(data->copy_map[i], data->map[i]);
		i++;
	}
}

int	is_valid_path(t_data *data, int y, int x)
{
	int	i;
	int	j;

	if (data->copy_map[y][x] != '1')
	{
		data->copy_map[y][x] = '1';
		i = 1;
		while (i < data->map_height - 1)
		{
			j = 1;
			while (j < data->map_width - 1)
			{
				if (data->copy_map[i][j] == 'E' || data->copy_map[i][j] == 'C')
					return (1);
				j++;
			}
			i++;
		}
		data->is_valid = 1;
	}
	return (0);
}

void	validate_path(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->map_height || x < 0 || x >= data->map_width)
		return ;
	data->copy_map[y][x] = '1';
	if (!data->is_valid && is_valid_path(data, y - 1, x))
		validate_path(data, y - 1, x);
	if (!data->is_valid && is_valid_path(data, y + 1, x))
		validate_path(data, y + 1, x);
	if (!data->is_valid && is_valid_path(data, y, x - 1))
		validate_path(data, y, x - 1);
	if (!data->is_valid && is_valid_path(data, y, x + 1))
		validate_path(data, y, x + 1);
}
