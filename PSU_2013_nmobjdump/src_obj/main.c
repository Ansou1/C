/*
** main.c for  in /home/daguen_s/rendu/nm-objdump
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Feb 26 11:06:56 2014 daguen_s
** Last update Sun Mar 16 22:32:48 2014 daguen_s
*/

#include "objdump.h"

void		my_objdump(char *file)
{
  Elf32_Ehdr	*elf;
  int		fd;
  unsigned int	size;
  void		*data;

  if ((fd = xopen(file, O_RDONLY)) == -1 || ((size = xlseek(fd)) == -1)
      || (xaccess(file)) == -1 || (data = xmmap(fd, file, size))
      == MAP_FAILED)
    return ;
  elf = (Elf32_Ehdr*)data;
  if (size > (size_t)(elf->e_shoff))
    {
      if (elf->e_ident[EI_CLASS] == ELFCLASS32)
	format_32(file, size, data);
      else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
	format_64(file, size, data);
      else
	fprintf(stderr, "objdump: %s: File truncated\n", file);
    }
  else
    fprintf(stderr, "objdump: %s: File truncated\n", file);
  if (munmap(data, size) == -1)
    fprintf(stderr, "ERROR on munmap.\n");
  xclose(fd);
}

int		check_validity(char *file)
{
  struct stat	my_stat;

  stat(file, &my_stat);
  if (!S_ISREG(my_stat.st_mode))
    {
      fprintf(stderr, "objdump: Warning: '%s' is not an ordinary file\n",
	      file);
      return (0);
    }
  return (1);
}

int		main(int ac, char **av)
{
  int		i;

  i = 1;
  if (ac > 1)
    {
      while (i < ac)
	{
	  if (check_validity(av[i]))
	    my_objdump(av[i]);
	  i++;
	}
    }
  else
    {
      if (check_validity("a.out"))
	my_objdump("a.out");
    }
  return (EXIT_SUCCESS);
}
