/*
** my_power_rec.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 16 23:27:41 2012 martial elegbede
** Last update Tue Oct 16 23:44:38 2012 martial elegbede
*/

int my_power_rec(int nb, int power)
{
  if (power != 1)
    nb = nb * my_power_rec(nb, power - 1);
  return (nb);
}
