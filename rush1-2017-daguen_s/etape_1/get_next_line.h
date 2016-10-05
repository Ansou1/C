/*
** get_next_line.h for get_next_line.h in /home/daguen_s//get_next_line2/1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Nov 25 11:27:59 2012 simon daguenet
** Last update Sun Dec  2 16:55:10 2012 simon daguenet
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# define	READ_S 1000
# define	BUFF_S READ_S + 1

char	*get_next_line(const int fd);
int	check_line(char *line, char *buff);
char	*my_realloc(char *str, int size);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
void    my_putchar(char c);
void    my_putstr(char *str);
int     my_getnbr(char *str);
char    *my_strcat1(char *dest, char *src);
char    *my_strdup(char *src);

#endif
