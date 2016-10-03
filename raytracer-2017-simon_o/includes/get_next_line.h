/*
** get_next_line.h for PiRaNhA in /home/cheval_y//wolf
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Fri Jan 11 12:44:06 2013 franck chevallier
** Last update Tue Mar 12 09:53:16 2013 franck chevallier
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# define	READ 4095
# define	BUFF READ + 1

#include <unistd.h>

char	*get_next_line(const int fd);
char	*my_realloc(char *str, int size);
char	*my_strcat(char *dest, char *src);
int	next_line(char *line, char *buff);
int	my_strlen(char *str);

#endif
