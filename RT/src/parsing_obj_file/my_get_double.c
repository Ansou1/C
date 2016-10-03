#include <math.h>

#include "rt.h"
#include "parsing.h"
#include "utils.h"

int	my_power_it(int nb, int power)
{
  int	nb2;

  nb2 = nb;
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else
    while (power != 1)
      {
	nb *= nb2;
	power -= 1;
      }
  return (nb);
}

double	my_get_double(const char *str)
{
  double	nb1;
  double	nb2;
  int		size;
  int		i;
  int		sign;

  i = 0;
  sign = 1;
  if (str[0] == '-')
    {
      sign = -1;
      ++str;
    }
  nb1 = (double)my_atoi(str);
  while (str[i] != '.' && str[i])
    ++i;
  if (str[i] != '.')
    return (nb1);
  ++i;
  size = i;
  nb2 = my_atoi(str + size);
  i = 1;
  while (str[size + i])
    ++i;
  return ((nb1 + (double)(nb2 / my_power_it(10.f, i))) * sign);
}
