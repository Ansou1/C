#include <mlx.h>

#include "rt.h"
#include "multi_thread.h"

void	print_pixel(t_mlx_win *win, int x, int y, t_color color)
{
  int		i;
  int		pos;
  t_color	ncolor;

  i = 0;
  pos = win->pixelsize * x + win->linesize * y;
  ncolor = mlx_get_color_value(win->xclient, color);
  while (i < win->pixelsize)
    {
      if (win->endianess == 0)
	win->m_img_addr[pos + i] = ncolor % 256;
      else
	win->m_img_addr[pos + win->pixelsize - i - 1] = ncolor % 256;
      ncolor >>= 8;
      i++;
    }
}

static void	render_rect(t_rt *this, t_rectangle *rect)
{
  t_uint	i;
  t_uint	j;
  t_color	clr;

  this->cam->effects_active = TRUE;
  if (rect->width > 1 || rect->height > 1)
    this->cam->effects_active = FALSE;
  clr = calc_color(this, rect->x, rect->y);
  i = 0;
  while (i < rect->width)
    {
      j = 0;
      while (j < rect->height)
	{
	  if (rect->x + i < WIN_WIDTH && rect->y + j < WIN_HEIGHT)
	    print_pixel(this->win, rect->x + i, rect->y + j, clr);
	  j++;
	}
      i++;
    }
}

void	refresh_render(t_mlx_win *win)
{
  mlx_put_image_to_window(win->xclient, win->cwindow,
			  win->m_image, 0, 0);
}

void	render_line(t_rt *this, t_rectangle *rect, int ref)
{
  (void)ref;
  rect->y = 0;
  while (rect->y < WIN_HEIGHT)
    {
      if (rect->y == 0)
	refresh_render(this->win);
      render_rect(this, rect);
      rect->y += rect->height;
    }
}

void	render_session(t_rt *this, char *saving)
{
  t_rectangle	rect;

  rect.width = WIN_WIDTH;
  rect.height = WIN_HEIGHT;
  while (rect.width > 1 || rect.height > 1)
    {
      rect.width /= 6;
      rect.height /= 6;
      if (rect.width < 1)
	rect.width = 1;
      if (rect.height < 1)
	rect.height = 1;
      rect.x = 0;
      if (rect.height == 1 && rect.width == 1
	  && this->cam->nb_core > 1 && this->multi_thread != 0)
	multi_thread(this, &rect);
      else
	while (rect.x < WIN_WIDTH)
	  {
	    render_line(this, &rect, 0);
	    rect.x += rect.width;
	  }
    }
  view_loop(this, saving);
}
