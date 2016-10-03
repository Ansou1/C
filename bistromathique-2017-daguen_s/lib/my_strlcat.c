/*
** my_strlcat.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 19:58:35 2012 martial elegbede
** Last update Thu Oct 18 20:06:25 2012 martial elegbede
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0' && (dest_len + i) < size)
    {
      dest[dest_len + i] = src[i];
      i = i + 1;
    }
  dest[dest_len + i] = '\0';
  return (dest_len + my_strlen(src));
}
