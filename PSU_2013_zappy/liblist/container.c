/*
** container.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:13 2014 corrad_f
** Last update Sun May 11 00:37:07 2014 daguenet
*/

/**
 * \file container.c
 * \brief container.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * container.
 *
 */

#include "list.h"

/**
 * \fn void init_list(list *this)
 * \brief initialisation of list and function pointer
 *
 * \param list *this
 * \return none.
 */

void			init_list(list *this)
{
  this->list = NULL;
  this->push_back = push_back_list;
  this->push_front = push_front_list;
  this->pop_back = pop_back_list;
  this->pop_front = pop_front_list;
  this->empty = empty_list;
  this->front = front_list;
  this->back = back_list;
  this->size = size_list;
  this->begin = begin_list;
  this->end = end_list;
  this->insert = insert_list;
  this->remove_if = remove_if_list;
  this->clear = clear_list;
  this->for_each_param = for_each_list_param;
  this->for_each = for_each_list;
  this->find = find_list;
  this->get = get_list;
  this->erase = erase_list;
  this->free = NULL;
}

/**
 * \fn void insert_list(list *this, t_list_iterator *to, void *data)
 * \brief insert in list.
 *
 * \param list *this, t_list_iterator *to, void *data
 * \return none.
 */

//non test
void			insert_list(list *this, t_list_iterator *to, void *data)
{
  t_list_iterator	*it;
  t_list_iterator	*new;

  new = malloc(sizeof(t_list_iterator));
  new->data = data;
  new->next = NULL;
  it = this->list;
  if (it == NULL)
    {
      this->list = new;
      return ;
    }
  while (it)
    {
      if (it == to)
	{
	  new->next = it->next;
	  it->next = new;
	  return ;
	}
      it = it->next;
    }
}

/**
 * \fn void remove_if_list(list *this, int (*test)(void *data, void *value), void *value)
 * \brief remove in condition
 *
 * \param list *this, int (*test)(void *data, void *value), void *value
 * \return none.
 */

void			remove_if_list(list *this, int (*test)
			(void *data, void *value), void *value)
{
  t_list_iterator	*tmp;
  t_list_iterator	*back;

  tmp = this->list;
  while (tmp && (*test)(tmp->data, value))
    {
      if (this->free)
	(this->free)(tmp->data);
      this->list = tmp->next;
      free(tmp);
      tmp = this->list;
    }
  while (tmp && tmp->next)
    {
      if ((*test)(tmp->next->data, value))
        {
          back = tmp->next;
          if (this->free)
            (this->free)(tmp->next->data);
          tmp->next = tmp->next->next;
          free(back);
        }
      else
	tmp = tmp->next;
    }
}

/**
 * \fn void clear_list(list *this)
 * \brief clean list.
 *
 * \param list *this
 * \return none.
 */

void			clear_list(list *this)
{
  while (this->list)
    erase_list(this, this->begin(this));
}

/**
 * \fn void erase_list(list *this, t_list_iterator *it)
 * \brief delete list
 *
 * \param list *this, t_list_iterator *it
 * \return none.
 */

void    erase_list(list *this, t_list_iterator *it)
{
  t_list_iterator *tmp;
  t_list_iterator *back;

  if (this->list == NULL || it == NULL)
    return ;
  tmp = this->list;
  if (this->list == it)
  {
    back = tmp;
    this->list = tmp->next;
    if (this->free)
      (this->free)(it->data);
    free(back);
    return ;
  }
  while (tmp && tmp->next != it)
    tmp = tmp->next;
  if (tmp && tmp->next == it)
  {
    back = tmp->next;
    tmp->next = tmp->next->next;
    if (this->free)
      (this->free)(back->data);
    free(back);
  }
}
