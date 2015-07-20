##
## Makefile for  in /home/quach_a/Lab/plazza
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Fri Apr 17 14:15:20 2015 Jonathan Quach
## Last update Sun Apr 26 19:20:33 2015 Jonathan Quach
##

NAME		= 	plazza

CPPFLAGS	+= 	-W -Wall -Wextra -Werror -g3

CPP		= 	g++

SRC		= 	main.cpp \
			Americaine.cpp \
			Item.cpp \
			Exception.cpp \
			Fantasia.cpp \
			Margarita.cpp \
			Pizza.cpp \
			Plazza.cpp \
			Regina.cpp \
			Order.cpp \
			Cooker.cpp \
			Kitchen.cpp \
			Fork.cpp \
			Mutex.cpp \
			Pipe.cpp

OBJ		= 	$(SRC:.cpp=.o)

LDFLAGS		=	-pthread -lncurses

RM		= 	rm -f

all		:	$(NAME)

$(NAME)		: 	$(OBJ)
	 		$(CPP) -o $(NAME) $(OBJ) $(LDFLAGS)
clean		:
			$(RM) $(OBJ)

fclean		: 	clean
			$(RM) $(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
