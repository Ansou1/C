/*
** print_action.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 22:50:02 2013 simon daguenet
** Last update Sat Jan 19 23:47:30 2013 simon daguenet
*/

#include "my_select.h"

int	print(t_list **tmp)
{
  char	*s;
  char	*str;
  char	*s1;

  if ((s = tgetstr("cm", NULL)) == NULL)
    my_put_error_2(1);
  if ((s1 = tgoto(s, 0, (*tmp)->x)) == NULL)
    my_put_error_2(2);
  tputs(s1, 1, outc);
  if ((*tmp)->u_s == 1 && (*tmp)->m_r == 1)
    print_und_vid((*tmp)->word);
  else if ((*tmp)->u_s == 1)
    print_underline((*tmp)->word);
  else if ((*tmp)->m_r == 1)
    print_video((*tmp)->word);
  else
    {
      if ((str = tgetstr("ce", NULL)) == NULL)
        my_put_error(1);
      tputs(str, 1 , outc);
      my_putstr((*tmp)->word);
    }
  return (0);
}

int	print_underline(char *s)
{
  char	*str1;
  char	*str2;
  char	*str3;

  if ((str1 = tgetstr("vi", NULL)) == NULL)
    my_put_error_2(1);
  if ((str2 = tgetstr("us", NULL)) == NULL)
    my_put_error_2(1);
  if ((str3 = tgetstr("me", NULL)) == NULL)
    my_put_error_2(1);
  my_putstr(str1);
  my_putstr(str2);
  my_putstr(s);
  my_putstr(str3);
  return (0);
}

int	print_video(char *s)
{
  char	*str1;
  char	*str2;
  char	*str3;

  if ((str1 = tgetstr("vi", NULL)) == NULL)
    my_put_error_2(1);
  if ((str2 = tgetstr("mr", NULL)) == NULL)
    my_put_error_2(1);
  if ((str3 = tgetstr("me", NULL)) == NULL)
    my_put_error_2(1);
  my_putstr(str1);
  my_putstr(str2);
  my_putstr(s);
  my_putstr(str3);
  return (0);
}

int	print_und_vid(char *s)
{
  char	*str1;
  char	*str2;
  char	*str3;
  char	*str4;

  if ((str1 = tgetstr("vi", NULL)) == NULL)
    my_put_error_2(1);
  if ((str2 = tgetstr("us", NULL)) == NULL)
    my_put_error_2(1);
  if ((str3 = tgetstr("mr", NULL)) == NULL)
    my_put_error_2(1);
  if ((str4 = tgetstr("me", NULL)) == NULL)
    my_put_error_2(1);
  my_putstr(str1);
  my_putstr(str2);
  my_putstr(str3);
  my_putstr(s);
  my_putstr(str4);
  return (0);
}
