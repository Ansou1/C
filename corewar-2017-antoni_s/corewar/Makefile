##
## Makefile for Makefile in /home/antoni_s//Cproject/testMinilibx
## 
## Made by sebastien antonico
## Login   <antoni_s@epitech.net>
## 
## Started on  Thu Oct 25 15:26:59 2012 sebastien antonico
## Last update Sat Mar 30 23:59:32 2013 sebastien antonico
##

NAME	= corewar

SRC	= main.c \
	  op.c \
	  get_file.c \
	  cycles.c \
	  misc.c \
	  check_live.c \
	  corewar.c \
	  proc.c \
	  reg.c \
	  fight.c \
	  live.c \
	  ld.c \
	  st.c \
	  add.c \
	  sub.c \
	  and.c \
	  xor.c \
	  or.c \
	  fork.c \
	  zjmp.c \
	  ldi.c \
	  sti.c \
	  lld.c \
	  lldi.c \
	  lfork.c \
	  aff.c

OBJ	= $(SRC:.c=.o)

TMP	= $(SRC:.c=.c~) \
	  $(SRC:.c=.h~) \
	  Makefile~

CFLAGS	= -Wall -Wextra
CFLAGS += -pedantic -ansi

LDFLAGS	= -Llibmy -lmy

all:	makelib $(NAME)

makelib:
	(cd libmy;$(MAKE))

fcleanlib:
	(cd libmy;$(MAKE) fclean)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(TMP)

fclean: fcleanlib clean
	rm -f $(NAME)

re: fcleanlib fclean all

.PHONY: re fclean clean all
