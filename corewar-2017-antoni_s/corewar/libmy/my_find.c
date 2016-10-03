/*
** my_find.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:41:48 2012 sebastien antonico
** Last update Thu Nov 15 21:44:59 2012 sebastien antonico
*/

int	my_find(char c, char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}
