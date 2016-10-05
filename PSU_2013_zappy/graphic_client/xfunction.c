/**
 * \file xfunction.c
 * \brief Every function usefull.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * Function use to simplify the code.
 *
 */

#include "graphique.h"

/**
 * \fn void *xmalloc(size_t size).
 * \brief Function use to malloc.
 *
 * \param size_t size.
 * \return pointeur of the malloc size.
 */

void			*xmalloc(size_t size)
{
  void			*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    fprintf(stderr, "Error with memory allocation.\n");
  return (ptr);
}
