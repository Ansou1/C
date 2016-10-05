/*
** my_strstr.c for strstr in /home/daguen_s//Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct  8 22:57:18 2012 simon daguenet
** Last update Tue Oct 16 19:27:14 2012 simon daguenet
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != to_find[j])
	{
	  j = 0;
	}
      if (str[i] == to_find[j])
	{
	  return (&str[i]);
	}
      if (to_find[j] == '\0')
	{
	  j = j - 1;
	  i = i - 1;
	  return (&str[i]);
	}
      i = i + 1;
    }
  return (0);
}
