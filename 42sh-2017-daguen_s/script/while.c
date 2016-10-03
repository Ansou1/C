/*
** while.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Thu Apr 25 11:42:41 2013 florian corradin
** Last update Sat May 11 19:19:37 2013 florian corradin
*/

#include "42.h"
#include "script.h"

char	*get_control_instruction_cond(char *file, int i)
{
  char	*ret;
  int	posi;

  posi = 0;
  i += 3;
  while (file[i + posi] != ']' && file[i + posi] != '\0')
    posi++;
  ret = xmalloc(posi + 1);
  posi = 0;
  while (file[i + posi] != ']' && file[i + posi] != '\0')
    {
      ret[posi] = file[i + posi];
      posi++;
    }
  ret[posi] = '\0';
  return (ret);
}

/* PASSER TOUTE LES CHAINE ET REMPLACER LES # PAR DES \0 */
/* rempli la structure while et les condotion */
t_script	*get_key_while(char *file, int pos)
{
  int		i;
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = WHILE;
  ret->name = NULL;
  i = 0;
  while (file[i] != ' ' && file[i] != '\0' && file[i] != '\t')
    i++;
  if (file[i] == '\0' || file[i + 1] != '[')
    {
      g_stop_script = -1;
      fprintf(stderr, "Error bad syntaxe in while line: %d %s\n",
	      pos + 1, file);
      return (NULL);
    }
  ret->att = -1;
  ret->add = g_add;
  ret->inst = my_epurstr_inib(my_strdup(&file[i]));
  ret->tab = NULL;
  return (ret);
}

int	exec_while(t_script **s, t_var *v, int *i)
{
  if (instruction(s[*i]->inst, v))
    return (0);
  while (s[*i] && s[*i]->type != DONE)
    *i = *i + 1;
  return (0);
}

int	exec_done(t_script *s, t_var *v, int *i)
{
  if (instruction(s->inst, v))
    *i = s->att;
  return (0);
}
