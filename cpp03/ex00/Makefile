# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 09:07:01 by mvan-ess          #+#    #+#              #
#    Updated: 2024/05/08 13:44:18 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	claptrap

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
			@rm -rf out

re		:	fclean all

.PHONY	:	all clean fclean re