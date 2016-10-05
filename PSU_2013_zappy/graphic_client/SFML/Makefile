NAME		= client_graphic
RM		= rm -f

CPP		= g++
CXXFLAGS	= -ansi -pedantic -W -Wall -Wextra $(INC) $(LIB) #-Werror
INC		= -I ./include/
LIB		= -Wl,--rpath=./lib/sfml -L ./lib/sfml -lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics -lGL -lX11 -lXrandr -lfreetype

HDR		= $(wildcard *.hh)
SRC		= $(wildcard *.cpp)
OBJ		= $(SRC:.cpp=.o)

$(NAME):	$(HDR) $(OBJ)
		$(CPP) -o $(NAME) $(OBJ) $(CXXFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)


fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re