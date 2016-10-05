SRC=	read.c\
		log.c\
		connection.c\
		main.c\
		parser.c\
		loop.c\
		buffer.c\
		player.c\
		commande.c\
		string.c\
		team.c\
		execute.c\
		map.c\
		time.c\
		world.c\
		broadcast.c\
		incantation.c\
		monitor.c\
		conf.c\
		config_function.c\
		advance_log.c\
		view.c

INCLUDE=$(wildcard *.h)

CFLAGS=-Wall -Wextra -g

LDFLAGS= -L../liblist -llinklist -lm

OBJ=$(SRC:.c=.o)

NAME=serveur

all: $(NAME)

%.i: %.c $(INCLUDE)
	gcc -E $(@:.i=.c) > $@

#linking project
$(NAME):$(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(PWD)/../liblist

#object Generation
%.o: %.c $(INCLUDE)
	gcc -c $< $(CFLAGS)

backup:
	tar -cf zappy.tar $(SRC) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
