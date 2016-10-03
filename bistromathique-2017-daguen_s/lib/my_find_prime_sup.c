/*
** my_find_prime_sup.c for my_find_prime_sup in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 00:38:34 2012 martial elegbede
** Last update Wed Oct 17 00:42:20 2012 martial elegbede
*/

int	my_find_prime_sup(int nb)
{
  while (!my_is_prime(nb))
    nb = nb + 1;
  return (nb);
}
