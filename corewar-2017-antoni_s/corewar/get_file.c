/*
** get_file.c for corewar in /home/efilon/corewar-2017-antoni_s/corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Sun Mar 17 20:02:10 2013 sebastien antonico
** Last update Wed Mar 20 02:15:28 2013 sebastien antonico
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libmy/my.h"
#include "corewar.h"
#include "op.h"

int	inv_nb(unsigned int nb)
{
  unsigned int	res;

  res = 0;
  while (nb != 0)
    {
      res <<= 8;
      res += (nb & 0xff);
      nb >>= 8;
    }
  return (res);
}

t_champ		get_binary(char *name)
{
  t_champ	champ;
  int		fd;
  int		ret;
  static int	nb_ch;

  if (nb_ch > 3)
    my_puterr("Only four champions can fight in the arena.\n");
  if ((fd = open(name, O_RDONLY)) == -1)
    my_puterr("Erreur lors de l'ouverture d'un fichier.\n");
  if ((ret = read(fd, &(champ.header), sizeof(champ.header))) == -1)
    my_puterr("Erreur lors de la lecture d'un fichier.\n");
  champ.header.magic = inv_nb((unsigned int)champ.header.magic);
  if (champ.header.magic != COREWAR_EXEC_MAGIC)
    my_puterr("Le fichier n'est pas valide.\n");
  champ.header.prog_size = inv_nb((unsigned int)champ.header.prog_size);
  if ((champ.binary = malloc((unsigned int)champ.header.prog_size)) == NULL)
    my_puterr("Erreur fatale lors d'un malloc.\n");
  if (read(fd, champ.binary, (unsigned int)champ.header.prog_size) == -1)
    my_puterr("Erreur lors de la lecture du binaire.\n");
  nb_ch++;
  close(fd);
  return (champ);
}
