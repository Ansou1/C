/*
** get_next_line.h for get_next_line.h in /home/daguen_s//get_next_line2/1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Nov 25 11:27:59 2012 simon daguenet
** Last update Sun Dec  9 20:58:27 2012 simon daguenet
*/

typedef struct s_var
{
  int   x;
  int   y;
  int   save_x;
  int   save_y;
  int   save_square;
}       t_data;

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# define	READ_S 1000
# define	BUFF_S READ_S + 1

char	*get_next_line(const int fd);
int	check_line(char *line, char *buff);
char	*my_realloc(char *str, int size);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
int     my_getnbr(char *str);
char    *my_strdup(char *src);
int     get_line(char *av);
char    **get_file(char *av, char **tab, int nbr_line);
void    get_square(t_data *elem, char **tab, int nbr_line);
void    get_files(char **tab, int nbr_line);

#endif
