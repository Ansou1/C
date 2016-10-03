/*
** get_base.c for bistro in /home/elegbe_m//programmation/bistro/BISTRO
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Sun Nov  4 16:19:42 2012 martial elegbede
** Last update Sun Nov  4 16:20:12 2012 martial elegbede
*/

int	get_base(char *base, char dessin)
{
  int	i;

  i = 0;
  while (base[i] != 0)
    {
      if (base[i] == dessin)
	return (i);
      i++;
    }
  return (0);
}
