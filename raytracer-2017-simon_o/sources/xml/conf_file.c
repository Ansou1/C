/*
** conf_file.c for Raytracer in /home/Jonathan/Work/svn/raytracer-epitech/Raytracer_with_xml/sources/xml
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Mon Apr 22 14:40:49 2013 jonathan racaud
** Last update Sun Jun  9 15:09:55 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <regex.h>
#include "raytracer.h"

int	fill_xml(char *file, t_mlx *rt)
{
  int	fd;
  char	*line;
  char	*epur_line;
  int	type;
  int	ret;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (!fprintf(stderr, "%s : fichier invalide.\n", file) - 1);
  while ((line = get_next_line(fd)) != NULL)
    {
      epur_line = my_epur_str(line);
      if ((type = type_line_xml(epur_line)) == -1 && epur_line[0] != 0)
	return (!fprintf(stderr, "%s : ligne invalide.\n", epur_line) - 1);
      ret = (type == TYPE_OPEN_NODE) ? add_node(epur_line, rt) :
	((type == TYPE_CLOSING_NODE) ? close_node(epur_line, rt) :
	 (type == TYPE_ELEM) ? add_elem(epur_line, rt) :
	 ((type == TYPE_PROLOGUE || type == TYPE_COMMENT) ? TYPE_COMMENT : 0));
      if (!ret && epur_line[0] != 0)
	return (!fprintf(stderr, "%s : ligne invalide.\n", epur_line) - 1);
      free(line);
      free(epur_line);
    }
  return (0);
}

void		init_rt(t_mlx *rt)
{
  rt->list = NULL;
  rt->light = NULL;
  if ((rt->eye = malloc(sizeof(t_eye))) == NULL)
    my_puterr("Erreur malloc\n");
  (rt->eye)->eye_pos.x = 0;
  (rt->eye)->eye_pos.y = 0;
  (rt->eye)->eye_pos.z = 0;
  (rt->eye)->r_x = 0;
  (rt->eye)->r_y = 0;
  (rt->eye)->r_z = 0;
  rt->nb_lights = 0;
  rt->anti_aliasing = 1;
  rt->blur = 0;
  rt->width = 640;
  rt->height = 480;
  rt->nb_threads = 0;
  rt->filter = FILTER_NONE;
  rt->video.radius = 1000;
  rt->video.center_x = 0;
  rt->video.center_y = 0;
  rt->video.center_z = 0;
  rt->video.nb_images = 36;
}

int	check_conf(t_mlx *rt)
{
  if (rt->list == NULL || rt->light == NULL)
    return (0);
  rt->width = MAX(100, MIN(1920, rt->width));
  rt->height = MAX(100, MIN(1080, rt->height));
  rt->anti_aliasing = MAX(1, MIN(100, rt->anti_aliasing));
  if (rt->blur != 0)
    rt->anti_aliasing = MAX(8, rt->anti_aliasing);
  rt->nb_threads = MAX(0, MIN(20, rt->nb_threads)) + 1;
  return (1);
}

int		conf_file(t_mlx *rt, char *file)
{
  if ((rt->xml = malloc(sizeof(t_xml))) == NULL)
    my_puterr("Erreur malloc\n");
  (rt->xml)->stack = NULL;
  (rt->xml)->state = STATE_NONE;
  init_rt(rt);
  if (fill_xml(file, rt) == -1 || !check_conf(rt))
    return (0);
  return (1);
}
