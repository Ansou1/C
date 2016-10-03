#include <pthread.h>
#include "rt.h"
#include "utils.h"
#include "multi_thread.h"

void		*thread_render_line(void *data)
{
  t_data	*data_new;

  data_new = (t_data*)data;
  printf("data_new->rect->x => %d || data_new->x_max => %d || data_new->rect->width => %d\n", data_new->rect->x, data_new->x_max, data_new->rect->width);
  while (data_new->rect->x < data_new->x_max)
    {
      render_line(data_new->this, data_new->rect, data_new->refresh);
      data_new->rect->x += data_new->rect->width;
    }
  free_session_copy(data_new->this);
  free(data_new->rect);
  free(data_new);
  return (NULL);
}

static void	wait_thread(pthread_t *thread, int core)
{
  int		i;

  i = 0;
  while (i < core)
    {
      if (pthread_join(thread[i], NULL) != 0)
	w_error("thread did'nt end correctly");
      i += 1;
    }
}

pthread_t	*thread_maker(int core)
{
  pthread_t	*thread;

  thread = w_malloc(sizeof(*thread) * core);
  return (thread);
}

t_data		*data_maker(t_rt *this, t_rectangle *rect, int i)
{
  t_data	*data;

  data = w_malloc(sizeof(*data));
  data->rect = w_malloc(sizeof(*(data->rect)));
  data->this = copy_tmp_session(this);
  data->rect->width = rect->width;
  data->rect->height = rect->height;
  data->rect->x = i * (WIN_WIDTH / (data->this->cam->nb_core));
  data->x_max = (i + 1) * (WIN_WIDTH / (data->this->cam->nb_core));
  data->refresh = 1;
  return (data);
}

void		multi_thread(t_rt *this, t_rectangle *rect)
{
  pthread_t	*thread;
  t_data	*data;
  int		i;

  i = 0;
  thread = thread_maker(this->cam->nb_core);
  while (i < this->cam->nb_core)
    {
      data = data_maker(this, rect, i);
      if (i == 0)
	data->refresh = 0;
      if (pthread_create(&thread[i],
			 NULL,
			 thread_render_line,
			 (void*)data) != 0)
	w_error("thread creation error");
      i += 1;
    }
  wait_thread(thread, this->cam->nb_core);
}
