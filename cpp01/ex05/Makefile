# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 10:33:18 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/30 08:32:28 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	harl

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	$(wildcard *.cpp)

HEADER	=	Harl.hpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o		:	%.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			@rm -rf $(OBJ)

fclean	:	clean 
			@rm -rf $(NAME)
			@rm -rf out

re		:	fclean all

.PHONY	:	all clean fclean re