/*
** my_str_isalpha.c for isalpha in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 13:08:27 2012 simon daguenet
** Last update Tue Oct  9 14:37:23 2012 simon daguenet
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (str[i] != '\0')
    {
      if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
	{
	  result = 0;
	}
      i = i + 1;
    }
  return (result);
}
