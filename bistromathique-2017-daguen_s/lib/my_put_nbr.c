/*
** my_put_nbr.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 15 12:50:10 2012 martial elegbede
** Last update Sat Oct 27 00:11:28 2012 martial elegbede
*/

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= 10)
      my_put_nbr(nb / 10);
  my_putchar((nb % 10) + '0');
}
