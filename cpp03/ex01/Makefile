NAME	:= ScavTrap

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

SRC		:= 	main.cpp ClapTrap.cpp ScavTrap.cpp

INCLUDE	:=	ClapTrap.hpp \

OBJ		:=$(SRC:.cpp=.o)

###########################################################

all: $(NAME)

$(NAME): $(OBJ) ${INCLUDE} 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re