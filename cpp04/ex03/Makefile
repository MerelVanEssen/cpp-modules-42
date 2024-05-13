NAME		=	character

CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -g3

SRC			=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.hpp)

OBJ			=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o 	:	%.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean	:	
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all re clean fclean