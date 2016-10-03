/*
** my_str_isalpha.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:00:54 2012 martial elegbede
** Last update Thu Oct 18 13:08:04 2012 martial elegbede
*/

int	my_str_isalpha(char *str)
{
  while (*str != 0)
    {
      if (!my_char_isalpha(*str))
	return (0);
      str = str + 1;
    }
  return (1);
}
