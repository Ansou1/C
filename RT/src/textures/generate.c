#include "utils.h"
#include "maths.h"

static void	recreate_img(t_img *img, t_obj_type type)
{
  unsigned int	i;

  (void)type;
  if (img->val != NULL)
    {
      i = 0;
      while (i < img->ysize)
	free(img->val[i++]);
      free(img->val);
    }
  img->xsize = DEF_TXT_SIZE;
  img->ysize = DEF_TXT_SIZE;
  img->amp = 1;
  img->rep = 360;
  img->val = w_malloc(sizeof(int *) * img->ysize);
  i = 0;
  while (i < img->ysize)
    img->val[i++] = w_malloc(sizeof(int) * img->xsize);
}

static void	gen_tole(t_img *img, int mod)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y < img->ysize)
    {
      x = 0;
      while (x < img->xsize)
	{
	  if (mod == 1)
	    img->val[y][x] = (my_cos(y * 8) * 100 + 128) * 256 * 256;
	  if (mod == 2)
	    img->val[y][x] = (my_cos(x * 8) * 100 + 128) * 256;
	  if (mod == 3)
	    img->val[y][x] = (my_cos(y * 8) * 100 + 128) * 256
	      + (my_cos(x * 2) * 100 + 128) * 256 * 256;
	  if (mod == 6)
	    img->val[y][x] = (rand() % 256) * 256
	      + (rand() % 256) * 256 * 256 + rand() % 256;
	  x++;
	}
      y++;
    }
}

static void	gen_dam(t_color color, t_img *img, int type)
{
  unsigned int	i;
  unsigned int	j;

  j = 0;
  while (j < img->ysize)
    {
      i = 0;
      while (i < img->xsize)
	{
	  if (type == 2 && (j + i) / 103 % 2)
	    img->val[j][i] = !color;
	  else if (type == 1 && (j / 90 % 2 == i / 90 % 2))
	    img->val[j][i] = !color;
	  else if (type == 3 && (i % 37 >= 30 && (j + i) / 20 % 4))
	    img->val[j][i] = !color;
	  else
	    img->val[j][i] = color;
	  i++;
	}
      j++;
    }
}

void	generate_modifiers(t_rt *this, t_object *new)
{
  (void)this;
  if (new->color_mod >= 1 && new->color_mod <= 6)
    {
      if (new->texture == NULL)
	new->texture = w_malloc(sizeof(t_img));
      recreate_img(new->texture, new->type);
      if (new->color_mod >= 1 && new->color_mod <= 3)
	gen_dam(new->color, new->texture, new->color_mod);
      if (new->color_mod >= 4 && new->color_mod <= 5)
	gen_perlin(new->color, !new->color, new->texture, new->color_mod);
      if (new->color_mod == 6)
	gen_tole(new->texture, 6);
    }
  if (new->norml_mod >= 1 && new->norml_mod <= 6)
    {
      if (new->bumpmap == NULL)
	new->bumpmap = w_malloc(sizeof(t_img));
      recreate_img(new->bumpmap, new->type);
      if (new->norml_mod >= 1 && new->norml_mod <= 3)
	gen_tole(new->bumpmap, new->norml_mod);
      if (new->norml_mod >= 4 && new->norml_mod <= 5)
	gen_perlin(0xffffff, 0x0000ff, new->bumpmap, new->norml_mod);
      if (new->norml_mod == 6)
	gen_tole(new->bumpmap, 6);
    }
}
