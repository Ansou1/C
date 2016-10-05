/**
 * \file set_background.c
 * \brief Set the background for the graphique.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * File use to set the background.
 *
 */

#include "graphique.h"

/**
 * \fn void background_repeat(t_graph *this)
 * \brief Function of background creation.
 *
 * \param structure t_graph qui comporte toutes les images.
 * \return none.
 */

void			background_repeat(t_graph *this)
{
  unsigned short	x;
  unsigned short	y;
  SDL_Rect		position;

  position.x = 0;
  position.y = 0;
  y = 0;
  while (y < 1000 * 32) //changer par la taille de la fenêtre
    {
      x = 0;
      while (x < 1000 * 32)
	{
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(WIN->bckg, NULL, WIN->screen, &position);
	  x += 32;
	}
      y += 32;
    }
}

/**
 * \fn void case_repeat(t_graph *this)
 * \brief Function of case creation.
 *
 * \param structure t_graph qui comporte toutes les images.
 * \return none.
 */

void			case_repeat(t_graph *this)
{
  unsigned short	x;
  unsigned short	y;
  SDL_Rect		position;

  position.x = 0;
  position.y = 0;
  y = 0;
  while (y < 10 * 100)
    {
      x = 0;
      while (x < 10 * 100)
	{
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(WIN->casee, NULL, WIN->screen, &position);
	  x += 100;
	}
      y += 100;
    }
}
