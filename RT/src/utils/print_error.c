#include "utils.h"

void	print_error(const char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return ;
}

void	my_putstr(const char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    print_error("Error on Write.\n");
}
