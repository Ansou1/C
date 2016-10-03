/*
** strcmp.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 11:36:24 2012 martial elegbede
** Last update Wed Oct 17 11:46:52 2012 martial elegbede
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
    {
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
    return (*s1 - *s2);
}
