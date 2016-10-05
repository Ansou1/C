##
## Makefile for  in /home/daguen_s/rendu/nm-objdump
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Fri Mar  7 19:45:02 2014 daguen_s
## Last update Sun Mar 16 22:10:34 2014 daguen_s
##

COMP=	cc

RM=	rm -f

NAME1=	my_objdump

SRC1=	./src_obj/main.c\
	./src_obj/obj_32.c\
	./src_obj/obj_64.c\
	./src_obj/print_obj_32.c\
	./src_obj/print_obj_64.c\
	./src_obj/xfunction.c

OBJ1=	$(SRC1:.c=.o)

NAME2=	my_nm

SRC2=	./src_nm/nm.c\
	./src_nm/main.c\
	./src_nm/xfunction.c

OBJ2=	$(SRC2:.c=.o)

all:	nm objdump

nm:	$(NAME2)

objdump:	$(NAME1)

$(NAME1):	$(OBJ1)
	@$(COMP) -o $(NAME1) $(OBJ1)

$(NAME2):	$(OBJ2)
	@$(COMP) -o $(NAME2) $(OBJ2)

clean:
	@$(RM) $(OBJ1) $(OBJ2)

fclean:	clean
	@$(RM) $(NAME1) $(NAME2)

re:	fclean all
