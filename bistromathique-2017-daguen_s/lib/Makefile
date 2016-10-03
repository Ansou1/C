##
## Makefile for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
## 
## Made by martial elegbede
## Login   <elegbe_m@epitech.net>
## 
## Started on  Mon Oct 22 08:54:58 2012 martial elegbede
## Last update Sat Nov 10 17:13:17 2012 martial elegbede
##

SRC=	my_find_prime_sup.c\
	my_getnbr.c\
	my_isneg.c\
	my_is_prime.c\
	my_power_rec.c\
	my_putchar.c\
	my_put_nbr.c\
	my_putstr.c\
	my_revstr.c\
	my_showmem.c\
	my_showstr.c\
	my_sort_int_tab.c\
	my_square_root.c\
	my_strcapitalize.c\
	my_strcat.c\
	my_strcmp.c\
	my_strcpy.c\
	my_str_isalpha.c\
	my_str_islower.c\
	my_str_isnum.c\
	my_str_isprintable.c\
	my_str_isupper.c\
	my_strlcat.c\
	my_strlen.c\
	my_strlowcase.c\
	my_strncat.c\
	my_strncmp.c\
	my_strncpy.c\
	my_strstr.c\
	my_strupcase.c\
	my_swap.c\

CFLAGS=	-W -Wall -Wextra -Werror -pedantic

NAME=	libmy.a

OBJ=	$(SRC:.c=.o)

CFLAGS= -I../includes

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp my.h ../includes/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
