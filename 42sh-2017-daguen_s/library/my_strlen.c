/*
** tmy_swap.c for tmy_swap.c in /home/corrad_f//tst/Jour4
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Oct  4 11:13:34 2012 florian corradin
** Last update Wed Apr 10 09:28:29 2013 florian corradin
*/

int	my_strlen(char *str)
{
  int	ctr;

  ctr = 0;
  while (str[ctr] != '\0')
    ctr++;
  return (ctr);
}
