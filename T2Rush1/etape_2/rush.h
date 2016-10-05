/*
** rush.h for  in /home/daguen_s/rendu/T2Rush1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Mar  7 20:49:48 2014 daguen_s
** Last update Sun Mar  9 19:14:31 2014 daguen_s
*/

#ifndef _RUSH_H_
# define _RUSH_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define USAGE			"./epikong [FILE].\n"
# define FLAG			SDL_HWSURFACE | SDL_DOUBLEBUF

# define VAL_X(x)		(x * 32)
# define VAL_Y(x)		(x * 32)

Mix_Music	*music;
Mix_Chunk	*sound;

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

typedef struct	s_menu
{
  SDL_Surface	*screen;
  SDL_Surface	*button1;
  SDL_Surface	*button2;
  SDL_Surface	*button3;
  SDL_Surface	*button4;
  SDL_Surface	*button5;
}		t_menu;

/* xfunction.c */
int		chosen_map(int x, int y);
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
int             get_map_by_menu();

void		stop();
void		son();
#endif /* _RUSH_H_ */
