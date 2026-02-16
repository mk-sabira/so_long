/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:46:47 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/02 10:11:10 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_memory(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_data(t_data *data)
{
	free (data);
	error_memory("Error allocating memory\n");
}

void	load_map(const char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		check_fd();
	data->map = ft_calloc((data->map_height + 1), sizeof (char *));
	if (!data->map)
		error_memory("Error allocating memory\n");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map[i] = ft_calloc((data->map_width + 2), (sizeof(char)));
		if (!data->map[i])
			free_data(data);
		ft_strcpy(data->map[i], line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	validate_file_extention(const char *filename)
{
	const char	*check;

	check = ft_strrchr(filename, '.');
	if (!check || ft_strcmp(filename + ft_strlen(filename) - 4, ".ber") != 0)
	{
		ft_printf("Error: File must have a .ber extension\n");
		return (1);
	}
	return (0);
}
