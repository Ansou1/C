/*
** match.c for match in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Oct 12 15:45:47 2012 simon daguenet
** Last update Thu Apr 25 15:32:42 2013 simon daguenet
*/

int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s2[0] == '*')
	  return (*(s2 + 1) == '\0' || match(s1, s2 + 1) || match(s1 + 1, s2));
      if (s1[0] != s2[0])
	  return (0);
      s2++;
      s1++;
    }
  while (s2[0] == '*')
      s2++;
  i++;
  return (s2[0] == '\0');
}
