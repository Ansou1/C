/*
** client.c for minitalk in /home/daguen_s//talk
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Mar  4 15:12:15 2013 simon daguenet
** Last update Sun Mar 24 00:25:36 2013 simon daguenet
*/

#include "client.h"

int	g_sig;

void	my_send_char(int pid, char c)
{
  char	charac;
  int	a;

  charac = 0;
  while (charac < 8)
    {
      a = 0;
      g_sig = 0;
      if (kill(pid, ((c >> charac) & 1) ? SIGUSR1 : SIGUSR2) == -1)
	my_puterror("Server is not reachable.\n");
      if (charac == 7 && c == '\0')
       	exit(0);
      while (g_sig == 0)
	{
	  if (a == 10000)
	    my_puterror("serveur closed\n");
	  a++;
	  usleep(1);
	}
      charac = charac + 1;
    }
}

void	handle_sig()
{
  g_sig = 1;
}

void	my_sig()
{
  if ((signal(SIGUSR1, handle_sig)) == SIG_ERR)
    my_puterror("ERROR with signal in my_sig.\n");
}

void	send_pid_client(int pid_client, int pid)
{
  int	i;

  i = 0;
  while (i < 32)
    {
      if (kill(pid, ((pid_client >> i) & 1) ? SIGUSR2 : SIGUSR1) == -1)
	my_puterror("Problem when I send the pid client.\n");
      i++;
      if ((usleep(1000)) == -1)
	my_puterror("ERROR in usleep send_pid_client.\n");
    }
}

int	main(int ac, char **av)
{
  char	*str;
  int	pid;
  int	pid_client;
  int	i;

  if (ac != 3)
    my_puterror("Usage: ./client [SERVER PID] [MESSAGE TO SEND].\n");
  i = 0;
  pid_client = getpid();
  my_printf("Client PID is: %d\n", pid_client);
  pid = my_getnbr(av[1]);
  if (pid <= 1)
    exit(1);
  str = my_strcpy(av[2]);
  send_pid_client(pid_client, pid);
  my_sig();
  while (str[i] != '\0')
    my_send_char(pid, str[i++]);
  my_send_char(pid, str[i]);
  g_sig = 0;
  free(str);
  return (EXIT_SUCCESS);
}
