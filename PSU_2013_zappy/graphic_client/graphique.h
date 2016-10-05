/**
 * \file graphique.h
 * \brief header.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * This is the header for the graphique.
 *
 */

#ifndef _GRAPHIQUE_H_
# define _GRAPHIQUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <errno.h>
#include <err.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

# define HEIGHT	1000
# define WEIGHT	1000

# define WIN	this->win

int		g_socket;

/**
 * \struct t_display
 * \brief All the image.
 *
 * t_display is the structure for all the image
 */

typedef struct	s_display
{
  SDL_Surface	*screen; /*!<L'ecran de la SDL */
  SDL_Surface	*bckg; /*!<Le fond de l'écran */
  SDL_Surface	*casee; /*!<L'image de la case */
  SDL_Surface	*ogre; /*!<L'image de l'ogre */
  SDL_Surface	*egg; /*!<L'image des oeufs */
  SDL_Surface	*food; /*!<L'image de la nourriture */
  SDL_Rect	eggs[49]; /*!<Le découpage des oeufs */
  SDL_Rect	ogres[16]; /*!<Le découpage des ogres */
  //SDL_Surface	*ogre_bro;
  //SDL_Surface	*ogre_inc;
  //SDL_Surface	*case_info;
}		t_display;

/**
 * \struct t_graph
 * \brief This structure is all
 *
 * t_graph is the structure for all the graphique part
 */

typedef struct	s_graph
{
  int		sock; /*!<La sockette de communication */
  t_display	*win; /*!<La structure qui contient toutes les images */
}		t_graph;

/*
** xfunction.c
*/

void		*xmalloc(size_t);

/*
** connection.c
*/

void		close_client_ctrl(int __attribute__((unused)));
void		init_connect(t_graph *, int, char *);

/*
** sdl.c
*/

SDL_Surface	*load_image(char *);
int		fill_data(t_graph *);
int		init_sdl(t_graph *);
void		end_sdl(t_graph *);

/*
** set_background.c
*/

void		background_repeat(t_graph *);
void		case_repeat(t_graph *);

/*
** main.c
*/

void		display_all(t_graph *);

/*
** image.c
*/

int		set_image(t_graph *);
void		set_ogres(t_graph *);
void		set_object(t_graph *);

#endif /* _GRAPHIQUE_H_ */
