/*
** str_condition.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon May  6 18:42:09 2013 florian corradin
** Last update Thu May 23 15:04:12 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

void		free_list_cond(t_cond *list)
{
  t_cond	*tmp;

  tmp = list;
  while (tmp)
    {
      list = tmp;
      tmp = tmp->next;
      if (list->data != NULL)
	free(list->data);
      free(list);
    }
}

int	all_exist_cond(char *s1, struct stat sb)
{
  int	ret;

  ret = 0;
  if (my_str_comp("-e", s1))
    ret = 1;
  else if (my_str_comp("-b", s1) && (sb.st_mode & S_IFMT) == S_IFBLK)
    ret = 1;
  else if (my_str_comp("-c", s1) && (sb.st_mode & S_IFMT) == S_IFCHR)
    ret = 1;
  else if (my_str_comp("-d", s1) && (sb.st_mode & S_IFMT) == S_IFDIR)
    ret = 1;
  else if (my_str_comp("-S", s1) && (sb.st_mode & S_IFMT) == S_IFSOCK)
    ret = 1;
  else if (my_str_comp("-L", s1) && (sb.st_mode & S_IFMT) == S_IFLNK)
    ret = 1;
  else if (my_str_comp("-f", s1) && (sb.st_mode & S_IFMT) == S_IFREG)
    ret = 1;
  else if (my_str_comp("-x", s1) && (sb.st_mode & S_IFMT) == S_IXUSR)
    ret = 1;
  else if (my_str_comp("-w", s1) && (sb.st_mode & S_IFMT) == S_IWUSR)
    ret = 1;
  else if (my_str_comp("-r", s1) && (sb.st_mode & S_IFMT) == S_IRUSR)
    ret = 1;
  return (ret);
}

int		check_exist_cond(char *s1, char *s2, char *s3)
{
  struct stat	sb;
  int		ret;

  if (stat(s2, &sb) == -1)
    {
      free(s1);
      free(s2);
      free(s3);
      return (0);
    }
  ret = all_exist_cond(s1, sb);
  free(s1);
  free(s2);
  free(s3);
  return (ret);
}

int	check_nbr_cond(char *s1, char *s2, char *s3)
{
  int	t1;
  int	t2;
  int	ret;

  ret = 0;
  t1 = my_atoi(s1);
  t2 = my_atoi(s3);
  if ((my_strncmp(s2, "-lt", 3) || my_strncmp(s2, "<", 1)) && t1 < t2)
    ret = 1;
  else if ((my_strncmp(s2, "-gt", 3) || my_strncmp(s2, ">", 1)) && t1 > t2)
    ret = 1;
  else if ((my_strncmp(s2, "-le", 3) || my_strncmp(s2, "<=", 2)) && t1 <= t2)
    ret = 1;
  else if ((my_strncmp(s2, "-ge", 3) || my_strncmp(s2, ">=", 2)) && t1 >= t2)
    ret = 1;
  else if ((my_strncmp(s2, "-eq", 3) || my_strncmp(s2, "==", 2)) && t1 == t2)
    ret = 1;
  else if ((my_strncmp(s2, "-ne", 3) || my_strncmp(s2, "!=", 2)) && t1 != t2)
    ret = 1;
  free(s1);
  free(s2);
  free(s3);
  return (ret);
}

int	check_str_cond(char *s1, char *s2, char *s3)
{
  if (my_str_comp("-z", s1) && s2[0] == '\0')
    return (1);
  else if (my_str_comp("-n", s1) && s2[0] != '\0')
    return (1);
  else if (s3[0] == '\0')
    return (check_exist_cond(s1, s2, s3));
  else if (my_str_comp(s2, "="))
    return (my_str_comp(s1, s3));
  else if (my_strncmp(s2, "!=", 2))
    {
      if (my_str_comp(s1, s3))
	return (0);
      return (1);
    }
  free(s1);
  free(s2);
  free(s3);
  return (0);
}
