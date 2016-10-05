/*
** my_strlen.c for my_strlen in /home/daguen_s//save_lib
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 09:32:56 2012 simon daguenet
** Last update Wed Oct 10 09:34:28 2012 simon daguenet
*/

int	my_strlen(char * str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
