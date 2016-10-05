/**
 * \file image.c
 * \brief This file is use to load every image.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * This file is use to load every image.
 *
 */

#include "graphique.h"

/**
 * \fn void set_ogres(t_graph *this).
 * \brief Load the image of ogres.
 *
 * \param t_graph *this.
 * \return none.
 */

void			set_ogres(t_graph *this)
{
  const int		width = 291;
  const int		height = 392;
  int			i;

  i = 0;
  while (i < 16)
    {
      WIN->ogres[i].x = (width / 4) * (i % 4);
      WIN->ogres[i].y = (height / 4) * (i / 4);
      WIN->ogres[i].w = width / 4;
      WIN->ogres[i].h = height / 4;
      i++;
    }
}

/**
 * \fn void set_object(t_graph *this).
 * \brief Load the image of eggs.
 *
 * \param t_graph *this.
 * \return none.
 */

void			set_object(t_graph *this)
{
  const int		width = 210;
  const int		height = 210;
  int			i;

  i = 0;
  while (i < 49)
    {
      WIN->eggs[i].x = (width / 7) * (i % 7);
      WIN->eggs[i].y = (height / 7) * (i / 7);
      WIN->eggs[i].w = width / 7;
      WIN->eggs[i].h = height / 7;
      i++;
    }
}

/**
 * \fn int set_image(t_graph *this).
 * \brief Load every image and SDL_Surface.
 *
 * \param t_graph *this.
 * \return 0 if everything worked well otherwise -1.
 */

int			set_image(t_graph *this)
{
  WIN->bckg = load_image("./img/sol_terre.jpg");
  //WIN->casee = load_image("./img/sol_os.jpg");
  WIN->casee = load_image("./img/grass1.png");
  WIN->ogre = load_image("./img/ogre.png");
  WIN->egg = load_image("./img/eggs.png");
  WIN->food = load_image("./img/Steak.PNG");
  if (WIN->bckg == NULL || WIN->casee == NULL || WIN->ogre == NULL ||
      WIN->egg == NULL || WIN->food == NULL)
    return (-1);
  set_ogres(this);
  set_object(this);
  return (0);
}
