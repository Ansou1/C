#include"rt.h"

t_color		get_pixel_color(t_mlx_win *win, int x, int y)
{
  int		i;
  int		pos;
  t_color	pixel;

  pixel = 0;
  pos = win->pixelsize * x + win->linesize * y;
  i = 0;
  while (i < win->pixelsize && i < 3)
    {
      pixel *= 256;
      if (win->endianess == 0)
	pixel += (unsigned char)win->m_img_addr[pos + 3 - i - 1];
      else
	pixel += (unsigned char)win->m_img_addr[pos + i + 1];
      i++;
    }
  return (pixel);
}

void		apply_postfx(t_rt *this)
{
  t_color	new;
  int		x;
  int		y;

  x = 0;
  if (this->pfx[0] == 0)
    return ;
  while (x < WIN_WIDTH)
    {
      y = 0;
      while (y < WIN_HEIGHT)
	{
	  new = get_pixel_color(this->win, x, y);
	  new = app_fx(this, new, x, y);
	  print_pixel(this->win, x, y, new);
	  y++;
	}
      refresh_render(this->win);
      x++;
    }
}
