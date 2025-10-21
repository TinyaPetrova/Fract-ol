# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 23:28:29 by upetrova          #+#    #+#              #
#    Updated: 2025/08/07 17:46:22 by upetrova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
BONUS_NAME	= fractol_bonus

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= minilibx-linux
MLX		= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
FAST_FLAGS	= -O3 -ffast-math -march=native

SRC		= src/mandatory/main_mandatory.c \
		src/fractals/mandelbrot.c \
		src/fractals/julia.c \
		src/mandatory/draw_mandatory.c \
		src/mandatory/colorizer_mandatory.c \
		src/mandatory/handlers_mandatory.c \
		src/utils/utils.c \
		src/utils/utils_lib.c \
		src/mandatory/utils_print_mandatory.c \
		src/mandatory/utils_init_mandatory.c \
		src/mandatory/validator_mandatory.c

BONUS_SRC	= src/bonus/main_bonus.c \
		src/fractals/mandelbrot.c \
		src/fractals/julia.c \
		src/fractals/spider.c \
		src/fractals/burning_ship.c \
		src/bonus/draw_bonus.c \
		src/bonus/draw_preview_bonus.c \
		src/bonus/colorizer_bonus.c \
		src/bonus/handlers_bonus.c \
		src/bonus/handlers_zoom_bonus.c \
		src/bonus/handlers_key_bonus.c \
		src/bonus/handlers_motion_bonus.c \
		src/utils/utils.c \
		src/utils/utils_lib.c \
		src/bonus/utils_print_bonus.c \
		src/bonus/utils_init_bonus.c \
		src/bonus/validator_bonus.c

OBJ		= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ) fractol.h Makefile
	$(CC) $(CFLAGS) $(FAST_FLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(MLX) $(BONUS_OBJ) fractol.h Makefile
	$(CC) $(CFLAGS) $(FAST_FLAGS) $(BONUS_OBJ) $(MLX) $(MLX_FLAGS) -o $(BONUS_NAME)

both: $(NAME) $(BONUS_NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(FAST_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus both clean fclean re re_bonus re_both
