# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/09/22 17:35:25 by sguilher         ###   ########.fr        #
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

SRCS =			main.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		minirt.h
VPATH	=		src
INCLUDE	=		-I ./ -I ./includes -I $(LIBFT_PATH) -I $(MLX_PATH)

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g -O3 #-fsanitize=leak
MLXFLAGS =	-lm -lXext -lX11

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# **************************************************************************** #
# rules

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)
	@echo "\033[1;32m"
	@echo "************************************"
	@echo "           miniRT created"
	@echo "************************************"
	@echo "\033[0m"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "\033[1;33mmaking libft....\033[0m"
	$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@echo "\033[1;33mlibft.a created\033[0m"
	@echo "------------------------------------------------------------------"

$(MLX):
	@echo "\033[1;33mmaking minilibx....\033[0m"
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	@echo "\033[1;33mlibmlx.a created\033[0m"
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
