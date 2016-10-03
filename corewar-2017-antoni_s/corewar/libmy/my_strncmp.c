/*
** my_strncmp.c for my_strncmp in /home/efilon/Projects/Cproject/Tests/RT
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Mon Mar 11 10:32:46 2013 sebastien antonico
** Last update Mon Mar 11 10:34:36 2013 sebastien antonico
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i + 1 < nb)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
