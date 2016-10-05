/*
** sdl.c for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Mar 25 13:08:20 2014 daguen_s
** Last update Sat Mar 29 20:34:10 2014 daguen_s
*/

#include "lemipc.h"

void			fill_data(t_lemipc *this)
{
  ALL->team1 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team3 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team4 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team5 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team6 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team7 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team8 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  ALL->team9 = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  SDL_FillRect(ALL->team1, NULL, SDL_MapRGB(ALL->screen->format, 255, 215, 0));
  SDL_FillRect(ALL->team2, NULL, SDL_MapRGB(ALL->screen->format, 255, 0, 0));
  SDL_FillRect(ALL->team3, NULL, SDL_MapRGB(ALL->screen->format, 0, 255, 0));
  SDL_FillRect(ALL->team4, NULL, SDL_MapRGB(ALL->screen->format, 0, 0, 255));
  SDL_FillRect(ALL->team5, NULL, SDL_MapRGB(ALL->screen->format, 255, 51, 255));
  SDL_FillRect(ALL->team6, NULL, SDL_MapRGB(ALL->screen->format, 0, 255, 204));
  SDL_FillRect(ALL->team7, NULL,
	       SDL_MapRGB(ALL->screen->format, 255, 255, 255));
  SDL_FillRect(ALL->team8, NULL, SDL_MapRGB(ALL->screen->format, 51, 102, 102));
  SDL_FillRect(ALL->team9, NULL,
	       SDL_MapRGB(ALL->screen->format, 255, 102, 204));
  ALL->background = SDL_CreateRGBSurface
    (SDL_HWSURFACE, MAP * 5, MAP * 5, 32, 0, 0, 0, 0);
  SDL_FillRect(ALL->background, NULL, SDL_MapRGB(ALL->screen->format, 0, 0, 0));
}

void			display(t_lemipc *this, SDL_Rect position,
				int i, unsigned char *v)
{
  position.x = (i % MAP) * 5;
  position.y = (i / MAP) * 5;
  if (this->map[(position.y / 5 * MAP) + position.x / 5] != IN)
    *v = this->map[(position.y / 5 * MAP) + position.x / 5];
  if (this->map[(position.y / 5 * MAP) + position.x / 5] == 1)
    SDL_BlitSurface(ALL->team1, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 2)
    SDL_BlitSurface(ALL->team2, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 3)
    SDL_BlitSurface(ALL->team3, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 4)
    SDL_BlitSurface(ALL->team4, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 5)
    SDL_BlitSurface(ALL->team5, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 6)
    SDL_BlitSurface(ALL->team6, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 7)
    SDL_BlitSurface(ALL->team7, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 8)
    SDL_BlitSurface(ALL->team8, NULL, ALL->screen, &position);
  else if (this->map[(position.y / 5 * MAP) + position.x / 5] == 9)
    SDL_BlitSurface(ALL->team9, NULL, ALL->screen, &position);
}

unsigned char		display_map(t_lemipc *this)
{
  SDL_Rect		position;
  int			i;
  unsigned char		v;

  v = 0;
  i = 0;
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(ALL->background, NULL, ALL->screen, &position);
  while (i < (MAP * MAP))
    {
      display(this, position, i, &v);
      i++;
    }
  SDL_Flip(ALL->screen);
  return (v);
}

int			init_sdl(t_lemipc *this)
{
  ALL = malloc(sizeof(t_display));
  if (!ALL)
    return (-1);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  SDL_WM_SetCaption("lemipc", NULL);
  if (!(ALL->screen = SDL_SetVideoMode(MAP * 5, MAP * 5, 32, FLAG)))
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  if (SDL_FillRect(ALL->screen, NULL,
		   SDL_MapRGB(ALL->screen->format, 0, 0, 0)) == -1)
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  fill_data(this);
  return (0);
}

void			end_sdl(t_lemipc *this)
{
  SDL_FreeSurface(ALL->team1);
  SDL_FreeSurface(ALL->team2);
  SDL_FreeSurface(ALL->team3);
  SDL_FreeSurface(ALL->team4);
  SDL_FreeSurface(ALL->team5);
  SDL_FreeSurface(ALL->team6);
  SDL_FreeSurface(ALL->team7);
  SDL_FreeSurface(ALL->team8);
  SDL_FreeSurface(ALL->team9);
  SDL_FreeSurface(ALL->screen);
  SDL_Quit();
}
