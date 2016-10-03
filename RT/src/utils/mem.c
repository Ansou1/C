#include<stdlib.h>

#include"utils.h"

void	*w_malloc(unsigned int size)
{
  void	*ret;

  ret = malloc(size);
  if (ret == 0)
    w_error("Malloc error");
  w_memset(ret, size, 0);
  return (ret);
}

void	w_free(void **ptr)
{
  if (ptr != NULL && *ptr != NULL)
    {
      free(*ptr);
      *ptr = NULL;
    }
  else
    w_warning("Null pointer free");
}

void	w_memset(void *ptr, int size, int val)
{
  int	i;
  char	*tmp;

  tmp = (char *)ptr;
  i = 0;
  while (i < size)
    {
      tmp[i] = val;
      i++;
    }
}
