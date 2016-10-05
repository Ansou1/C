/**
 * \file sdl.c
 * \brief All .
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * All to use SDL.
 *
 */

#include "graphique.h"

/**
 * \fn SDL_Surface *load_image(char *picture).
 * \brief load_image from a image.
 *
 * \param char *picture.
 * \return SDL_Surface *optimizedImage.
 */

SDL_Surface		*load_image(char *picture)
{
  SDL_Surface		*loadedImage;
  SDL_Surface		*optimizedImage;

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

/**
 * \fn int fill_data(t_graph *this).
 * \brief call function to load image.
 *
 * \param t_graph *this.
 * \return 0 if success and -1 for fail.
 */

int			fill_data(t_graph *this)
{
  SDL_Rect		position;

  position.x = 0;
  position.y = 0;
  if (set_image(this) == -1)
    return (-1);
  background_repeat(this);
  case_repeat(this);
  //SDL_SetColorKey(WIN->ogre, SDL_SRCCOLORKEY, SDL_MapRGB(WIN->screen->format, 255, 255, 255));
  //SDL_BlitSurface(WIN->ogre, &WIN->ogres[0], WIN->screen, &position);
  //SDL_SetColorKey(WIN->food, SDL_SRCCOLORKEY, SDL_MapRGB(WIN->screen->format, 255, 255, 255));
  //SDL_BlitSurface(WIN->food, NULL, WIN->screen, &position);
  //SDL_SetColorKey(WIN->egg, SDL_SRCCOLORKEY, SDL_MapRGB(WIN->screen->format, 255, 255, 255));
  //SDL_BlitSurface(WIN->egg, &WIN->eggs[10], WIN->screen, &position);
  return (0);
}

/**
 * \fn int init_sdl(t_graph *this).
 * \brief initialise la SDL.
 *
 * \param t_graph *this.
 * \return 0 if success and -1 for fail..
 */

int			init_sdl(t_graph *this)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  if ((WIN = xmalloc(sizeof(t_display))) == NULL)
    return (-1);
  SDL_WM_SetCaption("client graphique", NULL);
  if (!(WIN->screen = SDL_SetVideoMode(1000, 1000, 32,
				       SDL_HWSURFACE | SDL_DOUBLEBUF)))
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  if (SDL_FillRect(WIN->screen, NULL,
		   SDL_MapRGB(WIN->screen->format, 0, 0, 0)) == -1)
    {
      fprintf(stderr, "ERROR: %s\n", SDL_GetError());
      return (-1);
    }
  return (fill_data(this));
}

/**
 * \fn void end_sdl(t_graph *this).
 * \brief use to free SDL_Surface.
 *
 * \param t_graph *this.
 * \return none.
 */

//ici pense a free chaque SDL_Surface qui a été crée
void			end_sdl(t_graph *this)
{
  SDL_FreeSurface(WIN->food);
  SDL_FreeSurface(WIN->egg);
  SDL_FreeSurface(WIN->ogre);
  SDL_FreeSurface(WIN->casee);
  SDL_FreeSurface(WIN->bckg);
  SDL_FreeSurface(WIN->screen);
  SDL_Quit();
  free(this->win);
}
