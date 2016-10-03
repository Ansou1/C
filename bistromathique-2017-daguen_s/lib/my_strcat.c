/*
** my_strcat.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 18:22:10 2012 martial elegbede
** Last update Mon Nov  5 15:15:00 2012 martial elegbede
*/

char	*my_strcat(char *dest, char *src)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i = i + 1;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
