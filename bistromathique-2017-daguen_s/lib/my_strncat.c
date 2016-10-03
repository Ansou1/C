/*
** my_strncat.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 19:54:28 2012 martial elegbede
** Last update Thu Oct 18 20:00:02 2012 martial elegbede
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	dest_len;
  int   i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len + i] = src[i];
      i = i + 1;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
