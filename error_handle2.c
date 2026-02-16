

#include "so_long.h"

void	check_line_width(char *line, char *last_line,  int fd, int *width)
{
	int line_width;

	line_width = ft_strlen(line) - 1;
	if (line[line_width] != '\n')
			line_width = ft_strlen(line);
	if (line_width != *width)
	{
		free_get_next_line(line, fd);
		ft_printf("The Map must be rectangular");
		free(last_line);
		exit(1);
	}
}

void	check_valid_map(char *line, char *last_line, int *width, int fd)
{
	if (validate_map(line, width))
	{
		ft_printf("check_v: Map contains invalid characters\n");
		free_get_next_line(line, fd);
		free(last_line);
		exit(1);
	}
}