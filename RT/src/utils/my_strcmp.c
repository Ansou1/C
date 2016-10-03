#include<unistd.h>
#include"my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  size_t	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i += 1;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else if (s1[i] == '\0')
    return (-1);
  return (1);
}
