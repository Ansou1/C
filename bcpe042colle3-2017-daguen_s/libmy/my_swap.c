/*
** my_swap.c for my_swap in /home/daguen_s//afs/rendu/piscine/Jour_04
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Oct  4 11:01:55 2012 simon daguenet
** Last update Mon Oct  8 14:14:06 2012 simon daguenet
*/

int	my_swap(int *a, int *b)
{
  int	c;
  
  c = *a;
  *a = *b;
  *b = c;
}
