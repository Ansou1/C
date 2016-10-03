int	my_atoi(const char *str)
{
  int	res;
  int	mlt;

  res = 0;
  mlt = 1;
  if (*str == '-')
    {
      mlt = -1;
      str++;
    }
  while ((*str >= '0') && (*str <= '9'))
    {
      res = (res * 10) + *str - '0';
      str++;
    }
  return (res * mlt);
}
