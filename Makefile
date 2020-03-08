# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 20:41:32 by sjiseong          #+#    #+#              #
#    Updated: 2020/03/07 23:41:01 by sjiseong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c print.c parse_source.c fillit.c board.c

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)

INC = includes/

LIBFT = src/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT) $(SRC_POS)
		$(CC) $(FLAGS) -I $(INC) -c $(SRC_POS)

$(LIBFT):
		make -C ./src/libft

clean:
		rm -f $(OBJ)
			make clean -C ./src/libft

fclean: clean
		rm -f $(NAME)
			make fclean -C ./src/libft

re:	fclean all
