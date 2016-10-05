/*
** rush.h for  in /home/daguen_s/rendu/T2Rush1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Mar  7 20:49:48 2014 daguen_s
** Last update Sat Mar  8 10:42:55 2014 daguen_s
*/

#ifndef _RUSH_H_
# define _RUSH_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define USAGE			"./epikong [FILE].\n"
# define FLAG			SDL_HWSURFACE | SDL_DOUBLEBUF

# define VAL_X(x)		(x * 32)
# define VAL_Y(x)		(x * 32)

typedef struct	s_display
{
  SDL_Surface	*screen;
  SDL_Surface	*wall;
  SDL_Surface	*ladder;
  SDL_Surface	*monster;
  SDL_Surface	*the_exit;
  SDL_Surface	*key;
  SDL_Surface	*the_start;
}		t_display;

/* xfunction.c */
void		*xmalloc(size_t taille);
int		xopen(char *pathname, int flags);
int		xclose(int fd);
char		**realloc_tab(char **tab, char *str);
char		**get_map(char *file);
void		my_freetab(char **tab);

/* get_next_line.c */
int		new_line(char *str);
char		*my_cpy(char *buff, char *out);
char		*my_realloc(char *str, int size);
char		*get_next_line(const int fd);

/* display.c */
void		my_sleep();
int		get_h(char **map);
int		get_w(char **map);
void            fill_data(t_display *all);
SDL_Surface     *load_image(char *picture);
int		display_by_sdl(char **map);
void            display_picture(t_display *all, char **map);

/* check_map.c */
int		check_validity_map(char **map);

#endif /* _RUSH_H_ */
