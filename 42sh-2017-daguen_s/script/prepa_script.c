/*
** prepa_script.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon May  6 19:02:03 2013 florian corradin
** Last update Mon May 13 09:33:35 2013 florian corradin
*/

#include "42.h"
#include "script.h"

int	strlen_c(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != c)
    i++;
  return (i);
}

char	**my_word_tab(char *str, char c)
{
  int	i;
  char	*line;
  char	**tab;
  int	ctr;

  if ((tab = malloc(sizeof (char **))) == NULL)
    return (NULL);
  tab[0] = NULL;
  i = 0;
  while (str[i] != '\0')
    {
      ctr = 0;
      if ((line = malloc(strlen_c(&str[i], c) + 1)) == NULL)
	return (NULL);
      while (str[i] != c && str[i] != '\0')
	line[ctr++] = str[i++];
      line[ctr] = '\0';
      line = my_epurstr_inib(line);
      if ((tab = my_tabcat(tab, line)) == NULL)
	return (NULL);
      if (str[i] == c)
	i++;
    }
  free(str);
  return (tab);
}

int	my_exec_script(char *file)
{
  if (file[0] != '#')
    {
      if (check_inhibiteur(file) == SUCCESS)
	{
	  if ((file = module_str(file)) != NULL)
	    {
	      if (my_strncmp(file, "exit", 4) == 1)
		if (file[4] == ' ' || file[4] == '\0')
		  return (exit_shell(&file[4]));
	      if (my_shell(file) == FAIL)
		return (FAIL);
	    }
	}
    }
  return (SUCCESS);
}

void	my_free_scr(t_script **s)
{
  int	i;

  i = 0;
  while (s[i] != NULL)
    {
      if (s[i]->tab != NULL)
	my_free_tab(s[i]->tab);
      if (s[i]->name != NULL)
	free(s[i]->name);
      if (s[i]->inst != NULL)
	free(s[i]->inst);
      free(s[i]);
      i++;
    }
  free(s);
}

char	**get_comment(char **file)
{
  int	i;
  int	ctr;

  i = 0;
  while (file[i] != '\0')
    {
      ctr = 0;
      while (file[i][ctr] != '\0' && file[i][ctr] != '#')
	ctr++;
      if (ctr > 0)
	{
	  if (file[i][ctr - 1] != '$')
	    file[i][ctr] = '\0';
	}
      i++;
    }
  return (file);
}
