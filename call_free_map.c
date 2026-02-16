/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:49:49 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/02 11:23:06 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_helper(t_data *data)
{
	free(data->copy_map);
	data->copy_map = NULL;
}

void	call_free_map(t_data *data)
{
	free_check_map(data);
	exit(1);
}
