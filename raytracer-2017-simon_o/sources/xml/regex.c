/*
** regex.c for regex in /tmp/CACA/raytracer-2017-simon_o/rt/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sat Jun  8 19:30:56 2013 efilon
** Last update Sat Jun  8 19:31:14 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <regex.h>
#include "raytracer.h"

int		reg_match(char *str, char *reg)
{
  int		err;
  regex_t	preg;
  int		match;

  err = regcomp(&preg, reg, REG_NOSUB | REG_EXTENDED);
  if (!err)
    {
      match = regexec(&preg, str, 0, NULL, 0);
      regfree (&preg);
      return (match);
    }
  fprintf(stderr, "Erreur : %s invalide\n", reg);
  return (-1);
}

int	type_line_xml(char *line)
{
  if (!reg_match(line, REGEX_ELEM))
    return (TYPE_ELEM);
  else if (!reg_match(line, REGEX_OPEN_NODE))
    return (TYPE_OPEN_NODE);
  else if (!reg_match(line, REGEX_CLOSE_NODE))
    return (TYPE_CLOSING_NODE);
  else if (!reg_match(line, REGEX_COMMENT))
    return (TYPE_COMMENT);
  else if (!reg_match(line, REGEX_SPEC))
    return (TYPE_PROLOGUE);
  return (-1);
}
