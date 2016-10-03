/*
** serveur.c for minitalk in /home/daguen_s//talk
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Mar  4 15:12:38 2013 simon daguenet
** Last update Sun Mar 24 00:58:05 2013 simon daguenet
*/

#include "serveur.h"

int	g_pid_client;

int		get_nbr_client(int bit)
{
  static int	i;

  g_pid_client += (bit << i++);
  if (i == 32)
    i = 0;
}

int		my_receive_bit(int bit)
{
  static char	c;
  static int	i;

  c += (bit << i++);
  if (i == 8)
    {
      i = 0;
      write(1, &c, 1);
      if (c == '\0')
	{
	  g_pid_client = 0;
	  my_putchar('\n');
	  return (0);
	}
      c = 0;
    }
  if ((kill(g_pid_client, SIGUSR1)) == -1)
    my_puterror("Error kill in my_receive_bit.\n");
}

void	client_pid()
{
  int	i;

  i = 0;
  while (i < 32)
    {
      if ((signal(SIGUSR1, nbr_client1)) == SIG_ERR)
	my_puterror("Error signal in client_pid.\n");
      if ((signal(SIGUSR2, nbr_client2)) == SIG_ERR)
	my_puterror("Error signal in client_pid.\n");
      pause();
      i++;
    }
}

int	main(int ac, char **av)
{
  int	pid;

  if (ac != 1)
    my_puterror("Usage : ./server\n");
  g_pid_client = 0;
  pid = getpid();
  my_printf("Welcome to my minitalk!\nServer PID is: %d\n", pid);
  client_pid();
  while (42)
    {
      if ((signal(SIGUSR1, send_bit1)) == SIG_ERR)
	my_puterror("Error signal in main.\n");
      if ((signal(SIGUSR2, send_bit2)) == SIG_ERR)
	my_puterror("Error signal in main.\n");
      pause();
      if (g_pid_client == 0)
	client_pid();
    }
  return (EXIT_SUCCESS);
}
