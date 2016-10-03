/*
** my_nblen.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:46:45 2012 sebastien antonico
** Last update Thu Nov 15 21:47:16 2012 sebastien antonico
*/

int	my_nblen(unsigned int i)
{
  if (i < 10)
    return (i);
  return (1 + my_nblen(i/10));
}
