# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 13:32:26 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/30 07:44:35 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brain

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	main.cpp 

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