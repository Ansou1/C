/*
** recup_nbr.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 15:08:52 2013 simon daguenet
** Last update Fri Mar 29 14:36:36 2013 simon daguenet
*/

#include "asm.h"

/* pour les signed shorts */
char	*recup_nbr2(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && i == 0))
    i++;
  ret = xmalloc(i + 1);
  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && i == 0))
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  i = my_getnbr(ret);
  ret = my_nbr_str_u_sho((unsigned short)(i));
  ret = convert_base(ret, "0123456789", "0123456789abcdef");
  ret[4] = '\0';
  ret = my_clean2(ret);
  return (ret);
}

char	*recup_nbr4(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && i == 0))
    i++;
  ret = xmalloc(i + 1);
  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && i == 0))
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  i = my_getnbr(ret);
  ret = my_nbr_str(i);
  ret = convert_base(ret, "0123456789", "0123456789abcdef");
  ret[8] = '\0';
  ret = my_clean4(ret);
  return (ret);
}

char	*recup_nbr4l(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && i == 0))
    i++;
  ret = xmalloc(i + 1);
  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && i == 0))
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  ret = convert_base(ret, "0123456789", "0123456789abcdef");
  ret = my_clean4(ret);
  return (ret);
}
