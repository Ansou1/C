/*
** type_script.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 12:11:25 2013 florian corradin
** Last update Sat May 11 14:53:07 2013 florian corradin
*/

#include "42.h"
#include "script.h"

char	is_var_script(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' &&
	 is_c(line, i, '=') == 0)
    i++;
  if (line[i] == '=')
    return (1);
  else
    return (0);
}

char	is_commande(char *line)
{
  if (my_strncmp("do", line, 2) == 1)
    return (0);
  else if (line[0] == '#')
    return (0);
  else
    return (1);
}

char	is_keyword2(char *line)
{
  if (my_strncmp("then", line, 4))
    return (THEN);
  else if (my_strncmp(line, "read", 4))
    return (READ);
  else if (my_strncmp("case", line, 4))
    {
      if (line[4] == ' ' || line[4] == '\t' || line[4] == '\0')
	return (CASE);
    }
  else if (my_strncmp("trap", line, 4))
    return (TRAP);
  else if (is_commande(line) == 1)
    return (COM);
  return (0);
}

char	is_keyword(char *line)
{
  if (my_strncmp(line, "while", 5) == 1)
    return (WHILE);
  else if (my_strncmp(line, "}", 1))
    return (END_FUNC);
  else if (is_function(line))
    return (FUNCTION);
  else if (my_strncmp(line, "done", 4) == 1)
    return (DONE);
  else if (my_strncmp(line, "if", 2) == 1)
    return (IF);
  else if (my_strncmp(line, "else if", 7) == 1)
    return (ELSE_IF);
  else if (my_strncmp(line, "else", 4) == 1)
    return (ELSE);
  else if (my_strncmp(line, "exec", 4) == 1)
    return (EXEC);
  else if (my_strncmp(line, "for", 3) == 1)
    return (FOR);
  else if (my_strncmp(line, "until", 5) == 1)
    return (UNTIL);
  else if (my_strncmp(line, "let", 3) == 1)
    return (LET);
  else if (my_strncmp(line, "fi", 2))
    return (FI);
  return (is_keyword2(line));
}
