/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:46:53 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/03 17:22:53 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_fd(void)
{
	ft_printf("Error reading map");
	exit (1);
}

void	check_first_line(char *line, int *width, int fd)
{
	int	i;

	i = 0;
	while (i < *width)
	{
		if (line && line[i] != '1' )
		{
			ft_printf("f_l: Map is not closed/surrounded by walls\n");
			free_get_next_line(line, fd);
			close(fd);
			exit(1);
		}
		i++;
	}
}

void	check_last_line(char *line, char *last_line, int *width)
{
	int	i;

	i = 0;
	while (i < *width)
	{
		if (last_line && last_line[i] != '1')
		{
			ft_printf("l_l: Map is not closed/surrounded by walls\n");
			free(line);
			line = NULL;
			free(last_line);
			last_line = NULL;
			exit(1);
		}
		i++;
	}
}

void	check_left_right(char *line, char *last_line, int line_width, int fd)
{
	if (line && (line[0] != '1' || line[line_width - 1] != '1'))
	{
		ft_printf("L_R: Map is not closed/surrounded by walls\n");
		free_get_next_line(line, fd);
		line = NULL;
		free(last_line);
		last_line = NULL;
		exit(1);
	}
}

void	free_get_next_line(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}
