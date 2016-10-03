##
## Makefile for makefile in /home/daguen_s//my_minishell
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Dec 23 12:50:01 2012 simon daguenet
## Last update Sat Dec 29 14:54:52 2012 simon daguenet
##

SRC=	mysh.c\
	buitin.c\
	my_fonction.c\
	my_print.c\
	my_file.c\
	my_process.c\
	my_str_fonction.c\
	my_str_to_memory.c\
	my_word_tab.c\
	my_word_tab_dbp.c

OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	mysh

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
