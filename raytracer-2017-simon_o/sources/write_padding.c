/*
** write_padding.c for raytracer in /home/racaud_j/Documents/Work/svn/raytracer-2017-simon_o/rt
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Sun Jun  9 13:38:39 2013 jonathan racaud
** Last update Sun Jun  9 13:39:08 2013 jonathan racaud
*/

#include "raytracer.h"

void	write_padding(int data_wrote, char *data)
{
  while (data_wrote % 4 != 0)
    data[data_wrote++] = 0;
}

