##
## Makefile for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
##
## Made by corrad_f
## Login   <corrad_f@epitech.net>
##
## Started on  Wed Apr 30 12:37:46 2014 corrad_f
## Last update Wed Apr 30 15:49:18 2014 daguenet
##

SRC=		pop.c\
		push.c\
		algorithm.c\
		get_elements.c\
		capacity.c\
		container.c

INCLUDE=list.h

CFLAGS=-Wall -Wextra

LDFLAGS=

OBJ=$(SRC:.c=.o)

NAME=liblinklist.so

PREPROCESSOR=$(SRC:.c=.i)

ASM=$(SRC:.c=.s)

all: $(NAME)

full: $(NAME) asm preprocessor

preprocessor:$(PREPROCESSOR)

%.i: %.c $(INCLUDE)
	gcc -E $(@:.i=.c) > $@

asm:$(ASM)

%.s: %.c $(INCLUDE)
	gcc -S $<

export:
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(PWD)

#linking project
$(NAME):$(OBJ)
	gcc -shared -Wl,-soname,$@ -o $@ $^ -lc $(LDFLAGS)

#object Generation
%.o: %.c $(INCLUDE)
	gcc -fPIC -g -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	@rm -f $(addsuffix .gch, $(INCLUDE))
	@rm -f $(ASM)
	@rm -f $(PREPROCESSOR)

fclean: clean
	rm -f $(NAME)

re: fclean all

backup: $(SRC) $(INCLUDE)
	tar -cf $(addsuffix .tar, $(NAME)) $^ Makefile

help:
	@echo -e make option:
	@echo -e all
	@echo -e file.c
	@echo -e file.s
	@echo -e file.i
	@echo -e file.o
	@echo -e file.h
	@echo -e preprocessor
	@echo -e asm
	@echo -e clean
	@echo -e fclean
	@echo -e cache
	@echo -e clean_cache
	@echo -e rebuild
	@echo -e backup

.PHONY: clean fclean help re
