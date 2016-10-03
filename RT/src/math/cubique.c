#include <math.h>

#include "maths.h"

double	racinecubique(double x)
{
  return (x < 0.0 ? -exp((1.0 / 3.0) * log(-x)) : exp((1.0 / 3.0) * log(x)));
}

double	racinecubiquecomplex(double re, double img)
{
  double	module;
  double	arg;
  double	re_m;
  double	img_m;
  double	z_re;

  module = sqrt(re * re + img * img);
  re_m = re / module;
  img_m = img / module;
  if (re_m < 0.0 && img_m > 0.0)
    arg = acos(re_m);
  else
    arg = asin(img_m);
  z_re = exp((1.0 / 3.0) * log(module)) * cos(arg / 3.0);
  return (z_re);
}

static void	delta_minus_cub(t_complex *z0,
			   t_complex *z1,
			   t_complex *z2,
			   t_equation *ceq)
{
  t_equation	qeq;

  z0->img = z1->img = z2->img = 0.0;
  z0->re = racinecubiquecomplex(-1 * ceq->q / 2.0,
				sqrt(-1 * ceq->delta) / 2.0);
  z0->re += z0->re + ceq->s;
  qeq.a = 1.0;
  qeq.b = ceq->b + z0->re;
  qeq.c = ceq->c + z0->re * (ceq->b + z0->re);
  quadratique(&qeq, z1, z2);
}

static void	delta_major_cub(t_complex *z0,
			   t_complex *z1,
			   t_complex *z2,
			   t_equation *ceq)
{
  t_equation	qeq;

  z0->img = 0.0;
  z0->re = ceq->s + racinecubique((-1 * ceq->q + sqrt(ceq->delta)) / 2.0)
    + racinecubique((-1 * ceq->q - sqrt(ceq->delta)) / 2.0);
  qeq.a = 1.0;
  qeq.b = ceq->b + z0->re;
  qeq.c = ceq->c + z0->re * (ceq->b + z0->re);
  quadratique(&qeq, z1, z2);
}

double	cubique(t_equation *ceq,
	      t_complex *z0,
	      t_complex *z1,
	      t_complex *z2)
{
  ceq->d /= ceq->a;
  ceq->c /= ceq->a;
  ceq->b /= ceq->a;
  ceq->a = 1.0;
  ceq->s = -ceq->b / 3.0;
  ceq->p = - ceq->b * ceq->b / 3.0 + ceq->c;
  ceq->q = ceq->b / 27.0 * (ceq->b * ceq->b * 2 - 9 * ceq->c) + ceq->d;
  ceq->delta = ceq->q * ceq->q + 4.0 / 27.0 * (ceq->p * ceq->p * ceq->p);
  if (ceq->delta > 0.0)
    delta_major_cub(z0, z1, z2, ceq);
  else if (ceq->delta < 0.0)
    delta_minus_cub(z0, z1, z2, ceq);
  else
    {
      z0->img = z1->img = z2->img = 0.0;
      z0->re = ceq->s + 3 * ceq->q / ceq->p;
      z1->re = z2->re = ceq->s + -3 * ceq->q / 2 * ceq->p;
    }
  return (ceq->delta);
}
