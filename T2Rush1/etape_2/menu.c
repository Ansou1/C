/*
** menu.c for  in /home/daguen_s/rendu/T2Rush1/etape_2
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar  8 12:47:33 2014 daguen_s
** Last update Sun Mar  9 21:28:46 2014 daguen_s
*/

#include "rush.h"

void		my_sleep2()
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
      else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (event.button.button == SDL_BUTTON_LEFT)
	    go = chosen_map(event.button.x, event.button.y);
	}
    }
}

void		fill_menu(t_menu *menu)
{
  menu->button1 = load_image("./img/buttonlvl1-1.png");
  menu->button2 = load_image("./img/buttonlvl2-1.png");
  menu->button3 = load_image("./img/buttonlvl3-1.png");
  menu->button4 = load_image("./img/buttonlvl4-1.png");
  menu->button5 = load_image("./img/buttonlvl5-1.png");
}

void		set_button(t_menu *menu)
{
  SDL_Rect	position;

  position.y = 10;
  position.x = 10;
  SDL_BlitSurface(menu->button1, NULL, menu->screen, &position);
  position.y += 80;
  position.x = 10;
  SDL_BlitSurface(menu->button2, NULL, menu->screen, &position);
  position.y += 80;
  position.x = 10;
  SDL_BlitSurface(menu->button3, NULL, menu->screen, &position);
  position.y += 80;
  position.x = 10;
  SDL_BlitSurface(menu->button4, NULL, menu->screen, &position);
  position.y += 80;
  position.x = 10;
  SDL_BlitSurface(menu->button5, NULL, menu->screen, &position);
}

int		get_map_by_menu()
{
  t_menu	*menu;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (fprintf(stderr, "ERROR: %s.\n", SDL_GetError()));
  SDL_WM_SetCaption("MENU", NULL);
  menu = xmalloc(sizeof(*menu));
  if (!(menu->screen = SDL_SetVideoMode(260, 400, 32, FLAG)))
    return (fprintf(stderr, "ERROR: %s\n", SDL_GetError()));
  SDL_FillRect(menu->screen, NULL, SDL_MapRGB
	       (menu->screen->format, 255, 255, 255));
  fill_menu(menu);
  set_button(menu);
  SDL_Flip(menu->screen);
  my_sleep2();
  SDL_FreeSurface(menu->button1);
  SDL_FreeSurface(menu->button2);
  SDL_FreeSurface(menu->button3);
  SDL_FreeSurface(menu->button4);
  SDL_FreeSurface(menu->button5);
  SDL_FreeSurface(menu->screen);
  free(menu);
  SDL_Quit();
  return (1);
}
