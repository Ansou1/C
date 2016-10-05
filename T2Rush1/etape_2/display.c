/*
** display.c for  in /home/daguen_s/rendu/T2Rush1/etape_1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Mar  7 22:00:22 2014 daguen_s
** Last update Sun Mar  9 20:01:02 2014 daguen_s
*/

#include "rush.h"

void		my_sleep()
{
  int		go;
  SDL_Event	event;

  go = 1;
  while (go)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	go = 0;
      else if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    go = 0;
	}
    }
}

void		display_picture(t_display *all, char **map)
{
  int		tab[2];
  SDL_Rect	position;

  tab[1] = -1;
  while (++tab[1] < get_h(map))
    {
      tab[0] = -1;
      while (++tab[0] < get_w(map))
	{
	  position.y = tab[1] * 32;
	  position.x = tab[0] * 32;
	  if (map[tab[1]][tab[0]] == 'w')
	    SDL_BlitSurface(all->wall, NULL, all->screen, &position);
	  if (map[tab[1]][tab[0]] == 's')
	    SDL_BlitSurface(all->ladder, NULL, all->screen, &position);
	  if (map[tab[1]][tab[0]] == 'm')
	    SDL_BlitSurface(all->monster, NULL, all->screen, &position);
	  if (map[tab[1]][tab[0]] == 'o')
	    SDL_BlitSurface(all->the_exit, NULL, all->screen, &position);
	  if (map[tab[1]][tab[0]] == 'i')
	    SDL_BlitSurface(all->the_start, NULL, all->screen, &position);
	  if (map[tab[1]][tab[0]] == 'k')
	    SDL_BlitSurface(all->key, NULL, all->screen, &position);
	}
    }
}

int		display_by_sdl(char **map)
{
  t_display	*all;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (fprintf(stderr, "ERROR: %s.\n", SDL_GetError()));
  SDL_WM_SetCaption("epikong", NULL);
  all = xmalloc(sizeof(*all));
  if (!(all->screen = SDL_SetVideoMode(VAL_X(get_w(map)),
				       VAL_Y(get_h(map)), 32, FLAG)))
    return (fprintf(stderr, "ERROR: %s\n", SDL_GetError()));
  SDL_FillRect(all->screen, NULL, SDL_MapRGB
	       (all->screen->format, 255, 255, 255));
  fill_data(all);
  display_picture(all, map);
  SDL_Flip(all->screen);
  son();
  my_sleep();
  stop();
  my_freetab(map);
  return (0);
}
