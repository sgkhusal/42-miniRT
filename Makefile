# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/10/07 17:54:20 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			miniRT

# **************************************************************************** #
LIBFT_PATH =	./libraries/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		./libraries/minilibx_linux
MLX		 =		$(MLX_PATH)/libmlx.a
# **************************************************************************** #
# INPUTS

SRCS =			main.c handle_input.c mlx_utils.c colors.c utils.c ray.c \
				sphere.c $(TUPLES) $(MATRIX)
TUPLES =		point.c vector.c vector_and_point_operations.c \
				vector_operations.c
MATRICES =		matrix.c matrix_multiply.c matrix_operations.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		minirt.h
VPATH	=		src src/tuple src/matrix
INCLUDE	=		-I ./ -I ./includes -I $(LIBFT_PATH) -I $(MLX_PATH)

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

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "           miniRT created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

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

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) -C $(LIBFT_PATH) clean
		@$(MAKE) -C $(MLX_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re
