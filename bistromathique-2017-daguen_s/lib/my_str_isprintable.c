/*
** my_str_isprintable.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:28:51 2012 martial elegbede
** Last update Thu Oct 18 13:30:49 2012 martial elegbede
*/

int     my_str_isprintable(char *str)
{
  while (*str != 0)
    {
      if (*str < 32 || *str > 127)
        return (0);
      str = str + 1;
    }
  return (1);
}
