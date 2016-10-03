/*
** fill_env.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Feb 23 09:03:17 2013 florian corradin
** Last update Mon Apr  1 15:43:25 2013 florian corradin
*/

#include "42.h"

char	*my_fill_path(void)
{
  char	*ret;

  if ((ret = malloc(1)) == NULL)
    return (NULL);
  if ((ret = my_strcat_free_strt(ret, "/usr/sbin:/usr/bin:/sbin:/bin:/usr/sc"))
      == NULL)
    return (NULL);
  if ((ret = my_strcat_free_strt(ret, "hool/sbin:/usr/school/bin:/usr/netsou"))
      == NULL)
    return (NULL);
  if ((ret = my_strcat_free_strt(ret, "l/sbin:/usr/netsoul/bin:/usr/kerberos"))
      == NULL)
    return (NULL);
  if ((ret = my_strcat_free_strt(ret, "/sbin:/usr/kerberos/bin:/usr/local/sb"))
      == NULL)
    return (NULL);
  ret = my_strcat_free_strt(ret, "in:sbin:/usr/local/bin:/usr/bin/eclipse");
  if (ret == NULL)
    return (NULL);
  return (ret);
}
