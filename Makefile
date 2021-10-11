# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 18:24:31 by agautier          #+#    #+#              #
#    Updated: 2021/10/11 17:24:08 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC			=	src/sort/find_max.c \
				src/sort/sort_two.c \
				src/sort/sort_five.c \
				src/sort/quick_sort.c \
				src/sort/sort_three.c \
				src/sort/insertion_sort.c \
				src/sort/sort_very_small.c \
				\
				src/exit/exit.c \
				\
				src/opti/out.c \
				src/opti/delete.c \
				src/opti/convert.c \
				\
				src/parse/parse.c \
				src/parse/update_set.c \
				\
				src/utils/is_in_a.c \
				src/utils/find_min.c \
				src/utils/bigs_in_a.c \
				src/utils/invert_op.c \
				src/utils/is_sorted.c \
				src/utils/print_out.c \
				src/utils/adapt_size.c \
				src/utils/find_intervall.c \
				src/utils/get_median.c \
				src/utils/get_fastest_op.c \
				src/utils/smalls_in_b_is.c \
				src/utils/smalls_in_b_qs.c \
				src/utils/get_greater_pivot.c \
				\
				src/instruction/pa.c \
				src/instruction/pb.c \
				src/instruction/ra.c \
				src/instruction/rb.c \
				src/instruction/rr.c \
				src/instruction/rra.c \
				src/instruction/rrb.c \
				src/instruction/rrr.c \
				src/instruction/sa.c \
				src/instruction/sb.c \
				src/instruction/ss.c \
				\
				src/main.c
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -Ilibft/header
LIB			=	-Llibft
CFLAGS		=	-Wall -Wextra -Werror

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

