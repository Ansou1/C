##
## Makefile for pouet in /home/efilon/Projects/Cproject/Tests/sockets
## 
## Made by sebastien antonico
## Login   <antoni_s@epitech.net>
## 
## Started on  Wed Apr 24 17:50:24 2013 sebastien antonico
## Last update Thu Apr 25 15:49:44 2013 sebastien antonico
##

NAME_GEN	= gen

SRC_GEN	= main.c get_next_line.c match.c

OBJ_GEN	= $(SRC_GEN:.c=.o)

all:	$(NAME_GEN)

$(NAME_GEN):	$(OBJ_GEN)
		cc -o $(NAME_GEN) $(OBJ_GEN)


clean:
	rm -f $(OBJ_GEN)

fclean: clean
	rm -f $(NAME_GEN)

re: fclean all