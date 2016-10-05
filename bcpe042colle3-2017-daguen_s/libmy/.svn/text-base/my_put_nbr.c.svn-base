/*
** my_put_nbr.c for my_put_nbr in /home/daguen_s//match
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct 15 09:46:04 2012 simon daguenet
** Last update Mon Oct 22 11:41:35 2012 simon daguenet
*/

int	count_power(int nb)
{
  int	res;

  res = 1;
  while (nb/10 > 0)
    {
      nb = nb / 10;
      res = res * 10;
    }
  return (res);
}

int	my_put_nbr(int nb)
{
  int	power;

  if (nb <= 2147483647 && nb >= -2147483647)
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = nb * -1;
	}
      power = 0;
      power = count_power(nb);
      while (power > 0)
	{
	  my_putchar((nb / power) + '0');
	  nb = nb % power;
	  power = power / 10;
	}
    }
  return (0);
}

