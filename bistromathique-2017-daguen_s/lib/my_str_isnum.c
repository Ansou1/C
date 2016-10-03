/*
** my_str_isnum.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:09:15 2012 martial elegbede
** Last update Thu Oct 18 13:09:34 2012 martial elegbede
*/

int     my_str_isnum(char *str)
{
  while (*str != 0)
    {
      if (!my_char_isnum(*str))
        return (0);
      str = str + 1;
    }
  return (1);
}
