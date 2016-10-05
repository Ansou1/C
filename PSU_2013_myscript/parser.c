/*
** parser.c for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 17:09:10 2014 daguen_s
** Last update Fri Feb 28 17:32:54 2014 daguen_s
*/

#include "my_script.h"

void			*xmalloc(size_t size)
{
  void			*ptr;

  if (size == 0)
    return (NULL);
  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, "Error with memory allocation.\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

void			init_option(t_opt *opt)
{
  opt->a = 0;
  opt->c = 0;
  opt->q = 0;
  opt->command = NULL;
  opt->output = "typescript";
}

int			get_option(int ac, char **av, t_opt *opt, int *i)
{
  if (strcmp(av[*i], "-a") == 0)
    opt->a = 1;
  else if (strcmp(av[*i], "-c") == 0)
    {
      opt->c = 1;
      (*i)++;
      if (*i >= ac)
	return (0);
      opt->command = av[*i];
    }
  else if (strcmp(av[*i], "-q") == 0)
    opt->q = 1;
  return (1);
}

void			open_options(t_opt *opt)
{
  int			tmp_fd;

  if (opt->a == 0)
    {
      if ((tmp_fd = open(opt->output, FLAGS | O_TRUNC, 0644)) > 0)
	opt->my_fd = tmp_fd;
      else
	{
	  fprintf(stderr, ERROR_OPENING);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      if ((tmp_fd = open(opt->output, FLAGS | O_APPEND, 0644)) > 0)
	opt->my_fd = tmp_fd;
      else
	{
	  fprintf(stderr, ERROR_OPENING);
	  exit(EXIT_FAILURE);
	}
    }
}

int			get_params(int ac, char **av, t_opt *opt)
{
  char			*opt_lst;
  int			i;

  opt_lst = "acq";
  i = 1;
  init_option(opt);
  while (i < ac)
    {
      if (strlen(av[i]) == 2 && av[i][0] == '-' && !strchr(opt_lst, av[i][1]))
	return (0);
      if (av[i][0] != '-' && strcmp(opt->output, "typescript") == 0)
	opt->output = av[i];
      if (get_option(ac, av, opt, &i) == 0)
	return (0);
      i++;
    }
  open_options(opt);
  set_termios(&opt->term, &opt->win);
  return (1);
}
