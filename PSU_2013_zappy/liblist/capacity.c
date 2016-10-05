/*
** capacity.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:06 2014 corrad_f
** Last update Sun May 11 00:30:31 2014 daguenet
*/

/**
 * \file capacity.c
 * \brief capacity.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * capacity.
 *
 */

#include "list.h"

/**
 * \fn int empty_list(list *this)
 * \brief know if it's an empty list
 *
 * \param list *this
 * \return int
 */

int 	empty_list(list *this)
{
  return (this->list == NULL);
}

/**
 * \fn unsigned int size_list(list *this)
 * \brief get size list.
 *
 * \param list *this
 * \return unsigned int
 */

unsigned int 		size_list(list *this)
{
  unsigned int		size;
  t_list_iterator	*tmp;

  tmp = this->list;
  size = 0;
  while (tmp)
    {
      ++size;
      tmp = tmp->next;
    }
  return (size);
}
