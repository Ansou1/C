/*
** get_bit.c for serveur_minitlak in /home/daguen_s//talk/serveur
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:52:45 2013 simon daguenet
** Last update Sun Mar 24 00:53:38 2013 simon daguenet
*/

#include "serveur.h"

void	nbr_client1(int sig)
{
  get_nbr_client(0);
}

void	nbr_client2(int sig)
{
  get_nbr_client(1);
}

void	send_bit1(int sig)
{
  my_receive_bit(1);
}

void	send_bit2(int sig)
{
  my_receive_bit(0);
}
