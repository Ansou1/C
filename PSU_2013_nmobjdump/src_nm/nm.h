/*
** nm.h for  in /home/daguen_s/rendu/nm-objdump/src_nm
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 15 16:04:40 2014 daguen_s
** Last update Sun Mar 16 16:50:51 2014 daguen_s
*/

#ifndef _NM_H_
# define _NM_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

# define SIZE (obj.my_symtab->sh_size / sizeof(Elf64_Sym))

typedef struct	s_nm
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char		*strtab;
  void		*data;
  Elf64_Shdr	*my_strtab;
  Elf64_Shdr	*my_symtab;
  char		*file;
  unsigned int	size;
}		t_nm;

/* nm.c */
int		is_good_elf(Elf64_Ehdr *);
void		format_64(char *, unsigned int, void *);
void		my_nm(char *);
int		check_validity(char *);
int		get_the_tables_symbol(t_nm *);
char		get_the_symbol(t_nm, Elf64_Sym *, int);

/* xfunction.c */
int		xaccess(char *);
int		xopen(char *, int);
int		xclose(int);
long		xlseek(int);
void		*xmmap(int, char *, unsigned int);

#endif /* _NM_H_ */
