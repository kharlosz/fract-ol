# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/02 15:17:01 by carodrig          #+#    #+#              #
#    Updated: 2016/06/10 13:56:01 by carodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = fractol

FILES = fractol.c fractal.c fractal1.c julia_hook.c init.c

SRC_FOLDER = sources/

OBJ_FOLDER = build/

SRCS = $(addprefix $(SRC_FOLDER),$(FILES))

OBJS = $(addprefix $(OBJ_FOLDER),$(FILES:.c=.o))

INCLUDES = -I libft/ -I minilibx_macos/

LIBS = -L libft/ -lft -L minilibx_macos/ -lmlx -lm

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJS): $(OBJ_FOLDER)%.o : $(SRC_FOLDER)%.c
	gcc -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

build:
	mkdir -p $(OBJ_FOLDER)
	make -C libft/ re
	make -C minilibx_macos/ re

$(NAME): build $(OBJS)
	gcc -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) $(FRAMEWORK)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJS)
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
