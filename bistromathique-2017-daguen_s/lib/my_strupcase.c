/*
** my_strupcase.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 10:22:03 2012 martial elegbede
** Last update Thu Oct 18 10:34:35 2012 martial elegbede
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 'a' + 'A';
      i = i + 1;
    }
  return (str);
}
