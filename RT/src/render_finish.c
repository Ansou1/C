#include <stdlib.h>
#include <mlx.h>

#include "rt.h"

int		event_func(int key, void *param)
{
  (void)param;
  if (key == 65307)
    exit(EXIT_SUCCESS);
  return (0);
}

int		event_expose(void *param)
{
  refresh_render((t_mlx_win *)param);
  return (0);
}

void		view_loop(t_rt *this, char *saving)
{
  t_mlx_win	*win;

  win = this->win;
  apply_postfx(this);
  save_image(this, saving);
  mlx_key_hook(win->cwindow, &event_func, win);
  mlx_expose_hook(win->cwindow, &event_expose, win);
  mlx_loop(win->xclient);
}
