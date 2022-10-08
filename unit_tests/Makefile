# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by sguilher          #+#    #+#              #
#    Updated: 2022/10/08 15:22:08 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			tests
MINIRT =		minirt
MINIRT_PATH =	../

# **************************************************************************** #
LIBFT_PATH =	../libraries/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		../libraries/minilibx_linux
MLX		 =		$(MLX_PATH)/libmlx.a
# **************************************************************************** #
# INPUTS

SRCS =			main.c \
				unit_tests_utils.c \
				points_unit_test.c \
				vectors_unit_test.c \
				vector_operations_unit_test1.c \
				vector_operations_unit_test2.c \
				points_and_vectors_unit_test.c \
				projectile_test.c \
				ray_unit_test.c \
				sphere_unit_test.c \
				matrix_test.c \
				multiply_test.c \
				submatrix_test.c \
				determinant_test.c \
				cofactor_test.c \
				inverse_test.c \
				translation_test.c \
				scaling_test.c \
				rotation_test.c \
				$(MINIRT_SRCS)
MINIRT_SRCS =	point.c vector.c vector_operations.c utils.c ray.c \
				vector_and_point_operations.c sphere.c colors.c matrix.c \
				matrix_multiply.c matrix_operations.c matrix_inverse.c \
				matrix_transform.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		unit_tests.h
VPATH_MINIRT =	../src/ ../src/tuple ../src/matrix
VPATH	=		$(VPATH_MINIRT) tuples elements ray matrix
INCLUDE	=		-I ./ -I ../ -I ../includes -I $(LIBFT_PATH) -I $(MLX_PATH)

# compilation
CC =		gcc
CFLAGS =	-Werror -Wextra -g -O3 #-fsanitize=leak
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

$(OBJS_DIR)/%.o:	%.c $(HEADERS) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(MINIRT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "         unit_tests created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(MINIRT):
	@echo "$(YELLOW)making minirt....$(RESET)"
	$(MAKE) --no-print-directory -C $(MINIRT_PATH)
	@echo "$(YELLOW)minirt created$(RESET)"
	@echo "------------------------------------------------------------------"

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) -C $(MINIRT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) -C $(MINIRT_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re
