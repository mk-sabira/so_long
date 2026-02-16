# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 10:44:29 by bmakhama          #+#    #+#              #
#    Updated: 2024/06/03 12:32:47 by bmakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

FT_PRINTF = ft_printf/ft_printf.a

NAME = so_long
SRC = so_long.c get_map_dimension.c move_player.c load_map.c load_image.c validate_path.c collect.c \
	validate_map.c helper_fun.c draw_map.c draw_images.c call_free_map.c error_handle.c error_handle2.c  \
	free_check_map.c ft_calloc.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = ${SRC:.c=.o}
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(FT_PRINTF) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
$(MLX):
	@make -C mlx

$(FT_PRINTF):
	@make -C ft_printf

clean:
	make -C mlx clean
	make -C ft_printf clean
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean
