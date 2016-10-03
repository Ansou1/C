/*
** my_strcpy.c for my_strcpy in /home/efilon/Projects/Cproject/Corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Fri Mar 29 16:55:49 2013 sebastien antonico
** Last update Fri Mar 29 17:53:28 2013 sebastien antonico
*/

int	my_strcpy(unsigned char *src, unsigned char *dest, int sizesrc)
{
  int	i;

  i = 0;
  while (i < sizesrc)
    {
      dest[i] = src[i];
      i++;
    }
  return (i);
}
