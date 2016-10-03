/*
** my_memset.c for my_memset in /home/efilon/Projects/Cproject/Corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Tue Mar 19 13:50:23 2013 sebastien antonico
** Last update Tue Mar 19 13:55:49 2013 sebastien antonico
*/

void	my_memset(void *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      ((char*)tab)[i] = 0;
      i++;
    }
}
