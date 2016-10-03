/*
** my_str_islower.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:12:05 2012 martial elegbede
** Last update Thu Oct 18 13:31:14 2012 martial elegbede
*/

int     my_str_islower(char *str)
{
  while (*str != 0)
    {
      if (*str < 'a' || *str > 'z')
        return (0);
      str = str + 1;
    }
  return (1);
}
