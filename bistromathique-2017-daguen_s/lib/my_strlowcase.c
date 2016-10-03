/*
** my_strlowcase.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 10:37:51 2012 martial elegbede
** Last update Thu Oct 18 10:45:55 2012 martial elegbede
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] - 'A' + 'a';
      i = i + 1;
    }
  return (str);
}
