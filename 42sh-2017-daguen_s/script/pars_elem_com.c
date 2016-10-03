/*
** elem_com.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon May  6 18:56:52 2013 florian corradin
** Last update Mon May 13 10:07:35 2013 florian corradin
*/

#include "42.h"
#include "script.h"

int	go_to_in_str(char *str, int i, char c)
{
  while (str[i] != '\0' && str[i] != c)
    i++;
  return (i);
}

t_script	*get_key_done_error(int ctr_loop, int pos, t_script *ret)
{
  ret->tab = NULL;
  ret->add = g_add;
  if (ctr_loop != -1)
    {
      g_stop_script = -1;
      fprintf(stderr, "Error line %d done whithout previous loop\n", pos + 1);
    }
  return (ret);
}

/* va chercher le while correspondant et rempli la condition dans inst */
t_script	*get_key_done(t_script **p, int pos)
{
  t_script	*ret;
  int		i;
  int		ctr_loop;

  ctr_loop = 0;
  i = pos - 1;
  if ((ret = xmalloc(sizeof (t_script))) == NULL)
    return (NULL);
  ret->type = DONE;
  ret->name = NULL;
  ret->tab = NULL;
  while (ctr_loop != -1 && i > 0)
    {
      if (p[i]->type == DONE)
	ctr_loop++;
      else if (p[i]->type == WHILE || p[i]->type == FOR || p[i]->type == UNTIL)
	ctr_loop--;
      if (ctr_loop == -1)
	{
	  ret->inst = my_strdup(p[i]->inst);
	  ret->att = i;
	}
      i--;
    }
  return (get_key_done_error(ctr_loop, pos, ret));
}

/* pour l'instant commande*/
t_script	*get_other(char *file, int type)
{
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = type;
  ret->add = g_add;
  ret->inst = my_strdup(file);
  ret->name = NULL;
  ret->att = -1;
  ret->tab = NULL;
  return (ret);
}

void	check_name(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_digit(str[i]) == 0 && is_alpha(str[i]) == 0)
	{
	  g_statu = -1;
	  fprintf(stderr, "Error %c illegal character for variable\n", str[i]);
	  kill(getpid(), SIGKILL);
	}
      i++;
    }
}
