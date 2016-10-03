/*
** main.c for raytracer in /home/cheval_y//raytracer
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 14:58:03 2013 franck chevallier
** Last update Sun Jun  9 16:11:41 2013 jonathan racaud
*/

#include "raytracer.h"

static pthread_mutex_t	my_mutex;

int		estimation(t_mlx *mlx)
{
  static int	lines = 0;
  static double	pourcent;
  double	pas;
  double	fait;

  lines++;
  fait = lines;
  pas = WINDOW_X;
  pourcent = fait / pas;
  printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%d%%",
	 (int)(pourcent * 100));
  fflush(stdout);
  return (0);
}

int	fill_image(t_mlx *mlx, int x, int xmax, int y)
{
  while (x < xmax)
    {
      y = 0;
      while (y < WINDOW_Y)
  	{
  	  my_pixel_put_to_image(mlx, x, y, calc(x, y, mlx));
  	  y+=1;
  	}
      x+=1;
      pthread_mutex_lock (&my_mutex);
      estimation(mlx);
      pthread_mutex_unlock (&my_mutex);
    }
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img_ptr,
			  0, 0);
  return (0);
}

void	my_print_error(char *str)
{
  write(2, "Fichier ", 8);
  write(2, str, my_strlen(str));
  write(2, " invalide\n", 11);
}

char	*my_get_file_name(char *str)
{
  char	*name;
  int	i;
  int	len;

  len = strlen(str);
  if ((name = malloc(len + 5)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      name[i] = str[i];
      i++;
    }
  name[i++] = '.';
  name[i++] = 'b';
  name[i++] = 'm';
  name[i++] = 'p';
  name[i++] = 0;
  return (name);
}

int	main(int ac, char **av)
{
  pthread_mutex_init (&my_mutex, NULL);
  XInitThreads();
  srand(time(NULL));
  if (ac >= 2)
    do_rt(av);
  else
    manage_error("Usage : ./rtv1 \"configuration file\"");
  return (0);
}
