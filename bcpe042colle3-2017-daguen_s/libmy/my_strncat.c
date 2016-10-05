/*
** my_strncat.c for strncat in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 00:50:40 2012 simon daguenet
** Last update Thu Oct 18 13:18:11 2012 simon daguenet
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	lenght;
  int	j;

  j = 0;
  if (nb < 0)
    {
      j = my_strlen(src);
      nb = j;
    }
  i = 0;
  lenght = my_strlen(dest);
  while (i < nb && src[i] != '\0')
    {
      dest[lenght + i] = src[i];
      i = i + 1;
    }
  dest[lenght + i] = '\0';
  return (dest);
}
