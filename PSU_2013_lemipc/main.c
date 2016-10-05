/*
** main.c for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 22 21:42:52 2014 daguen_s
** Last update Fri Apr 11 09:31:33 2014 daguen_s
*/

#include "lemipc.h"

int		get_arg(t_lemipc *this, int ac, char **av)
{
  int		c;

  MAP = 100;
  this->key = get_key();
  while ((c = getopt(ac, av, "t:g")) != -1)
    {
      if (c == 't' && optind <= ac)
	this->team_player = atoi(optarg);
      else if (c == 'g')
        this->status |= GRAPHIC_MODE;
      else if (c  == '?')
	return (1);
    }
  if (this->team_player < 0 || this->team_player > 9)
    return (1);
  return (0);
}

void		init_the_game(t_lemipc *this)
{
  this->shm_id = shmget(this->key, MAP * MAP + 1, RW);
  if (this->shm_id == -1)
    {
      if ((this->shm_id = shmget(this->key, MAP * MAP + 1, IPC_CREAT | RW)) == -1)
	errx(EXIT_FAILURE, "Error : %s", strerror(errno));
      if ((this->map = (unsigned char *)shmat(this->shm_id, NULL, RW))
	  == (void*)-1)
        errx(EXIT_FAILURE, "Error : %s", strerror(errno));
      memset(this->map, 0, (MAP * MAP + 1));
      if (this->status & GRAPHIC_MODE)
        if (init_sdl(this) == -1)
          this->status &= ~GRAPHIC_MODE;
      this->status |= SERVER;
    }
  if ((this->map = (unsigned char *)shmat(this->shm_id, NULL, RW)) == (void*)-1)
    errx(EXIT_FAILURE, "Error : %s", strerror(errno));
  this->sem_id = semget(this->key, 1, RW);
  if (this->sem_id == -1)
    {
      if ((this->sem_id = semget(this->key, 1, IPC_CREAT | RW)) == -1)
        errx(EXIT_FAILURE, "Error : %s", strerror(errno));
      if (semctl(this->sem_id, 0, SETVAL, 1) == -1)
        errx(EXIT_FAILURE, "Error : %s", strerror(errno));
    }
}

int		main(int ac, char **av)
{
  t_lemipc	this;

  this.status = ALIVE;
  if (get_arg(&this, ac, av))
    errx(EXIT_FAILURE, USAGE);
  if (this.map_size < 2)
    errx(EXIT_FAILURE, "ERROR lemipc invalide map size");
  srand(time(NULL));
  init_the_game(&this);
  if (pop_near_friend(&this) == -1 && !(this.status & SERVER))
    return (0);
  while (get_number_of_team(&this) == 1)
    usleep(100000);
  lets_go(&this);
  return (0);
}
