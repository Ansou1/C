/*
** my_putstr.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 15 22:20:54 2012 martial elegbede
** Last update Mon Oct 15 22:26:56 2012 martial elegbede
*/

void	my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str = str + 1;
    }
}
