/*
** my_sort_int_tab.c for my_sort_int_tab in /home/daguen_s//save_lib
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 11:34:39 2012 simon daguenet
** Last update Tue Oct 16 09:59:56 2012 simon daguenet
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	tampon;
  int	j;

  j = 0;
  while (j < size)
    {
      i = 0;
      while (i < size)
	{
	  if(tab[i] > tab[i + 1])
	    {
	      tampon = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = tampon;
	    }
	  i = i + 1;
	}
      j = j + 1;
    }
}
