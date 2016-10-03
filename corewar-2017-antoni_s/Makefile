##
## Makefile for Makefile in /home/antoni_s//Cproject/testMinilibx
## 
## Made by sebastien antonico
## Login   <antoni_s@epitech.net>
## 
## Started on  Thu Oct 25 15:26:59 2012 sebastien antonico
## Last update Sat Mar 30 21:49:16 2013 sebastien antonico
##

all:	makeasm makevm

makeasm:
	(cd asm;$(MAKE))

makevm:
	(cd corewar;$(MAKE))

fcleanasm:
	(cd asm;$(MAKE) fclean)

fcleanvm:
	(cd corewar;$(MAKE) fclean)

cleanasm:
	(cd asm;$(MAKE) clean)

cleanvm:
	(cd corewar;$(MAKE) clean)

clean:	cleanvm cleanasm

fclean: fcleanvm fcleanasm

re: fclean all

.PHONY: re fclean clean cleanvm cleanasm fcleanvm fcleanasm makevm makeasm all
