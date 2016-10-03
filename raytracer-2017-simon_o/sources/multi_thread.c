/*
** multi_thread.c<2> for rt in /home/daguen_s//raytracer-3017-simon_o
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Wed May 29 09:52:32 2013 simon daguenet
** Last update Sun Jun  9 13:28:38 2013 jonathan racaud
*/

#include "raytracer.h"

void	*my_malloc(size_t taille)
{
  void	*ptr;

  if (taille == 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    fprintf(stderr, "Error in Xmalloc\n");
  return (ptr);
}

void		*fill_win(void *data)
{
  t_data	*new_data;

  new_data = (t_data*)data;
  fill_image(new_data->rt, new_data->x, new_data->xmax, new_data->y);
  return (NULL);
}

t_data		*fill_data(t_mlx *val, int i)
{
  t_data	*data;
  t_mlx		*new;

  new = NULL;
  data = my_malloc(sizeof(*data));
  data->rt = copy_struct_all(val, new);
  data->y = 0;
  data->x = i * ((data->rt->width) / val->nb_threads);
  data->xmax = (i + 1) * ((data->rt->width) / val->nb_threads);
  return (data);
}

void		multi_thread(t_mlx *mlx)
{
  pthread_t	*thread;
  t_data	*data;
  int		i;

  thread = my_malloc(sizeof(*thread) * mlx->nb_threads);
  i = 0;
  while (i < mlx->nb_threads)
    {
      data = fill_data(mlx, i);
      if (pthread_create(&thread[i], NULL, fill_win, (void*)data) != 0)
	exit(!fprintf(stderr, "ERROR in pthread_create.\n"));
      i++;
    }
  i = 0;
  while (i < mlx->nb_threads)
    {
      if (pthread_join(thread[i], NULL) != 0)
      	exit(!fprintf(stderr, "ERROR in pthread_join.\n"));
      i++;
    }
}
