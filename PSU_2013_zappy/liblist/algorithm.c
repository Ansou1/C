/*
** algorithm.c for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:37:56 2014 corrad_f
** Last update Sun May 11 00:24:12 2014 daguenet
*/

/**
 * \file algorithm.c
 * \brief algorithm stl in c modular.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * c modular.
 *
 */

#include "list.h"

/**
 * \fn void for_each_list(list *this, void (*fct)(void *data))
 * \brief for_each.
 *
 * \param list *this, void (*fct)(void *data)
 * \return none.
 */

void			for_each_list(list *this, void (*fct)(void *data))
{
  t_list_iterator	*tmp;

  tmp = this->list;
  while (tmp)
    {
      (fct)(tmp->data);
      tmp = tmp->next;
    }
}

/**
 * \fn void for_each_list_param(list *this, void (*fct)(void *data, void *value), void *value)
 * \brief for each in param
 *
 * \param list *this, void (*fct)(void *data, void *value), void *value
 * \return none.
 */

void 			for_each_list_param(list *this, void (*fct)
					    (void *data, void *value),
					    void *value)
{
  t_list_iterator	*tmp;

  tmp = this->list;
  while (tmp)
    {
      (fct)(tmp->data, value);
      tmp = tmp->next;
    }
}

/**
 * \fn t_list_iterator *find_list(struct s_list *this, t_list_iterator *first, int (*test)(void *data, void *value), void *value)
 * \brief find
 *
 * \param struct s_list *this, t_list_iterator *first, int (*test)(void *data, void *value), void *value
 * \return t_list_iterator *
 */

t_list_iterator 	*find_list(struct s_list *this, t_list_iterator *first,
				   int (*test)(void *data, void *value),
				   void *value)
{
  t_list_iterator *it;

  this = this;
  it = first;
  while (it)
    {
      if ((test)(it->data, value))
	return (it);
      it = it->next;
    }
  return (NULL);
}
