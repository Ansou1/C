/*
** my_power_rec.c for my_power_rec in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Oct  5 20:50:05 2012 simon daguenet
** Last update Mon Oct  8 08:48:06 2012 simon daguenet
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    {
      return (1);
    }
  if (power == 1)
    {
      return (nb);
    }
  if (power < 0)
    {
      return (0);
    }
  else
    {
      return(nb * my_power_rec(nb, power - 1));
    }
  return (0);
}
