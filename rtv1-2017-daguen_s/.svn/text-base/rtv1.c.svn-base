/*
** tp_1.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Jan 22 21:52:32 2013 simon daguenet
** Last update Sun Mar 17 16:32:53 2013 simon daguenet
*/

#include "rtv1.h"

t_result	equation_second(double a, double b, double c)
{
  t_result	ret;

  ret.delta = (b * b) - (4 * a * c);
  ret.a = (-b + sqrt(ret.delta)) / (2.f * a);
  ret.b = (-b - sqrt(ret.delta)) / (2.f * a);
  if (ret.a > 0 && ret.b > 0)
    {
      if (ret.a <= ret.b)
  	ret.min = ret.a;
      else
  	ret.min = ret.b;
    }
  else
    {
      if (ret.a > 0 && ret.b < 0)
  	ret.min = ret.a;
      else if (ret.a < 0 && ret.b > 0)
  	ret.min = ret.b;
      else
  	ret.min = -1.0;
    }
  return (ret);
}

t_result	calc_plan(t_element *param, int x, int y)
{
  t_point_3d	eyes;
  t_point_3d	vect;
  t_result	ret;

  eyes = param->eyes;
  vect.x = 100;
  vect.y = (WIDTH / 2) - (double)x - param->eyes.y;
  vect.z = (HEIGHT / 2) - (double)y - param->eyes.z;
  eyes = rotate_inv(eyes, param->plan);
  vect = rotate_inv(vect, param->plan);
  if (vect.z != 0.f)
    ret.min = -(param->eyes.z / vect.z);
  else
    ret.min = -1;
  ret.n.x = 0;
  ret.n.y = 0;
  ret.n.z = 100;
  ret.sec.x = param->eyes.x + ret.min * vect.x;
  ret.sec.y = param->eyes.y + ret.min * vect.y;
  ret.sec.z = param->eyes.z + ret.min * vect.z;
  return (ret);
}

int		calc_all(t_element *param, int x, int y)
{
  t_result	k_sphere;
  t_result	k_plan;
  t_result	k_cylindre;
  t_result	k_cone;
  int		color;

  k_sphere = calc_sphere(param, x, y);
  k_plan = calc_plan(param, x, y);
  k_cylindre = calc_cylindre(param, x, y);
  k_cone = calc_cone(param, x, y);
  color = get_k_min(k_sphere.min, k_plan.min, k_cylindre.min, k_cone.min);
  if (color == RED)
    color = light(color, k_sphere, param->lig);
  if (color == BLUE)
    color = light(color, k_plan, param->lig);
  if (color == GREEN)
    color = light(color, k_cone, param->lig);
  if (color == YELLOW)
    color = light(color, k_cylindre, param->lig);
  mlx_put_pixel_to_img(param->img, x, y, color);
}

int	draw(t_element *param)
{
  int	x;
  int	y;

  param->eyes = rotate(param->eyes, param->r_eyes);
  x = 0;
  while (x != WIDTH)
    {
      y = 0;
      while (y != HEIGHT)
	{
	  calc_all(param, x, y);
	  y++;
	}
      x++;
    }
  mlx_put_image_to_window(param->mlx_ptr
			, param->win_ptr, param->img.image, 0, 0);
  return (0);
}

int		main()
{
  t_element	param;

  if ((param.mlx_ptr = mlx_init()) == NULL)
    exit(EXIT_FAILURE);
  if ((param.win_ptr = mlx_new_window
       (param.mlx_ptr, WIDTH, HEIGHT, "rtv1")) == NULL)
    exit(EXIT_FAILURE);
  if ((param.img.image = mlx_new_image(param.mlx_ptr, WIDTH, HEIGHT)) == NULL)
    exit(EXIT_FAILURE);
  param.img.data = mlx_get_data_addr
    (param.img.image, &param.img.bpp, &param.img.sizeline, &param.img.endian);
  if (param.img.data == NULL)
    exit(EXIT_FAILURE);
  init(&param);
  draw(&param);
  mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img.image, 0, 0);
  mlx_expose_hook(param.win_ptr, gere_expose, &param);
  mlx_key_hook(param.win_ptr, gere_key, &param);
  mlx_loop(param.mlx_ptr);
  return (0);
}
