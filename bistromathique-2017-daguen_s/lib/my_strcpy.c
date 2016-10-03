/*
** my_strcpy.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 00:44:29 2012 martial elegbede
** Last update Wed Oct 17 00:56:55 2012 martial elegbede
*/

char	*my_strcpy(char *dest, char *src)
{
  while (*src != 0)
    {
      *dest = *src;
      dest = dest + 1;
      src = src + 1;
    }
  return (dest);
}
