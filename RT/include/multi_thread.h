#ifndef MULTI_THREAD_H_
# define MULTI_THREAD_H_

typedef struct s_data
{
  t_rt		*this;
  t_rectangle	*rect;
  t_uint	x_max;
  int		refresh;
}		t_data;

void		render_line(t_rt *this, t_rectangle *rect, int ref);
t_rt		*copy_tmp_session(t_rt *this);
void		multi_thread(t_rt *this, t_rectangle *rect);
void		free_session_copy(t_rt *this);

#endif/* !MULTI_THREAD_H_ */
