/*
** my_strncmp.c for strncmp in /home/daguen_s//Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct  8 23:21:25 2012 simon daguenet
** Last update Tue Oct  9 09:56:31 2012 simon daguenet
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
