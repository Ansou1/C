/*
** my_revstr.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 01:13:57 2012 martial elegbede
** Last update Wed Oct 17 11:10:34 2012 martial elegbede
*/

char	*my_revstr(char *str)
{
  int	char_nb;
  char	*back_str;
  int	i;
  char	c;

  char_nb = my_strlen(str);
  back_str = str + char_nb - 1;
  char_nb = char_nb / 2;
  i = 0;
  while (i < char_nb)
    {
      c = *str;
      *str = *back_str;
      *back_str = c;
      str = str + 1;
      back_str = back_str - 1;
      i = i + 1;
    }
  return (str);
}
