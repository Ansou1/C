/*
** ascii.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:47:25 2013 florian corradin
** Last update Thu May 23 14:04:42 2013 simon daguenet
*/

#include "42.h"

int	infectsh(char *str)
{
  if (check_inhibiteur(str) == SUCCESS)
    {
      if ((str = module_str(str)) != NULL)
	{
	  if (my_strncmp(str, "exit", 4) == 1)
	    if (str[4] == ' ' || str[4] == '\0')
	      return (exit_shell(&str[4]));
	  if (my_shell(str) == FAIL)
	    return (FAIL);
	}
    }
  free(str);
  return (0);
}

int	put_file(char *file, char *color)
{
  int	fd;
  char	buf[10000];

  if (g_ascii == 0)
    return (SUCCESS);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (FAIL);
  my_putstr(color);
  fd = read(fd, &buf, 9999);
  if (fd == -1)
    return (FAIL);
  buf[fd] = '\0';
  my_putstr(buf);
  my_putstr("\033[37m");
  close(fd);
  return (SUCCESS);
}

int	aff_help()
{
  printf("option: \n");
  printf("[--ascii] -> print ascii art picture when an error occured\n");
  printf("[-C] -> execute the command line past in argv[2]\n");
  printf("[--man] -> print the manual of infectsh\n");
  return (1);
}

int	check_c(int ac, char **av)
{
  if (ac == 2)
    {
      if (my_str_comp(av[1], "--man"))
	infectsh(my_strdup("cat man_infect | less"));
    }
  if (ac == 3)
    {
      if (my_str_comp(av[1], "-C"))
	{
	  infectsh(my_strdup(av[2]));
	  return (-1);
	}
    }
  return (0);
}

void	check_option(int ac, char **av)
{
  int	arg;

  g_wait_com = 1;
  g_ascii = 0;
  g_old_com = 0;
  info.hist = NULL;
  arg = ac;
  ac--;
  info.time = get_time();
  info.term = my_getenv("TERM");
  while (ac != 0)
    {
      if (my_str_comp(av[ac], "--ascii") == 1 ||
	  my_strncmp("-a", av[ac], 2) == 1)
	g_ascii = 1;
      if (my_str_comp(av[ac], "--help") == 1)
	arg = aff_help();
      ac--;
    }
  if (arg == 2 && g_ascii == 0)
    printf(USAGES);
  put_file(DARK_VADOR_PATATE, RED);
}
