/*
** my_strcapitalize.c for strcapitalize in /home/daguen_s//Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct  8 23:34:18 2012 simon daguenet
** Last update Tue Oct 16 20:18:25 2012 simon daguenet
*/

int	my_fonction(char c)
{
  return (c >= 48 && c <= 57 || c >= 97 && c <= 122 || c >= 65 && c <= 90);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 97 && str[i] <= 122 && !my_fonction(str[i - 1]))
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
