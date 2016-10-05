/*
** term_and_win.c for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 17:14:55 2014 daguen_s
** Last update Fri Feb 28 17:22:56 2014 daguen_s
*/

#include "my_script.h"

void			set_termios(struct termios *term, struct winsize *win)
{
  if ((tcgetattr(0, term)) < 0 || (ioctl(0, TIOCGWINSZ, win) < 0))
    {
      fprintf(stderr, "impossible to get attribute.\n");
      exit(EXIT_FAILURE);
    }
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  term->c_lflag &= ~(ICANON | ECHO | ISIG);
  tcsetattr(0, TCSANOW, term);
}

void			set_back_termios(t_opt *opt)
{
  opt->term.c_lflag |= (ICANON | ECHO | ISIG);
  tcsetattr(0, TCSANOW, &opt->term);
}

void			sigwinch(int signal)
{
  struct		winsize winp;

  signal = signal;
  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &winp) < 0)
    return ;
  if (ioctl(opt->fd_master, TIOCSWINSZ, &winp) < 0)
    return ;
  if (kill(-1, SIGWINCH) == -1)
    return ;
}
