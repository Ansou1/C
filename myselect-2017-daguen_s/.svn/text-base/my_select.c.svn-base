/*
** my_select.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 23:13:36 2013 simon daguenet
** Last update Sat Jan 19 23:16:41 2013 simon daguenet
*/

#include "my_select.h"

void	init_t(struct termios *t)
{
  if (tcgetattr(0, t) == -1)
    my_put_error(2);
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, t) == -1)
    my_put_error(3);
}

int	keys(char *str)
{
  if (str[1] == '[' && str[2] == 'A')
    return (1);
  else if (str[1] == '[' && str[2] == 'B')
    return (2);
  else if (str[0] == '\n')
    return (3);
  else if (str[0] == ' ')
    return (4);
  else if (str[0] == 127 || (str[1] == '[' && str[2] == '3'))
    return (5);
  else if (str[0] == 27)
    return (6);
  return (0);
}

int	gere_command(t_list **list, int value_key, int *taille)
{
  if (value_key == 1)
    move_up(list);
  else if (value_key == 2)
    move_down(list);
  else if (value_key == 3)
    press_enter(list);
  else if (value_key == 4)
    press_space(list);
  else if (value_key == 5)
    press_delete(list, taille);
  else if (value_key == 6)
    press_exit(list);
  return (0);
}

int	display_loop(t_list *list, int *taille)
{
  struct termios	t;
  char			buff[101];
  int			ret;
  char			*s;

  init_t(&t);
  display_list(list);
  list = list->prev;
  signal(SIGINT, get_sigint);
  while (42)
    {
      if ((ret = read(0, buff, 100)) == -1)
        exit(EXIT_FAILURE);
      buff[ret] = '\0';
      gere_command(&list, keys(buff), taille);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_list	*list;
  char		*term;
  int		ret;

  if (env[0] == NULL || ac == 1)
    exit(EXIT_FAILURE);
  term = get_term(env, "TERM=");
  if (term == NULL)
    my_put_error(5);
  ret = tgetent(NULL, term);
  if (ret == -1 || ret == 0)
    my_put_error(1);
  ret = ac - 1;
  list = my_params_in_list(ac, av);
  display_loop(list, &ret);
  return (0);
}
