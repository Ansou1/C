int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (dest == 0 || src == 0)
    return (dest);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
