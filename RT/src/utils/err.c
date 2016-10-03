#include<stdlib.h>
#include<unistd.h>

#include"utils.h"

void	w_error(char *msg)
{
  int	i;

  i = 0;
  while (msg[i++]);
  if (write(2, "Fatal error : ", 14) == -1)
    return ;
  if (write(2, msg, i) == -1)
    return ;
  if (write(2, "\n", 1) == -1)
    return ;
  exit(EXIT_FAILURE);
}

void	w_warning(char *msg)
{
  int	i;

  i = 0;
  while (msg[i++]);
  if (write(2, "Warning : ", 10) == -1)
    return ;
  if (write(2, msg, i) == -1)
    return ;
  if (write(2, "\n", 1) == -1)
    return ;
}
