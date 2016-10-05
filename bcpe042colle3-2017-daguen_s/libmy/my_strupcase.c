/*
** my_strupcase.c for strupcase in /home/daguen_s//Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct  8 23:26:18 2012 simon daguenet
** Last update Tue Oct  9 11:36:02 2012 simon daguenet
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 97 && str[i] <= 122)
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
