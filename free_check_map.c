/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:20:36 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/02 11:22:38 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	while (data && data->map && data->map[i])
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	if (data && data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	i = 0;
	while (data && data->copy_map && data->copy_map[i])
	{
		free(data->copy_map[i]);
		data->copy_map[i] = NULL;
		i++;
	}
	if (data && data->copy_map)
		free_map_helper(data);
}
