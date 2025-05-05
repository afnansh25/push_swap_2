# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 19:57:49 by ashaheen          #+#    #+#              #
#    Updated: 2025/05/04 19:57:52 by ashaheen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c init.c ft_atoi.c parsing.c check_errors.c ft_split.c push.c swap.c rotate.c rrotate.c sorts.c radix_sort.c sort_utils.c str_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean: 
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
