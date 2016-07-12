# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/06 14:54:45 by daviwel           #+#    #+#              #
#    Updated: 2016/07/08 22:18:07 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

PATH = src/

SRC = $(PATH)main.c \
	  $(PATH)new_node.c \
	  $(PATH)read_input.c \
	  $(PATH)error.c \
	  $(PATH)fill_nodes.c \
	  $(PATH)free_arr.c \
	  $(PATH)find_elem.c \
	  $(PATH)connect_nodes.c \
	  $(PATH)find_paths.c

OBJ = $(SRC:.c=.o)

ATTACH = -L libft/ -lft

all: $(NAME)

$(NAME):
	clang $(CFLAG) -c $(SRC)
	/bin/mv *.o src/
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) includes/lem_in.h
