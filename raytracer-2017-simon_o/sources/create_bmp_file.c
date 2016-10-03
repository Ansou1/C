/*
** create_bmp_file.c for raytracer in /home/Jonathan/Work/svn/raytracer-2017-simon_o/sources
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Wed May 15 16:38:36 2013 jonathan racaud
** Last update Sun Jun  9 16:06:15 2013 jonathan racaud
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

int	fill_structures(t_bmp_info *info, t_mlx *mlx)
{
  int	size;

  info->head_size = 40;
  info->img_height = WINDOW_Y;
  info->img_width = WINDOW_X;
  info->plane = 0x1;
  info->bpp = 24;
  info->compression = 0x0;
  info->res_x_pxm = 0x64;
  info->res_y_pxm = 0x64;
  info->img_size = WINDOW_X * WINDOW_Y * 3;
  info->palette = 0x0;
  info->vip_color = 0x0;
  size = info->img_size + 54;
  return (size);
}

void	write_header(int fd, t_bmp_header *header, t_bmp_info *info)
{
  char	offset[4];

  offset[0] = 0x36;
  offset[1] = 0x0;
  offset[2] = 0x0;
  offset[3] = 0x0;
  write(fd, &header->signature, 2);
  write(fd, &header->file_size, 4);
  write(fd, &header->zero, 4);
  write(fd, offset, 4);
  write(fd, &info->head_size, 4);
  write(fd, &info->img_width, 4);
  write(fd, &info->img_height, 4);
  write(fd, &info->plane, 2);
  write(fd, &info->bpp, 2);
  write(fd, &info->compression, 4);
  write(fd, &info->img_size, 4);
  write(fd, &info->res_x_pxm, 4);
  write(fd, &info->res_y_pxm, 4);
  write(fd, &info->palette, 4);
  write(fd, &info->vip_color, 4);
}

void	write_color(int color, char *data, int x)
{
  char	*c;

  c = (char *)&color;
  data[x++] = c[2];
  data[x++] = c[1];
  data[x] = c[0];
}

int	write_scene(int fd, t_mlx *mlx, size_t size)
{
  int	x;
  int	y;
  char	*data_bmp;

  y = WINDOW_Y;
  if ((data_bmp = malloc(size)) == NULL)
    my_puterr("Erreur malloc\n");
  memset(data_bmp, 0, size);
  while (y > 0)
    {
      x = 0;
      while (x < WINDOW_X)
	{
	  write_color(GET_COLOR_BMP(x, y), data_bmp,
		      (WINDOW_Y - y) * (WINDOW_X * 3) + (x * 3));
	  x++;
	}
      write_padding(x * 3, data_bmp);
      y--;
    }
  write(fd, data_bmp, size);
  free(data_bmp);
  return (0);
}

int		create_bmp_file(t_mlx *mlx)
{
  t_bmp_header	header;
  t_bmp_info	info;
  int		fd;

  if ((fd = open(mlx->image->name, O_CREAT | O_WRONLY | O_TRUNC, 00664)) == -1)
    {
      printf("Error opening file %s\n", mlx->image->name);
      close(fd);
      return (-1);
    }
  header.signature = 0x4D42;
  header.file_size = fill_structures(&info, mlx);
  header.zero = 0x0;
  write_header(fd, &header, &info);
  write_scene(fd, mlx, info.img_size);
  return (fd);
}
