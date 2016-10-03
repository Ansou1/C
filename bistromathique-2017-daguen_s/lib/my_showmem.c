/*
** my_showmem.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 16:35:02 2012 martial elegbede
** Last update Sat Nov 10 17:41:26 2012 martial elegbede
*/

int	my_showmem(char *str, int size)
{
  int	line_nb;
  int	i;

  line_nb = size / 16;
  i = 0;
  while (i <= line_nb)
    {
      my_putnbr_base(str, "0123456789abcdef");
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
