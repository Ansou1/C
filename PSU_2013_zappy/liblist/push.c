/*
** push.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:36 2014 corrad_f
** Last update Sun May 11 00:49:54 2014 daguenet
*/

/**
 * \file push.c
 * \brief push.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * push.
 *
 */

#include "list.h"

/**
 * \fn void push_front_list(list *list, void *data)
 * \brief push in front list.
 *
 * \param list *list, void *data
 * \return none.
 */

void              push_front_list(list *list, void *data)
{
  t_list_iterator *new;

  if ((new = malloc(sizeof(t_list_iterator))) == NULL)
    return ;
  new->data = data;
  new->next = list->list;
  list->list = new;
}

/**
 * \fn void push_back_list(list *list, void *data)
 * \brief push in back list.
 *
 * \param list *list, void *data
 * \return none.
 */

void              push_back_list(list *list, void *data)
{
  t_list_iterator *new;
  t_list_iterator *tmp;

  tmp = list->list;
  if ((new = malloc(sizeof(t_list_iterator))) == NULL)
    return ;
  new->data = data;
  new->next = NULL;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    list->list = new;
  else
    tmp->next = new;
}
