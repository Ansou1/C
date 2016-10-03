#include"utils.h"

char	*x_strdup(const char *str_to_copy)
{
  char	*str_to_return;
  int	size;
  int	i;

  i = 0;
  size = my_strlen(str_to_copy) + 1;
  str_to_return = w_malloc(sizeof(*str_to_copy) * size);
  while (str_to_copy[i] != '\0')
    {
      str_to_return[i] = str_to_copy[i];
      i += 1;
    }
  str_to_return[i] = '\0';
  return (str_to_return);
}
