/*
** my_sort_int_tab.c for libmy in /home/elegbe_m//fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 16 10:21:43 2012 martial elegbede
** Last update Tue Oct 16 21:59:31 2012 martial elegbede
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	*little;

  while (size > 0)
    {
      i = 0;
      while (i < size)
	{
	  if (tab[i] < *tab)
	    my_swap(tab, tab + i);
	  i = i + 1;
	}
      size = size - 1;
      tab = tab + 1;
    }
}
