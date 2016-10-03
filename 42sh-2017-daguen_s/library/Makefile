##
## Makefile for fdf in /home/corrad_f//fdf-2017-corrad_f/lib
## 
## Made by florian corradin
## Login   <corrad_f@epitech.net>
## 
## Started on  Thu Dec  6 10:54:48 2012 florian corradin
## Last update Thu Apr 25 09:26:29 2013 florian corradin
##

NAME	= libmy.a

SRC	= my_strlen.c\
	  my_putchar.c\
	  array.c\
	  error_malloc.c\
	  my_strcmp.c\
	  get_next_line.c\
	  epur_str.c\
	  my_str_to_word_tab.c\
	  my_getnbr.c\
	  my_put_nbr.c

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: clean $(NAME)
