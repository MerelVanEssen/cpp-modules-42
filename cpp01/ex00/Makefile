# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 12:27:49 by mvan-ess          #+#    #+#              #
#    Updated: 2024/05/06 11:36:37 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	zombie

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	$(wildcard *.cpp)

OBJ		=	$(SRC:.cpp=.o)

HEADER	=	Zombie.hpp

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o		:	%.cpp $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			@rm -rf $(OBJ)

fclean	:	clean 
			@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re