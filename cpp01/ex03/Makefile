# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 13:46:19 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/30 08:14:03 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	human

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	$(wildcard *.cpp)

HEADER	=	$(wildcard *.hpp)

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

re		:	fclean all

.PHONY	:	all clean fclean re