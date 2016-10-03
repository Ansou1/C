#include <time.h>
#include <mlx.h>
#include <X11/Xlib.h>

#include "utils.h"
#include "maths.h"

static t_mlx_win	*create_window(char *path)
{
  t_mlx_win		*win;

  win = w_malloc(sizeof(*win));
  win->xclient = mlx_init();
  if (win->xclient == 0)
    w_error("mlx_init failure");
  win->cwindow = mlx_new_window(win->xclient, WIN_WIDTH,
				WIN_HEIGHT, path);
  if (win->cwindow == 0)
    w_error("mlx_new_window failure");
  win->m_image = mlx_new_image(win->xclient, WIN_WIDTH, WIN_HEIGHT);
  if (win->m_image == 0)
    w_error("mlx_new_image failure");
  win->m_img_addr = mlx_get_data_addr(win->m_image,
				      &(win->pixelsize),
				      &(win->linesize),
				      &(win->endianess));
  if (win->m_img_addr == 0)
    w_error("mlx_get_data_addr failure");
  win->pixelsize /= 8;  XInitThreads();
  srand(time(NULL));
  return (win);
}

static t_cam		*create_cam()
{
  t_cam			*new;

  new = w_malloc(sizeof(t_cam));
  new->pos = w_malloc(sizeof(t_coords));
  new->angle = w_malloc(sizeof(t_coords));
  new->pos->x = -1000;
  new->pos->y = 0;
  new->pos->z = 1000;
  new->angle->x = 0;
  new->angle->y = 45;
  new->angle->z = 0;
  new->ratio_pixel = 1;
  return (new);
}

t_rt			*create_session(int argc, char **argv)
{
  t_rt			*new;

  srand(time(0));
  new = w_malloc(sizeof(*new));
  new->multi_thread = XInitThreads();
  new->cam = create_cam();
  new->temps.d_sample = NULL;
  new->pfx[0] = '\0';
  if (argc > 1)
    parse_xml(new, argv[1]);
  else
    w_error("No file to render.");
  new->win = create_window(argv[1]);
  init_rndms(new);
  new->photons = launch_photons(new->lights, new);
  return (new);
}
