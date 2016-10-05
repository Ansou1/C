/*
** my_strcmp.c for strcmp in /home/daguen_s//afs/rendu/piscine/Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 09:44:38 2012 simon daguenet
** Last update Tue Oct 16 19:49:34 2012 simon daguenet
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
