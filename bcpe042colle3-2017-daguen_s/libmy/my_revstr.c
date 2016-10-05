/*
** my_revstr.c for revstr in /home/daguen_s//Jour_06
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct  8 22:49:02 2012 simon daguenet
** Last update Tue Oct 16 17:13:50 2012 simon daguenet
*/

char	*my_revstr(char *str)
{
  int	i;
  int	taille;
  char	c;

  i = 0;
  taille = 0;
  while (str[i])
    {
      taille = taille + 1;
      i = i + 1;
    }
  i = 0;
  while (i < taille / 2)
    {
      c = str[taille - 1 - i];
      str[taille - 1 - i] = str[i];
      str[i] = c;
      i = i + 1;
    }
  return (str);
}
