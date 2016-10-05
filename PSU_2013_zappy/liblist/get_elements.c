/*
** get_elements.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:19 2014 corrad_f
** Last update Sun May 11 00:42:56 2014 daguenet
*/

/**
 * \file get_elements.c
 * \brief get function.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * get elements.
 *
 */

#include "list.h"

/**
 * \fn void *front_list(list *this)
 * \brief get elements in front list.
 *
 * \param list *this
 * \return void*
 */

void			*front_list(list *this)
{
  if (!this->list)
    return (NULL);
  return (this->list->data);
}

/**
 * \fn void *back_list(list *this)
 * \brief get_elements in back list.
 *
 * \param list *this
 * \return void*
 */

void			*back_list(list *this)
{
  t_list_iterator	*tmp;

  if (!this->list)
    return (NULL);
  tmp = this->list;
  while (tmp->next)
    tmp = tmp->next;
  return (tmp->data);
}

/**
 * \fn t_list_iterator *begin_list(list *this)
 * \brief get elem on front list.
 *
 * \param list *this
 * \return t_list_iterator*
 */

t_list_iterator		*begin_list(list *this)
{
  if (!this->list)
    return (NULL);
  return (this->list);
}

/**
 * \fn t_list_iterator *end_list(list *this)
 * \brief get elem on end list
 *
 * \param list *this
 * \return t_list_iterator*
 */

t_list_iterator		*end_list(list *this)
{
  t_list_iterator	*tmp;

  if (!this->list)
    return (NULL);
  tmp = this->list;
  while (tmp->next)
    tmp = tmp->next;
  return (tmp);
}

/**
 * \fn void *get_list(list *this, int (*match) (void *data, void *value), void *value)
 * \brief get a list
 *
 * \param list *this, int (*match) (void *data, void *value), void *value
 * \return void*
 */

void			*get_list(list *this, int (*match)
				  (void *data, void *value),
				  void *value)
{
  t_list_iterator	*it;

  if ((it = find_list(this, this->begin(this), match, value)) == NULL)
    return (NULL);
  return (it->data);
}
