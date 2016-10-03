/*
** type.c for infectsh in /home/corrad_f//projet/infect
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Apr  7 09:09:20 2013 florian corradin
** Last update Sun May  5 18:35:16 2013 florian corradin
*/

#include "42.h"

char	is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (c);
  return (0);
}

char	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (c);
  return (0);
}

char	is_operator(char c)
{
  if (c == '/' || c == '-' || c == '+' || c == '*' || c == '%')
    return (c);
  return (0);
}

char	is_varchar(char c)
{
  if (c != '{' && c != '}' && c != '[' && c != ']' &&
      c != '$' && c != '#' && c != '@')
    return (0);
  return (c);
}
