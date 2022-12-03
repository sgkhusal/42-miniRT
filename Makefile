# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/10/08 11:51:591 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			miniRT
NAME_BONUS =			miniRT_bonus

# **************************************************************************** #
LIBFT_PATH =		./libraries/libft
LIBFT =				$(LIBFT_PATH)/libft.a
MLX_PATH =			./libraries/minilibx_linux
MLX		 =			$(MLX_PATH)/libmlx.a
UNIT_TESTS_PATH =	./unit_tests
# **************************************************************************** #
# INPUTS

SRCS =			main.c $(WORLD) $(SHAPES) $(INTERSECT) $(INPUT) $(INPUT_M) \
				$(TUPLES) $(MATRICES) $(UTILS)
WORLD =			world.c transform.c computations.c camera.c light.c reflection.c
SHAPES =		sphere.c cylinder.c objects.c plane.c normal.c material.c
INTERSECT =		ray.c intersection.c hit.c intersect_sort.c
INPUT =			handle_input.c input_file.c handle_ambient.c handle_camera.c \
				handle_sphere.c handle_plane.c handle_cylinder.c \
				validate_utils.c transform_utils.c input_utils.c get_rotation.c
INPUT_M =		handle_content.c handle_light.c
TUPLES =		point.c vector.c vector_and_point_operations.c \
				vector_operations.c
MATRICES =		matrix.c matrix_multiply.c matrix_operations.c \
				matrix_inverse.c matrix_transform.c matrix_rotation.c
UTILS =			utils.c error.c mlx_utils.c colors.c canvas.c plot.c clean.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS	=		minirt.h matrix.h tuples.h mlx_utils.h elements.h utils.h
VPATH	=		includes src src/tuple src/matrix src/input src/objects \
				src/utils src/world
INCLUDE	=		-I./ -I./includes

# bonus
INPUT_B =		handle_content_bonus.c handle_light_bonus.c
SRCS_BONUS =	main.c $(WORLD) $(SHAPES) $(INTERSECT) $(INPUT) $(INPUT_B) \
				$(TUPLES) $(MATRICES) $(UTILS)
OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g -O3 #-fsanitize=leak
MLXFLAGS =	-lm -lXext -lX11

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# colors
YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

# **************************************************************************** #
# rules

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(OBJS_DIR) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "           miniRT created"
	@echo "************************************"
	@echo "$(RESET)"

$(NAME_BONUS):	$(OBJS_DIR) $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "        miniRT_bonus created"
	@echo "************************************"
	@echo "$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)making libft....$(RESET)"
	$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@echo "$(YELLOW)libft.a created$(RESET)"
	@echo "------------------------------------------------------------------"

$(MLX):
	@echo "$(YELLOW)making minilibx....$(RESET)"
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	@echo "$(YELLOW)libmlx.a created$(RESET)"
	@echo "------------------------------------------------------------------"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

test:	$(NAME)
	./$(NAME) scenes/composition.rt

utest:
		@$(MAKE) --no-print-directory -C $(UNIT_TESTS_PATH) test

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
		@$(MAKE) --no-print-directory -C $(MLX_PATH) clean

re:			fclean all

.PHONY: all clean fclean re test utest
