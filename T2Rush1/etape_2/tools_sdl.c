/*
** tools_sdl.c for  in /home/daguen_s/rendu/T2Rush1/etape_1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar  8 10:34:11 2014 daguen_s
** Last update Sat Mar  8 10:34:56 2014 daguen_s
*/

#include "rush.h"

int		get_h(char **map)
{
  int		i;

  i = 0;
  while (map[i])
    i++;
  return (i);
}

int		get_w(char **map)
{
  return (strlen(map[0]));
}

SDL_Surface	*load_image(char *picture)
{
  SDL_Surface	*loadedImage;
  SDL_Surface	*optimizedImage;

  loadedImage = NULL;
  optimizedImage = NULL;
  loadedImage = IMG_Load(picture);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      SDL_FreeSurface(loadedImage);
    }
  return (optimizedImage);
}

void		fill_data(t_display *all)
{
  all->wall = load_image("./img/wall.png");
  all->ladder = load_image("./img/ladder.png");
  all->monster = load_image("./img/monster.png");
  all->the_exit = load_image("./img/the_exit.png");
  all->key = load_image("./img/key.png");
  all->the_start = load_image("./img/the_start.png");
}
