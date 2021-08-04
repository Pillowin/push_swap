# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:52:43 by agautier          #+#    #+#              #
#    Updated: 2021/08/04 14:33:54 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	$(addprefix src/,			\
				gc/gc_new.c				\
				gc/gc_calloc.c			\
				gc/gc_free.c			\
				gc/gc_clear.c			\
				\
				list/list_new.c			\
				list/node_new.c			\
				list/list_push_front.c	\
				list/list_push_back.c	\
				list/list_merge.c		\
				list/node_del.c			\
				list/get_node_index.c	\
				list/list_print.c		\
				list/list_del.c			\
				list/list_at.c			\
				\
				str/ft_atoi.c			\
				str/ft_strcmp.c			\
				\
				print/ft_putendl_fd.c	\
				\
				is/is_great.c			\
				is/is_int.c				\
			)
OBJ		=	$(SRC:.c=.o)
HEADER	=	header
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
