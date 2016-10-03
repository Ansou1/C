#include <stdlib.h>

#include "utils.h"

size_t		my_strlen(const char *s)
{
  size_t	size;

  size = 0;
  while (s[size])
    ++size;
  return (size);
}
