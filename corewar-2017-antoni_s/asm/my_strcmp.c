/*
** strcmp.c for lib in /home/corrad_f/
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Dec  9 10:14:14 2012 florian corradin
** Last update Sat Mar 16 17:59:37 2013 simon daguenet
*/

#include "asm.h"

/* la fonction renvoie 1 si la chaine str1 est contenu dans 
   la chaine str2, sinon 0*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	ctr;

  ctr = 0;
  i = 0;
  while (str2[i] != '\0')
    {
      while (str1[ctr] == str2[i] && str2[i] != '\0' && str1[ctr] != '\0')
	{
	  i++;
	  ctr++;
	}
      if (ctr == my_strlen(str1))
	return (1);
      else
	ctr = 0;
      i++;
    }
  return (0);
}

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;
  int	ctr;

  ctr = 0;
  i = 0;
  while (str2[i] != '\0' && i < n)
    {
      while (str1[ctr] == str2[i] && str2[i] != '\0' && str1[i] != '\0')
	{
	  if (i >= n)
	    return (1);
	  i++;
	  ctr++;
	}
      if (ctr == my_strlen(str1))
	return (1);
      else
	ctr = 0;
      i++;
    }
  return (0);
}
