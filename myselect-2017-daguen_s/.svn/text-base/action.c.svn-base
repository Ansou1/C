/*
** action.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 22:56:56 2013 simon daguenet
** Last update Sat Jan 19 23:01:20 2013 simon daguenet
*/

#include "my_select.h"

int	move_up(t_list **list)
{
  underline(list);
  print(list);
  (*list) = (*list)->prev;
  underline(list);
  print(list);
  return (0);
}

int	move_down(t_list **list)
{
  underline(list);
  print(list);
  (*list) = (*list)->next;
  underline(list);
  print(list);
  return (0);
}

int	press_space(t_list **list)
{
  video_mode(list);
  print(list);
  move_down(list);
  return (0);
}

void	press_enter(t_list **list)
{
  t_list	*tmp;
  int		i;
  char		*s;

  if ((s = tgetstr("cl", NULL)) == NULL)
    my_put_error_2(1);
  tputs(s, 1, outc);
  tmp = (*list);
  i = 0;
  while (i == 0 || tmp != (*list))
    {
      i++;
      if (tmp->m_r == 1)
        {
          my_putstr(tmp->word);
          my_putchar(' ');
        }
      tmp = tmp->next;
    }
  free_list(list);
  if ((s = tgetstr("ve", NULL)) == NULL)
    my_put_error_2(1);
  my_putstr(s);
  exit (EXIT_SUCCESS);
}

void	press_exit(t_list **list)
{
  char	*s;
  char	*str;

  if ((s = tgetstr("cl", NULL)) == NULL)
    my_put_error_2(1);
  if ((str = tgetstr("ve", NULL)) == NULL)
    my_put_error_2(1);
  free_list(list);
  tputs(s, 1, outc);
  my_putstr(str);
  exit (EXIT_SUCCESS);
}
