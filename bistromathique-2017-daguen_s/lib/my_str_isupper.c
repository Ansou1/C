/*
** my_str_isupper.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:19:05 2012 martial elegbede
** Last update Thu Oct 18 13:31:03 2012 martial elegbede
*/

int     my_str_isupper(char *str)
{
  while (*str != 0)
    {
      if (*str < 'A' || *str > 'Z')
        return (0);
      str = str + 1;
    }
  return (1);
}
