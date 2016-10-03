/*
** client.h for minitalk_client in /home/daguen_s//talk/client
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:22:20 2013 simon daguenet
** Last update Sun Mar 24 00:31:12 2013 simon daguenet
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

	/* tools_clt.c */
int	my_strlen(char *str);
void	my_puterror(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *str);

	/* print.c */
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putnbr_base2(int nb, char *base);
void	my_print_char(va_list ap, char format);
void	my_printf(char *format, ...);

	/* client.c */
void	my_send_char(int pid, char c);
void	handle_sig();
void	my_sig();
void	send_pid_client(int pid_client, int pid);

#endif
