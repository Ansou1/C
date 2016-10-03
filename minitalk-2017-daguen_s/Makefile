##
## Makefile for minitalk in /home/daguen_s//talk
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sat Mar 23 23:55:16 2013 simon daguenet
## Last update Sun Mar 24 00:59:10 2013 simon daguenet
##

COMP=	cc

RM=	rm -f

NAME1=	./serveur/server

SRC1=	./serveur/serveur.c\
	./serveur/print.c\
	./serveur/tools_srv.c\
	./serveur/get_bit.c

OBJ1=	$(SRC1:.c=.o)

NAME2=	./client/client

SRC2=	./client/client.c\
	./client/print.c\
	./client/tools_clt.c

OBJ2=	$(SRC2:.c=.o)

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
	@echo -n "Compilation de $(NAME1)."
	@$(COMP) -o $(NAME1) $(OBJ1)
	@echo " Terminée."

$(NAME2):	$(OBJ2)
	@echo -n "Compilation de $(NAME2)."
	@$(COMP) -o $(NAME2) $(OBJ2)
	@echo " Terminée."

clean:
	@echo -n "Suppression des fichiers objets."
	@$(RM) $(OBJ1) $(OBJ2)
	@echo " Terminée."

fclean:	clean
	@echo -n "Suppression du programme $(NAME)."
	@$(RM) $(NAME1) $(NAME2)
	@echo " Terminée."

re:	fclean all
