# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 08:45:38 by mvan-ess          #+#    #+#              #
#    Updated: 2024/05/08 08:45:39 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	diamondtrap

CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -Wshadow

SRC			=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.hpp)

OBJ			=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o		:	%.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all re clean fclean