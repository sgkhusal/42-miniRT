# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by sguilher          #+#    #+#              #
#    Updated: 2022/11/20 15:08:12 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			unit_test
MINIRT =		../miniRT
MINIRT_PATH =	../

# **************************************************************************** #
LIBFT_PATH =	../libraries/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		../libraries/minilibx_linux
MLX		 =		$(MLX_PATH)/libmlx.a
# **************************************************************************** #
# INPUTS

SRCS =			main.c \
				input_tests.c \
				ft_atod_tests.c \
				validate_input_tests.c \
				transform_input_tests.c \
				unit_tests_utils.c \
				points_unit_test.c \
				vectors_unit_test.c \
				vector_operations_unit_test1.c \
				vector_operations_unit_test2.c \
				points_and_vectors_unit_test.c \
				projectile_test.c \
				matrix_test.c \
				equality_test.c \
				multiply_test_1.c multiply_test_2.c \
				identity_test.c \
				transpose_test.c \
				minor_test.c \
				submatrix_test.c \
				determinant_test_1.c determinant_test_2.c \
				cofactor_test.c \
				inverse_test_1.c inverse_test_2.c inverse_test_3.c \
				translation_test.c \
				scaling_test.c \
				rotation_test.c \
				shearing_test.c \
				chaining_test.c \
				ray_unit_test.c \
				object_unit_test.c \
				sphere_unit_test1.c \
				sphere_unit_test2.c \
				intersection_test.c \
				ray_transform_test.c \
				normal_test.c \
				reflection_test.c \
				light_test.c \
				material_test.c \
				sphere_render_test.c \
				world_test.c \
				computations_test.c \
				cylinder_unit_test1.c \
				cylinder_unit_test2.c \
				cylinder_render_test.c \
				shade_hit_test.c \
				transformation_test.c \
				camera_test.c \
				ray_for_pixel_test.c \
				scene_render_test.c \
				shadow_test.c \
				plane_unit_test.c \
				plane_render_test.c \
				plane_scene_render_test.c \
				$(MINIRT_SRCS)
MINIRT_SRCS =	point.c vector.c vector_operations.c utils.c ray.c error.c \
				vector_and_point_operations.c sphere.c colors.c matrix.c \
				matrix_multiply.c matrix_operations.c matrix_inverse.c \
				matrix_transform.c matrix_rotation.c intersection.c hit.c \
				transform.c normal.c reflection.c material.c light.c \
				handle_input.c input_file.c handle_content.c  validate_utils.c \
				handle_ambient.c handle_camera.c handle_light.c \
				handle_sphere.c handle_plane.c handle_cylinder.c world.c \
				transform_utils.c objects.c ft_atod.c intersect_sort.c \
				computations.c cylinder.c mlx_utils.c canvas.c plot.c plane.c \
				camera.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		unit_tests.h
VPATH_MINIRT =	../src/ ../src/tuple ../src/matrix ../src/input ../src/objects \
				../src/utils ../src/world
VPATH	=		$(VPATH_MINIRT) input tuples elements ray matrix light world \
				render camera
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

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(MINIRT) $(OBJS_DIR) $(OBJS)
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

test:		$(NAME)
		@touch no_permission.rt && chmod 000 no_permission.rt
		./$(NAME) 2> log

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) -C $(MINIRT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		$(RM) log
		$(RM) no_permission.rt
		@$(MAKE) -C $(MINIRT_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re test
