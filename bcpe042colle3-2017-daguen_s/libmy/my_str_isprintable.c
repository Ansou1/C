/*
** my_str_isprintable.c for my_str_isprintable in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 15:18:53 2012 simon daguenet
** Last update Tue Oct  9 15:23:46 2012 simon daguenet
*/

int	my_str_isprintable(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (str[i] != '\0')
    {
      if (!(str [i] >= 33 && str[i] <= 126))
	{
	  result = 0;
	}
      i = i + 1;
    }
  return (result);
}
