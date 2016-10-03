/*
** my_showstr.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 13:37:49 2012 martial elegbede
** Last update Thu Oct 18 15:32:30 2012 martial elegbede
*/

int	my_showstr(char *str)
{
  while (*str != '\0')
    {
      if (my_char_isprintable(*str))
	my_putchar(*str);
      else
	{
	  my_putchar('\\');
	  my_putnbr_base(*str, "0123456789abcdef");
	}
      str = str + 1;
    }
  return (0);
}
