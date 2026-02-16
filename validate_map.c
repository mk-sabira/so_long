/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:27:56 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/01 14:59:02 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(const char *line, int *width)
{
	int	i;

	i = 0;
	while (i < *width)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' \
			&& line[i] != 'P' && line[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

void	exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

void	helper_valid_map(char *line, t_map_elements *elements)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'E')
			elements->exit++;
		else if (line[i] == 'C')
			elements->collect++;
		else if (line[i] == 'P')
			elements->start_pos++;
		i++;
	}
}

void	check_for_null(char *line)
{
	if (line == NULL)
	{
		free(line);
		ft_printf("The map can not be empty!\n");
		exit(1);
	}
}

int	validate_map_elements(const char *filename)
{
	int				fd;
	char			*line;
	t_map_elements	elements;

	elements.exit = 0;
	elements.collect = 0;
	elements.start_pos = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		check_fd();
	line = get_next_line(fd);
	check_for_null(line);
	while (line != NULL)
	{
		helper_valid_map(line, &elements);
		free(line);
		line = get_next_line(fd);
	}
	if (elements.start_pos > 1 || elements.exit > 1)
		exit_error("The map must include only one: P and E");
	if (elements.exit == 0 || elements.collect == 0 || elements.start_pos == 0)
		exit_error("The map must include atleast one: C, E and P");
	return (0);
}
