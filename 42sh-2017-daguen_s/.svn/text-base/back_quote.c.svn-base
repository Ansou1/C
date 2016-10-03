/*
** back_quote.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Mar 28 18:25:22 2013 florian corradin
** Last update Sun May 12 11:02:27 2013 florian corradin
*/

#include "42.h"
#include "script.h"

char	*get_back_quot()
{
  int	fd;
  char	*ret;

  if ((ret = malloc(1)) == NULL)
    return (NULL);
  ret[0] = '\0';
  if ((fd = open(".ba_quo", O_RDONLY)) == -1)
    {
      fprintf(stderr, "open fail\n");
      return (NULL);
    }
  ret = get_next_file(fd);
  close(fd);
  return (ret);
}

char	*creat_file_bq(char *com)
{
  pid_t	pid;
  int	status;
  int	fd;
  char	*exec;

  if ((fd = open(".ba_quo", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU)) == -1)
    {
      fprintf(stderr, "open fail\n");
      return (NULL);
    }
  pid = xfork(1);
  if (pid == 0)
    {
      dup2(fd, 1);
      infectsh(com);
      kill(getpid(), SIGKILL);
    }
  else
    wait3(&status, 0, 0);
  write(fd, "\0", 1);
  close(fd);
  exec = get_back_quot();
  remove(".ba_quo");
  return (exec);
}

char	*init_del()
{
  char	*ret;

  ret = malloc(1);
  ret[0] = '\0';
  return (ret);
}

char	*get_del_bq(char *rep)
{
  char	*del;

  if ((del = my_strcat_free_end("`", rep)) == NULL)
    return (NULL);
  if ((del = my_strcat_free_strt(del, "`")) == NULL)
    return (NULL);
  return (del);
}

char	*replace_bq_str(char *com, int pos)
{
  char	*del;
  int	i;
  char	*quote;
  char	*ret;
  char	*rep;
  int	len;

  if ((rep = get_bq_rep(com)) == NULL)
    return (com);
  i = pos;
  if ((quote = creat_file_bq(rep)) == NULL)
    return (NULL);
  del = init_del();
  if ((del = get_del_bq(rep)) == NULL)
    return (NULL);
  while (is_c(com, i, '`') == 0 && com[i] != '\0' && com[i] != '\n')
    i++;
  len = i;
  i = i + my_strlen(quote);
  ret = replace_in_str(com, del, quote, len);
  ret = replace_by_in_str(ret, '\n', ' ');
  if (ret[i] == '\0' || ret[i] == '\n')
    return (ret);
  return (replace_bq_str(ret, i));
}
