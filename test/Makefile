# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 00:25:16 by thbernar          #+#    #+#              #
#    Updated: 2018/10/30 11:35:34 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bmp_parser

SRC = bmp_parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	mv libft/libft.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	gcc -Wall -g -Werror -Wextra -L. -lft $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJ) libft.a

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
