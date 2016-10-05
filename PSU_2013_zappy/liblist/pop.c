/*
** pop.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:25 2014 corrad_f
** Last update Sun May 11 00:47:40 2014 daguenet
*/

/**
 * \file pop.c
 * \brief pop.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * pop.
 *
 */

#include "list.h"

/**
 * \fn void *pop_front_list(list *list)
 * \brief pop elem in front
 *
 * \param list *list
 * \return void*
 */

void              *pop_front_list(list *list)
{
  void            *ret;
  t_list_iterator *tmp;

  if (list->list == NULL)
    return (NULL);
  tmp = list->list;
  ret = tmp->data;
  list->list = tmp->next;
  free(tmp);
  return (ret);
}

/**
 * \fn void *pop_back_list(list *list)
 * \brief pop elem in back
 *
 * \param list *list
 * \return void*
 */

void              *pop_back_list(list *list)
{
  void            *ret;
  t_list_iterator *tmp;

  tmp = list->list;
  if (list->list == NULL)
    return (NULL);
  while (tmp->next)
    {
      if (tmp->next && tmp->next->next == NULL)
        {
	  ret = tmp->next->data;
	  free(tmp->next);
	  tmp->next = NULL;
	  return (ret);
        }
      tmp = tmp->next;
    }
  ret = (list->list)->data;
  free(list->list);
  list->list = NULL;
  return (ret);
}
