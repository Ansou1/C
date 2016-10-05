/*
** my_str_islower.c for my_str_islower in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 14:56:11 2012 simon daguenet
** Last update Tue Oct  9 15:08:41 2012 simon daguenet
*/

int	my_str_islower(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 97 && str[i] <= 122))
	{
	  result = 0;
	}
      i = i + 1;
    }
  return (result);
}
