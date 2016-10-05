/*
** my_str_isnum.c for my_str_isnum in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 14:42:05 2012 simon daguenet
** Last update Tue Oct  9 14:53:48 2012 simon daguenet
*/

int	my_str_isnum(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 48 && str[i] <= 57))
	{
	  result = 0;
	}
      i = i + 1;
    }
  return (result);
}
