/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:29:34 by bmakhama          #+#    #+#             */
/*   Updated: 2024/06/03 17:39:07 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_exten(const char *filename)
{
	if (validate_file_extention(filename))
		exit (1);
	if (validate_map_elements(filename))
		exit(1);
}

void	ft_check_fd(t_map_dimen md)
{
	if (md.fd < 0)
	{
		ft_printf("Error opening map");
		exit (1);
	}
}

void read_free_close(t_map_dimen md, int *width)
{
	check_last_line(md.line, md.last_line, width);
	if (md.last_line)
		free(md.last_line);
	close(md.fd);
}

void free_last(char *last_line)
{
	free(last_line);
	last_line = NULL;
}

void	get_map_dimension(const char *filename, int *width, int *height)
{
	t_map_dimen	md;

	valid_map_exten(filename);
	md.fd = open(filename, O_RDONLY);
	ft_check_fd(md);
	md.line = get_next_line(md.fd);
	*height = 0;
	*width = (int)ft_strlen(md.line) - 1;
	check_first_line(md.line, width, md.fd);
	md.last_line = NULL;
	while (md.line)
	{
		(*height)++;
		md.line_width = ft_strlen(md.line) - 1;
		if (md.line[md.line_width] != '\n')
			md.line_width = ft_strlen(md.line);
		check_line_width(md.line, md.last_line, md.fd, width);
		check_left_right(md.line, md.last_line, md.line_width, md.fd);
		check_valid_map(md.line, md.last_line, width, md.fd);
		free_last(md.last_line);
		md.last_line = md.line;
		md.line = get_next_line(md.fd);
	}
	read_free_close(md, width);
}
