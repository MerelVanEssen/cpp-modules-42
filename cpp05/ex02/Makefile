RED 	:= $(shell tput -Txterm setaf 1)
GREEN 	:= $(shell tput -Txterm setaf 2)
YELLOW 	:= $(shell tput -Txterm setaf 3)
WHITE	:= $(shell tput -Txterm setaf 7)
RESET 	:= $(shell tput -Txterm sgr0)

NAME	=	aform

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g3

SRC		=	$(wildcard *.cpp)

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo '${GREEN}Ready with compiling${RESET}'

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
			
clean	:	
			@rm -rf $(OBJ)
			@echo '${RED}Removed files $(OBJ)${RESET}'

fclean	:	clean
			@rm -rf $(NAME)
			@echo '${RED}Removed $(NAME)${RESET}'

re		:	fclean all

.PHONY	:	all clean fclean re

