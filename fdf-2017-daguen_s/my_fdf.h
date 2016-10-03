/*
** my_fdf.h for fdf in /home/daguen_s//Ighaph/fdf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec  2 21:36:20 2012 simon daguenet
** Last update Fri Dec  7 18:10:40 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct s_my_var
{
  void	*mlx_ptr;
  void	*win_ptr;
  void	*img;
  unsigned char	*data;
  int	bpp;
  int	sizeline;
  int	endian;
  int	x1;
  int	x2;
  int	y1;
  int	y2;
}	t_element;

#ifndef		MY_FDF_H_
# define	MY_FDF_H_

# define	READ_S 1000
# define	BUFF_S READ_S + 1

char	*get_next_line(const int fd);
int	check_line(char *line, char *buff);
char	*my_realloc(char *str, int size);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	count_word(char *str);
int	countchar(char *str);
char	**my_str_to_wordtab(char *str);
char	*my_strdup(char *src);
char	***get_map(char *av, int i);
int	get_nbr_line(char *av);
void	my_putchar(char c);
void	my_putstr(char *str);
int	display_screen(char ***tab, int i);
int	display_draw(t_element *param, char ***tab, int taille);
int	isometrique(t_element *param, int x, int y, char *z1);
int	gere_expose(t_element *param);
int	draw_base(t_element *param);
int	draw_exeption(t_element *param);
int	draw_cas_seven_eight(t_element *param);
int	draw_cas_five_six(t_element *param);
int	draw_cas_trois_quatre(t_element *param);
int	draw_cas_un_deux(t_element *param);
int	gere_key(int touche);
void	my_pixel_put_to_image(t_element *param, int x, int y);
int	abs(int x);
void    free_tab(char ***tab, int line);

#endif
