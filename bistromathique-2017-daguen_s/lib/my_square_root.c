/*
** my_square_root.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 00:00:23 2012 martial elegbede
** Last update Wed Oct 17 00:06:26 2012 martial elegbede
*/

int	my_square_root(int nb)
{
  int	i;
  int	ret;

  i = 1;
  ret = 1;
  while (nb > ret)
    {
      nb = nb - ret;
      ret = ret + 2;
      i = i + 1;
    }
  if (nb == ret)
    return (i);
  if (nb < ret)
    return (0);
}
