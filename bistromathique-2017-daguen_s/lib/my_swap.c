/*
** my_swap.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 15 13:33:05 2012 martial elegbede
** Last update Mon Oct 15 16:38:40 2012 martial elegbede
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
