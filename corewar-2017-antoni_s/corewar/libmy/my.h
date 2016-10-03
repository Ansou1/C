/*
** my.h for my in /home/efilon/corewar-2017-antoni_s/corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Wed Mar 13 13:59:44 2013 sebastien antonico
** Last update Sun Mar 31 18:57:05 2013 sebastien antonico
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

void	my_puterr(char *err);
int	my_strlen(char *str);
int	my_putchar(char c);
int	my_putnbrXX(int nb);
void	my_memset(void *tab, int size);
int     my_strcpy(unsigned char *src, unsigned char *dest, int sizesrc);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);

/* printf */
int     parsing(char *str, int *id, va_list list);
int     my_putthing(char c, va_list list, char flag);
int     my_putstr_spec(char *str);
int     my_putstr(char *str);
int     my_putptr(unsigned long i);
int     my_putnbr_us(unsigned long i, char c, int precision, char flag);
int     my_putnbr(int i, char flag);
int     my_putnbr_base(unsigned long i, char *base, char flag);
int     my_printf(char *str, ...);
int     my_nblen(unsigned int i);
int     my_find(char c, char *str);

#endif /* !MY_H_ */
