#include <math.h>

#include "maths.h"

void	get_cube_quart(t_quartet *q,
		   t_complex *z0,
		   t_complex *z1,
		   t_complex *z2)
{
  t_equation	ceq;

  ceq.a = 8.0;
  ceq.b = -(4.0 * q->p);
  ceq.c = -(8.0 * q->r);
  ceq.d = 4.0 * q->r * q->p - (q->q * q->q);
  cubique(&ceq, z0, z1, z2);
}

static void	fill_quartet(t_quartet *q, t_complex z[3])
{
  t_equation	qeq;

  q->a0.img = q->b0.img = 0.0;
  q->a0.re = sqrt(q->a0.re);
  q->b0.re = -1 * q->q / (2.0 * q->a0.re);
  qeq.a = 1.0;
  qeq.b = -1 * q->a0.re;
  qeq.c = q->x0 - q->b0.re;
  quadratique(&qeq, &z[0], &z[1]);
  qeq.b = q->a0.re;
  qeq.c = q->x0 + q->b0.re;
  quadratique(&qeq, &z[2], &z[3]);
  z[0].re += q->s;
  z[1].re += q->s;
  z[2].re += q->s;
  z[3].re += q->s;
}

double	quartique(t_equation *eq,
		t_complex z[3])

{
  t_quartet	q;

  eq->e /= eq->a;
  eq->d /= eq->a;
  eq->c /= eq->a;
  eq->b /= eq->a;
  eq->a = 1.0;
  q.s = -eq->b / 4.0;
  q.p = (-3.0 * eq->b * eq->b) / 8.0 + eq->c;
  q.q = (eq->b / 2.0 * eq->b / 2.0 * eq->b / 2.0) - 0.5 *
    eq->b * eq->c + eq->d;
  q.r = -3.0 * (eq->b / 4.0 * eq->b / 4.0 * eq->b / 4.0 * eq->b / 4.0)
    + eq->c * (eq->b / 4.0 * eq->b / 4.0) - 0.25 * eq->b * eq->d + eq->e;
  get_cube_quart(&q, &z[0], &z[1], &z[2]);
  q.x0 = z[0].re;
  q.a0.re = -1 * q.p + 2.0 * q.x0;
  if (q.a0.re < 0.0)
    return (-1);
  else
    fill_quartet(&q, z);
  return (1);
}
