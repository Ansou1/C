/*
** my_rev_list.c for my_rev_list.c in /home/corrad_f//piscine/Jour_12/ex_03
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Oct 23 15:30:57 2012 florian corradin
** Last update Thu May 23 14:22:32 2013 simon daguenet
*/

#include "my.h"

void		my_rev_list(t_alum **begin)
{
  t_alum	*s1;
  t_alum	*s2;
  t_alum	*stock;

  s1 = *begin;
  stock = *begin;
  if (s1 != NULL)
    {
      s1 = stock->next;
      stock->next = NULL;
      while (s1 != NULL)
	{
	  s2 = s1->next;
	  s1->next = stock;
	  stock = s1;
	  s1 = s2;
	}
    }
  *begin = stock;
}
