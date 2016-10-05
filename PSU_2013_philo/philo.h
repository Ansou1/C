/*
** philo.h for  in /home/daguen_s/rendu/PSU_2013_philo
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Mar 10 11:59:12 2014 daguen_s
** Last update Sun Mar 23 21:28:32 2014 daguen_s
*/

#ifndef _PHILO_H_
# define _PHILO_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <err.h>

typedef struct		s_param
{
  unsigned short	rice;
  unsigned char		time;
}			t_param;

const char * const	g_name[] =
  {
   "\033[31m 1 Socrate",
   "\033[32m 2 Platon",
   "\033[33m 3 Aristote",
   "\033[34m 4 Montaigne",
   "\033[35m 5 Pascal",
   "\033[36m 6 Descarte",
   "\033[37m 7 Thales"
  };

const char * const	g_state[] =
  {
    "is thinking",
    "is eating",
    "is sleeping"
  };

enum eState
  {
    THINK,
    EAT,
    SLEEP
  };

enum eName
  {
    SOCRATE,
    PLATON,
    ARISTOTE,
    MONTAIGNE,
    PASCAL,
    DESCARTES,
    THALES
  };

typedef struct		s_philo
{
  enum eName		name;
  pthread_t		thread;
  enum eState		state;
  int			rice;
}			t_philo;

#endif /* _PHILO_H_ */
