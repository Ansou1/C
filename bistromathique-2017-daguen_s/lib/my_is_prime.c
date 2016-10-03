/*
** my_is_prime.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 00:11:22 2012 martial elegbede
** Last update Sat Nov 10 17:40:21 2012 martial elegbede
*/

int	my_is_prime(int nombre)
{
  int	i;

  if (nombre < 0)
    nombre = nombre * -1;
  if (nombre < 2)
    return (0);
  i = nombre;
  while (i > 2)
    {
      i = i - 1;
      if (nombre % i == 0)
	return (0);
    }
  return (1);
}
