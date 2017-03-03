# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:02:20 by apinchuk          #+#    #+#              #
#    Updated: 2016/12/06 15:12:51 by apinchuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc

SRC_C = file_to_str.c ft_check_last_figure.c ft_compare_tetriminos.c \
		ft_count_words.c ft_generate_empty_field.c conditions_for_check.c \
		ft_memcopy_fields.c ft_put_tetraminos.c ft_remove_ltrs.c \
		ft_sizes.c ft_str_to_list.c ft_strsplit.c ft_validate.c test.c \
		main.c


OBJ = $(SRC_C:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror
HEADER = fillit.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L./../libft -lft -o $(NAME) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
