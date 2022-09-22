# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/09/22 15:50:23 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			miniRT

# **************************************************************************** #
LIBFT_PATH =	./libft
LIBFT =			$(LIBFT_PATH)/libft.a
# **************************************************************************** #
# INPUTS

SRCS =			main.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		minirt.h
VPATH	=		src
INCLUDE	=		-I ./ -I ./includes

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g -O3 #-fsanitize=leak

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# **************************************************************************** #
# rules

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LIBFT)
	@echo "\033[1;32m"
	@echo "************************************"
	@echo "           miniRT created"
	@echo "************************************"
	@echo "\033[0m"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo making libft....
	$(MAKE) --no-print-directory -C $(LIBFT_PATH)

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re
