# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 18:24:31 by agautier          #+#    #+#              #
#    Updated: 2021/05/25 22:13:23 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO: norme because SRC need to be explicit
# TODO: remove fsanitize

NAME		=	push_swap
SRC			=	$(wildcard $(addprefix src/, $(addsuffix .c, */*))) \
				$(wildcard $(addprefix src/, $(addsuffix .c, *)))
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -Ilibft/header
LIB			=	-Llibft
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $(OBJ) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

libft:
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY:	all libft clean fclean re

