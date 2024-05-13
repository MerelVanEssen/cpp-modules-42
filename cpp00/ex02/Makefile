# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 09:32:33 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/19 10:50:04 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	Account.cpp \
				tests.cpp

OBJ		=	$(SRC:.cpp=.o)

HEADER	=	Account.hpp

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