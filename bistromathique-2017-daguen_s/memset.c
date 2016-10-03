/*
** memset.c for bistro in /home/elegbe_m//programmation/bistro/BISTRO
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Nov  5 14:34:02 2012 martial elegbede
** Last update Mon Nov  5 14:34:54 2012 martial elegbede
*/

void	my_memcharset(char *str, int c, int size)
{
  while (size >= 0)
    {
      str[size] = c;
      size = size - 1;
    }
}

void	my_memset(int *str, int c, int size)
{
  while (size >= 0)
    {
      str[size] = c;
      size = size - 1;
    }
}
