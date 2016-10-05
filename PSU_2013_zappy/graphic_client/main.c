/**
 * \file main.c
 * \brief main programme.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * The main party.
 *
 */

#include "graphique.h"

/**
 * \fn .
 * \brief .
 *
 * \param .
 * \return .
 */

void			my_mouse(t_graph *this, SDL_Event event)
{
  if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE ||
      event.type == SDL_QUIT)
    end_sdl(this);
  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == 1)
    {
      //ici je dois récupérer la position et les element de la map en affichant dans une nouvelle fenêtre les data puis afficher
    }
}

/**
 * \fn void display_all(t_graph *this).
 * \brief main loop for the programme.
 *
 * \param t_graph *this.
 * \return none.
 */

void			display_all(t_graph *this)
{
  SDL_Event		event;

  while (1)
    {
      while (SDL_PollEvent(&event))
	my_mouse(this, event);
      SDL_Flip(WIN->screen); //launch l'image
    }
}

/**
 * \fn int main(int ac, char **av).
 * \brief Enter for the Programme.
 *
 * \param int ac, char **av.
 * \return EXIT_SUCCESS Programme finish normally and if not EXIT_FAILURE.
 */

int			main(int ac, char **av)
{
  t_graph		this;

  if (ac == 3)
    {
      signal(SIGINT, close_client_ctrl);
      signal(SIGPIPE, SIG_IGN);
      if (!(atoi(av[2]) >= 1024 && atoi(av[2]) <= 65535))
	errx(EXIT_FAILURE, "USAGE: port must be between 1024 and 65535");
      //init_connect(&this, atoi(av[2]), av[1]);
      if (init_sdl(&this) == -1)
	errx(EXIT_FAILURE, "ERROR in init_sdl.");
      display_all(&this);
    }
  else
    errx(EXIT_FAILURE, "USAGE: ./client_graphique [ip] [port]");
  return (EXIT_SUCCESS);
}
