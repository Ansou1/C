/*
** lib.h for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 17:42:48 2013 florian corradin
** Last update Fri Feb 22 19:47:50 2013 florian corradin
*/

#ifndef LIB_H
#define LIB_H

void	check_malloc(void *ptr);
char	*my_strdup(char *str);
char	**my_copy_tab(char **src);
void	my_free_tab(char **tab);
void	my_put_tab(char **tab);

#endif
