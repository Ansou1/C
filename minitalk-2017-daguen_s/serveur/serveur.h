/*
** serveur.h for serveur_minitalk in /home/daguen_s//talk/serveur
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:41:57 2013 simon daguenet
** Last update Sun Mar 24 00:59:41 2013 simon daguenet
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

	/* tools_srv.c */
int	my_strlen(char *str);
void	my_puterror(char *str);
char	*my_strcpy(char *str);

	/* print.c */
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putnbr_base2(int nb, char *base);
void	my_print_char(va_list ap, char format);
void	my_printf(char *format, ...);

	/* get_bit.c */
void	nbr_client1(int sig);
void	nbr_client2(int sig);
void	send_bit1(int sig);
void	send_bit2(int sig);

	/* serveur.c */
int	get_nbr_client(int bit);
int	my_receive_bit(int bit);
void	client_pid();

#endif
