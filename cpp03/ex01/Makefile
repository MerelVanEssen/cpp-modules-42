# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 11:38:23 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/30 12:09:06 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scavtrap

CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC			=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.hpp)

OBJ			=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o		:	%.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
