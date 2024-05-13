# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 07:20:05 by mvan-ess          #+#    #+#              #
#    Updated: 2024/04/19 12:28:34 by mvan-ess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CC		=	c++
FlAGS	=	-Wall -Werror -Wextra -std=c++98

SRC		=	PhoneBook.cpp \
				Contact.cpp \
				main.cpp

OBJ		=	$(SRC:.cpp=.o)

HEADER	=	Contact.hpp \
				PhoneBook.hpp

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