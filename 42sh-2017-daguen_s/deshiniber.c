/*
** deshiniber.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Mar 26 20:53:17 2013 florian corradin
** Last update Tue May 21 13:44:02 2013 florian corradin
*/

#include "42.h"

char	**de_inhib_tab(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i] != NULL)
    {
      if ((tabl[i] = desinhiber(tabl[i])) == NULL)
	return (NULL);
      i++;
    }
  return (tabl);
}

char	*desinhiber(char *str)
{
  int	i;
  int	i2;
  char	*ret;

  i = 0;
  i2 = 0;
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == 92)
	i++;
      ret[i2++] = str[i];
      if (str[i] != '\0')
	i++;
    }
  ret[i2] = '\0';
  free(str);
  return (ret);
}

int	check_inhibiteur(char *str)
{
  int	i;
  char	statement;

  i = 0;
  statement = 0;
  while (str[i] != '\0')
    {
      if (!statement && is_c(str, i, 96))
	statement = str[i];
      else if (!statement && is_c(str, i, 34))
	statement = str[i];
      else if (!statement && is_c(str, i, 39))
	statement = str[i];
      else if (statement && is_c(str, i, statement))
	statement = 0;
      i++;
    }
  if (statement)
    {
      put_file(PIG, GREEN);
      fprintf(stderr, "Unmatched %c.\n", statement);
    }
  return (statement ? FAIL : SUCCESS);
}
