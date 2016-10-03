/*
** get_instruction.c for corewar* in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Jan 26 16:08:07 2013 florian corradin
** Last update Fri Mar 29 14:17:06 2013 simon daguenet
*/

#include "asm.h"

int	is_only_mnemo(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != ':')
    i++;
  if (str[i] == ':')
    return (0);
  return (1);
}

int	check_mnemo(char *mnemo)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (mnemo == NULL)
    return (0);
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strncmp(op_tab[i].mnemonique,
		mnemo, my_strlen(op_tab[i].mnemonique)) == 1)
	if (is_only_mnemo(mnemo) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	check_mnemo_len(char *mnemo)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (mnemo == NULL)
    return (0);
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strncmp(mnemo, op_tab[i].mnemonique, my_strlen(mnemo)) == 1)
	return (my_strlen(op_tab[i].mnemonique));
      i++;
    }
  return (0);
}

char	**my_strdup_tab(char **tab)
{
  int	i;
  char	**ret;

  i = 0;
  while (tab[i] != NULL)
    i++;
  ret = malloc(sizeof (char **) * (i + 1));
  ret[i] = NULL;
  check_malloc(ret);
  i = 0;
  while (tab[i] != NULL)
    {
      ret[i] = my_strdup(tab[i]);
      i++;
    }
  return (ret);
}

char	***my_clean_file(char ***file)
{
  char	***ret;
  int	len;
  int	ctr;

  ctr = 0;
  len = my_len_bigtab(file);
  ret = malloc(sizeof(char ***) * (len + 1));
  ret[len] = NULL;
  check_malloc(ret);
  len = 0;
  while (file[len] != NULL)
    {
      if (check_mnemo(file[len][0]) == 1 || check_mnemo(file[len][1]) == 1)
	{
	  ret[ctr] = my_strdup_tab(file[len]);
	  ctr++;
	}
      len++;
    }
  ret[ctr] = NULL;
  my_free_bigtab(file);
  return (ret);
}
