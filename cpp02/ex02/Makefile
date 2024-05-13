# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 11:17:43 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/26 11:17:50 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fixed

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