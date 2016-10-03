/*
** my_fonction1.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:17:24 2012 simon daguenet
** Last update Sat Dec 29 14:46:03 2012 simon daguenet
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  while (i < my_strlen(str))
    {
      j = 0;
      while (str[i + j] == to_find[j] && j < my_strlen(to_find))
	j++;
      if (j == my_strlen(to_find))
	return (&str[i]);
      i++;
    }
  return (0);
}

char	*my_strcat_furui(char *dest, char *src)
{
  int	i;
  int	lenght;

  lenght = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[lenght + i] = src[i];
      i = i + 1;
    }
  dest[lenght + i] = '\0';
  return (dest);
}
