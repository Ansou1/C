/*
** condition.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Thu Apr 25 18:27:35 2013 florian corradin
** Last update Thu May 23 14:34:42 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

int	get_and_or_bol(int c1, int type, t_cond *c, t_var *v)
{
  int	c2;

  if (c == NULL)
    return (0);
  c2 = one_instruction(c->data, v);
  if (type == 2 && c1 == 1 && c2 == 1)
    return (1);
  else if (type == 3 && (c1 == 1 || c2 == 1))
    return (1);
  return (0);
}

int	instruction_return(int ret, t_cond *tmp)
{
  free_list_cond(tmp);
  return (ret);
}

int		instruction(char *inst, t_var *v)
{
  int		c1;
  t_cond	*c;
  t_cond	*tmp;

  if ((c = get_cond_list(inst)) == NULL)
    return (0);
  tmp = c;
  c1 = one_instruction(c->data, v);
  while (c)
    {
      if ((c = c->next) == NULL)
	return (instruction_return(c1, tmp));
      if (c->type == 1)
	{
	  fprintf(stderr, "Syntaxe error in binary operande in condition\n");
	  g_stop_script = -1;
	  return (0);
	}
      c1 = get_and_or_bol(c1, c->type, c->next, v);
      if (c1 == 1 && c->type == 3)
	return (instruction_return(1, tmp));
      if ((c = c->next) == NULL)
	return (instruction_return(c1, tmp));
    }
  return (c1);
}

char	*modif_str_var(char *com, t_var *v)
{
  com = check_var_script(com, 0, v);
  com = desinhiber(com);
  com = replace_bq_str(com, 0);
  return (com);
}

int	one_instruction(char *inst, t_var *v)
{
  char	*cond;
  char	*s1;
  char	*s2;
  char	*s3;
  int	i;

  i = 0;
  if ((cond = my_strdup(inst)) == NULL)
    return (0);
  cond = modif_str_var(cond, v);
  if ((s1 = get_next_word(&cond[i])) == NULL)
    return (0);
  while (cond[i] == ' ' || cond[i] == '\t')
    i++;
  i += my_strlen(s1);
  if ((s2 = get_next_word(&cond[i])) == NULL)
    return (0);
  while (cond[i] == ' ' || cond[i] == '\t')
    i++;
  i += my_strlen(s2);
  if ((s3 = get_next_word(&cond[i])) == NULL)
    return (0);
  if (s2[0] == '-' && s2[1] != 'n' && s2[1] != 'z')
    return (check_nbr_cond(s1, s2, s3));
  return (check_str_cond(s1, s2, s3));
}
