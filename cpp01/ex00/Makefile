SRC				=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ 			=	$(SRC:.cpp=.o)

CC				= c++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98
NAME			= Zombax

all:			$(NAME)

%.o: %.c
				$(CC) -o $@ -c $< $(CFLAGS)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re