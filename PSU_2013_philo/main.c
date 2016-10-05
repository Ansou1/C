/*
** main.c for  in /home/daguen_s/rendu/PSU_2013_philo
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Mar 10 11:58:30 2014 daguen_s
** Last update Sun Mar 23 21:24:20 2014 daguen_s
*/

#include "philo.h"

pthread_mutex_t	g_mutex[7];
t_philo		g_t_philo[7];
t_param		g_param;

void		*task(void *tmp)
{
  t_philo	*philo;
  unsigned char	used;

  philo = (t_philo*)tmp;
  while (--(philo->rice))
    {
      if (philo->state != THINK)
	used ^= used;
      if (philo->state != EAT)
	{
	  used += pthread_mutex_trylock(&g_mutex[philo->name]) != 0 ? 0 : 1;
	  used += pthread_mutex_trylock(&g_mutex[(philo->name + 1) % 7])
	    != 0 ? 0 : 2;
	}
      sleep(g_param.time);
      philo->state = (((used == 1) | (used == 2)) ? THINK :
		      ((used == 3) ? EAT : SLEEP));
      printf("%d %s %s\033[37m\n", g_t_philo->name, g_name[philo->name], g_state[philo->state]);
      if (used & 1 && philo->state != THINK)
	pthread_mutex_unlock(&g_mutex[philo->name]);
      if (used & 2 && philo->state != THINK)
	pthread_mutex_unlock(&g_mutex[(philo->name + 1) % 7]);
    }
  pthread_exit(NULL);
  return (NULL);
}

void		get_options(const int argc, const char * const * const argv)
{
  if (argc != 3 && argc != 1)
    errx(EXIT_FAILURE, "Syntaxe: ./philo [rice] [time]");
  g_param.rice = (argc == 3) ? atoi(argv[1]) : 10;
  if (g_param.rice < 10 || g_param.rice > 50)
    g_param.rice = 10;
  g_param.time = (argc == 3) ? atoi(argv[2]): 1;
  if (g_param.time > 5 || g_param.time < 1)
    g_param.time = 1;
}

int		main (const int argc, const char * const * const argv)
{
  register int	i;

  get_options(argc, argv);
  i = ~(i ^ i);
  while (++i < 7)
    {
      if (pthread_mutex_init(&(g_mutex[i]), NULL) != 0)
	errx(EXIT_FAILURE, "ERROR: %s.", strerror(errno));
      g_t_philo[i].state = SLEEP;
      g_t_philo[i].rice = g_param.rice + 1;
      g_t_philo[i].name = i;
    }
  i = ~(i ^ i);
  while (++i < 7)
    if (pthread_create(&g_t_philo[i].thread, NULL, task, &(g_t_philo[i])) != 0)
      errx(EXIT_FAILURE, "ERROR: %s.", strerror(errno));
  i = ~(i ^ i);
  while (++i < 7)
    if (pthread_join(g_t_philo[i].thread, NULL) != 0)
      errx(EXIT_FAILURE, "ERROR: %s.", strerror(errno));
  return (EXIT_SUCCESS);
}
