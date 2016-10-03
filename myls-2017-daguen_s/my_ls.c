/*
** my_ls.c for ls in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 27 09:16:57 2012 simon daguenet
** Last update Sun Dec  2 16:37:13 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdarg.h>
#include "my_ls.h"

void	display_data(struct stat sb)
{
  struct passwd	*name;
  struct group	*gp;
  char	*temps;

  my_printf("%d", sb.st_nlink);
  my_printf(" ");
  name = getpwuid(sb.st_uid);
  if (name == NULL)
    exit (EXIT_FAILURE);
  gp = getgrgid(sb.st_gid);
  if (gp == NULL)
    exit (EXIT_FAILURE);
  my_printf("%s", name->pw_name);
  my_printf(" ");
  my_printf("%s", gp->gr_name);
  my_printf("\t");
  my_printf("%d", sb.st_size);
  my_printf("\t");
  my_printf("%s", my_putstr_temps(temps, sb));
  my_printf(" ");
}

void	display_rights(struct stat sb)
{
  if (S_ISLNK(sb.st_mode))
    my_putchar('l');
  else if (S_ISDIR(sb.st_mode))
    my_putchar('d');
  else if (S_ISREG(sb.st_mode))
    my_putchar('-');
  ((sb.st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
  ((sb.st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
  ((sb.st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
  ((sb.st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
  ((sb.st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
  ((sb.st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
  ((sb.st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
  ((sb.st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
  ((sb.st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-");
  my_putstr(" ");
}

void	display_without_options(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_printf("%s\n", tab[i]);
      i++;
    }
  freetab(tab, i + 1);
}

void	display_with_option_d(char *path, char *options)
{
  struct stat	sb;
  char	*result;

  result = my_strstr(options, "l");
  if (result != 0)
    {
      if (stat(path, &sb) == -1)
	{
	  my_printf("ERROR : stat problem \n");
	  exit (EXIT_FAILURE);
	}
      display_rights(sb);
      display_data(sb);
  if (my_strcmp(path, "./") == 0)
    path[1] = '\0';
      my_printf("%s\n", path);
    }
  if (my_strcmp(path, "./") == 0)
    path[1] = '\0';
  if (result == 0)
    my_printf("%s\n", path);
}

int	main(int ac, char **av)
{
  char	*options;
  char	**args;

  options = NULL;
  args = NULL;
  get_options_and_args(ac, av, &options, &args);
  display_list(options, args);
  exit(EXIT_SUCCESS);
}
