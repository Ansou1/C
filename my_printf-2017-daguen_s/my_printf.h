/*
** my_printf.h for printf in /home/daguen_s//myownprintf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 13 11:15:39 2012 simon daguenet
** Last update Sun Nov 18 21:50:54 2012 simon daguenet
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

int	my_printf(char *format, ...);
int	my_print_char(va_list ap, char format);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_getnbr(char *str);
int	my_putnbr_base2(long nb, char *base);
int	my_strlen(char *str);
int	*init_var(int *tab);
int	exeption(char *format, int tab);
int	flag(char *format, int tab);

#endif
