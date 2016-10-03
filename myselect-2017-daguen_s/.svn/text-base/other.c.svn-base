/*
** other.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 23:16:54 2013 simon daguenet
** Last update Sat Jan 19 23:46:23 2013 simon daguenet
*/

#include "my_select.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	free_list(t_list **list)
{
  t_list	*tmp;
  t_list	*tmp1;
  int		i;

  i = 0;
  tmp = (*list);
  while (i == 0 || tmp != (*list))
    {
      i++;
      tmp1 = (*list);
      (*list) = (*list)->next;
      free(tmp1);
    }
}

int	underline(t_list **list)
{
  if ((*list)->u_s == 0)
    (*list)->u_s = 1;
  else
    (*list)->u_s = 0;
  return (1);
}

int	video_mode(t_list **list)
{
  if ((*list)->m_r == 0)
    (*list)->m_r = 1;
  else
    (*list)->m_r = 0;
  return (1);
}

void	get_sigint(int sig)
{
  char	*s;
  char	*str;

  if ((s = tgetstr("cl", NULL)) == NULL)
    my_put_error_2(1);
  if ((str = tgetstr("ve", NULL)) == NULL)
    my_put_error_2(1);
  tputs(s, 1, outc);
  tputs(str, 1, outc);
  exit (EXIT_SUCCESS);
}
