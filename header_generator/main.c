/*
** main.c for main in /home/efilon/Projects/Cproject/Tests/header_gen
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Thu Apr 25 15:35:48 2013 sebastien antonico
** Last update Thu Apr 25 16:31:46 2013 sebastien antonico
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int	write_in_file(int fd_header, char *line)
{
  write(fd_header, line, strlen(line));
  return (1);
}

int	fill_header(int fd, int fd_header)
{
  char	*line;
  char	*str;

  str = malloc(2048);
  while (line = get_next_line(fd))
    {
      if (match(line, "*\t*(*)"))
	{
	  memset(str, 0, 2048);
	  sprintf(str, "%s;\n", line);
	  write_in_file(fd_header, str);
	}
      free(line);
    }
  free(str);
  return (1);
}

int	main(int ac, char **av)
{
  int	i;
  int	fd;
  int	fd_header;
  char	*str;

  if (ac == 1)
    exit(fprintf(stderr, "Usage : ./header_gen file1 [file2...]\n"));
  if ((fd_header = open("header.h", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (0);
  str = malloc(2048);
  write(fd_header, "#ifndef HEADER_H_\n# define HEADER_H_\n\n", strlen("#ifndef HEADER_H_\n# define HEADER_H_\n\n"));
  for (i = 1; i < ac; i++)
    {
      if ((fd = open(av[i], O_RDONLY)) != -1)
	{
	  memset(str, 0, 2048);
	  sprintf(str, "/* %s */\n", av[i]);
	  write(fd_header, str, strlen(str));
	  fill_header(fd, fd_header);
	  write(fd_header, "\n", 1);
	  close(fd);
	}
    }
  free(str);
  write(fd_header, "\n#endif /* !HEADER_H_ */", strlen("\n#endif /* !HEADER_H_ */"));
  close(fd_header);
}
