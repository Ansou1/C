/*
** my_strcapitalize.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Thu Oct 18 11:31:30 2012 martial elegbede
** Last update Sat Nov 10 17:42:29 2012 martial elegbede
*/

char	*my_strcapitalize(char *str)
{
  int i;

  my_strlowcase(str);
  if (my_char_isalpha(str[0]))
    str[i] = str[i] - 'a' + 'A';
  i = 1;
  while (str[i] != 0)
    {
      if (my_char_isalpha(str[i]))
	{
	  if (!my_char_isalpha(str[i - 1])
	      && !my_char_isnum(str[i - 1]))
	    str[i] = str[i] - 'a' + 'A';
	}
      i = i + 1;
    }
}
