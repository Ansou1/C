/*
** my_inf_mult_defines.h for bistro in /home/elegbe_m//programmation/bistro/bistro
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Fri Nov  2 10:56:51 2012 martial elegbede
** Last update Sat Nov 10 17:16:30 2012 martial elegbede
*/

#ifndef INF_MULT_DEFINES_H_
#define INF_MULT_DEFINES_H_

#define DIGIT_TO_VAL(x) (digit_to_val(base, x))
#define VAL_TO_DIGIT(x) (base[x])
#define BASE_LEN	(my_strlen(base))

typedef struct s_mul_elem
{
  char	*res;
  int	*r;
  int	p1;
  int	p2;
  int	neg;
}	t_type;

#endif
