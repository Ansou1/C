/*
** list.h for  in /home/corrad_f/Documents/PSU_2013_zappy/liblist
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 30 12:38:31 2014 corrad_f
** Last update Sun May 11 00:45:44 2014 daguenet
*/

/**
 * \file list.h
 * \brief list.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * list.
 *
 */

#ifndef _MYLIST_
# define _MYLIST_

#include <stdlib.h>

/**
 * \struct t_list_iterator
 * \brief list_iterator
 *
 */

typedef struct 			s_list_iterator
{
  void 				*data;
  struct s_list_iterator 	*next;
}				t_list_iterator;

/**
 * \struct t_list
 * \brief list
 *
 */

typedef struct 			s_list
{
  t_list_iterator		*list;
  void 				(*push_back)(struct s_list *, void *);
  void 				(*push_front)(struct s_list *, void *);
  void 				*(*pop_back)(struct s_list *);
  void 				*(*pop_front)(struct s_list *);
  void 				(*for_each)(struct s_list *, void (*fct)(void *));
  void 				(*for_each_param)(struct s_list *, void (*fct)(void *, void *), void *);
  int 				(*empty)(struct s_list *);
  void 				*(*front)(struct s_list *);
  void 				*(*back)(struct s_list *);
  unsigned int			(*size)(struct s_list *);
  t_list_iterator		*(*begin)(struct s_list *);
  t_list_iterator		*(*end)(struct s_list *);
  void 				(*insert)(struct s_list *, t_list_iterator *, void *);
  void 				(*remove_if)(struct s_list *, int (*test)(void *data, void *value), void *value);
  void				(*clear)(struct s_list *);
  t_list_iterator		*(*find)(struct s_list *, t_list_iterator *first, int (*test)(void *data, void *value), void *value);
  void 				*(*get)(struct s_list *this, int (*match)(void *data, void *value), void *value);
  void        (*erase)(struct s_list *this, t_list_iterator *it);
  void 				(*free)(void *);
}				t_list;

typedef				t_list list;

//container
void				init_list(list *this);
void				push_front_list(list *list, void *data);
void				push_back_list(list *list, void *data);
void				*pop_front_list(list *list);
void				*pop_back_list(list *list);
void				for_each_list(list *this, void (*fct)(void *data));
int				  empty_list(list *this);
void				*front_list(list *this);
void				*back_list(list *this);
unsigned int			size_list(list *this);
t_list_iterator			*begin_list(list *this);
t_list_iterator			*end_list(list *this);
void				insert_list(list *this, t_list_iterator *to, void *data);
void				remove_if_list(list *this, int (*test)(void *data, void *value), void *value);
void				for_each_list_param(list *this, void (*fct)(void *data, void *value), void *value);
void				clear_list(list *this);
t_list_iterator			*find_list(struct s_list *this, t_list_iterator *first, int (*test)(void *data, void *value), void *value);
void				*get_list(list *this, int (*match)(void *data, void *value), void *value);
void        erase_list(list *this, t_list_iterator *it);

#endif
