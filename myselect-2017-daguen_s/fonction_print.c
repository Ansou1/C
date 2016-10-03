/*
** fonction_print.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 23:07:09 2013 simon daguenet
** Last update Sat Jan 19 23:47:09 2013 simon daguenet
*/

#include "my_select.h"

void	my_putchar(char c)
{
  write(0, &c, 1);
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

void	aff_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (i == 0 || tmp != list)
    {
      i++;
      my_putstr(tmp->word);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int	outc(int c)
{
  write(0, &c, 1);
}

void	display_list(t_list *list)
{
  char	*s;
  char	*str;
  char	*s1;

  if ((str = tgetstr("cl", NULL)) == NULL)
    my_put_error_2(1);
  tputs(str, 1, outc);
  aff_list(list);
  if ((s = tgetstr("cm", NULL)) == NULL)
    my_put_error_2(1);
  if ((s1 = tgoto(s, 0, 0)) == NULL)
    my_put_error_2(2);
  tputs(s1, 1, outc);
}
