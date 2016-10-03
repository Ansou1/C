/*
** my_strlen.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 15 22:29:22 2012 martial elegbede
** Last update Mon Oct 15 22:31:53 2012 martial elegbede
*/

int	my_strlen(char *str)
{
  int	char_nb;

  char_nb = 0;
  while (str[char_nb] != 0)
    {
      char_nb = char_nb + 1;
    }
  return (char_nb);
}
