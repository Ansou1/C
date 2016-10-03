/*
** my_getnbr.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 15 22:43:00 2012 martial elegbede
** Last update Sat Nov  3 15:15:28 2012 martial elegbede
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	sign;

  sign = 1;
  nb = 0;
  while (*str > '9' && *str < '0')
    {
      if (*str == '-')
	sign = sign * -1;
      str = str + 1;
    }
  while (*str >= '0' && *str <= '9')
    {
      if (nb > 214748364 && *str > 6)
	return (0);
      nb = nb * 10;
      nb = nb + *str - '0';
      str = str + 1;
    }
  return (sign * nb);
}
