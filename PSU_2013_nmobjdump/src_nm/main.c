/*
** nm.c for  in /home/daguen_s/rendu/nm-objdump
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Mar  7 15:56:00 2014 daguen_s
** Last update Sun Mar 16 22:34:29 2014 daguen_s
*/

#include "nm.h"

int		is_good_elf(Elf64_Ehdr *elf)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0 || elf->e_ident[EI_MAG1] != ELFMAG1 ||
      elf->e_ident[EI_MAG2] != ELFMAG2 || elf->e_ident[EI_MAG3] != ELFMAG3 ||
      elf->e_type != ET_NONE || elf->e_ident[EI_VERSION] == EV_NONE
      || elf->e_ident[EI_DATA] == ELFDATANONE)
    return (-1);
  return (1);
}

void		my_nm(char *file)
{
  int		fd;
  void		*data;
  Elf64_Ehdr	*elf;
  unsigned int	size;

  if ((fd = xopen(file, O_RDONLY)) == -1 || ((size = xlseek(fd)) == -1)
      || (xaccess(file)) == -1 || (data = xmmap(fd, file, size))
      == MAP_FAILED)
    return ;
  elf = (Elf64_Ehdr*)data;
  if (size > (size_t)(elf->e_shoff))
    {
      if (elf->e_ident[EI_CLASS] == ELFCLASS64)
	format_64(file, size, data);
      else
	fprintf(stderr, "nm: %s: File truncated.\n", file);
    }
  else
    fprintf(stderr, "nm: %s: File truncated.\n", file);
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
      fprintf(stderr, "nm: Warning: '%s' is not an ordinary file\n", file);
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
	    {
	      if (ac > 2)
		printf("\n%s:\n", av[i]);
	      my_nm(av[i]);
	    }
	  i++;
	}
    }
  else
    {
      if (check_validity("a.out"))
	my_nm("a.out");
    }
  return (EXIT_SUCCESS);
}
