/*
** objdump.h for  in /home/daguen_s/rendu/nm-objdump/src_obj
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Mar 13 12:23:23 2014 daguen_s
** Last update Sat Mar 15 15:08:13 2014 daguen_s
*/

#ifndef _OBJDUMP_H_
# define _OBJDUMP_H_

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct	s_objdump_64
{
  Elf64_Shdr	*shdr;
  Elf64_Ehdr	*elf;
  void		*data;
  char		*strtab;
  char		*file;
  unsigned int	size;
}		t_objdump_64;

typedef struct	s_objdump_32
{
  Elf32_Shdr	*shdr;
  Elf32_Ehdr	*elf;
  void		*data;
  char		*strtab;
  char		*file;
  unsigned int	size;
}		t_objdump_32;

# define	CMP(x)	(strcmp(&obj.strtab[obj.shdr[i].sh_name], x))
# define	NAME	obj.shdr[i].sh_name
# define	SIZE	sizeof(NAME)
# define	TMP	(unsigned char)tmp[shdr[i].sh_offset

static char *my_machine[] =
  {
    "none",
    "AT&T",
    "sun",
    "i386",
    "m68k",
    "m88k",
    "none",
    "i860",
    "r3000",
    "S370",
    "r3000le",
    "none",
    "none",
    "none",
    "none",
    "HPPA",
    "none",
    "VPP500",
    "v8plus",
    "i960",
    "ppc",
    "ppc64",
    "S390",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "V800",
    "FR20",
    "RH32",
    "RCE",
    "ARM",
    "Alpha",
    "SH",
    "sparcv9",
    "TriCore",
    "ARC",
    "H8_300",
    "H8_300H",
    "H8S",
    "H8_500",
    "IA_64",
    "MIPS_X",
    "COLDFIRE",
    "M68HC12",
    "MMA",
    "PCP",
    "NCPU",
    "NDR1",
    "STARCORE",
    "ME16",
    "ST100",
    "TINYJ",
    "x86-64",
    "PDSP",
    "none",
    "none",
    "FX66",
    "ST9PLUS",
    "ST7",
    "M68HC16",
    "M68HC11",
    "M68HC08",
    "M68HC05",
    "SVX",
    "ST19",
    "VAX",
    "CRIS",
    "JAVELIN",
    "FIREPATH",
    "ZSP",
    "MMIX",
    "HUANY",
    "PRISM",
    "AVR",
    "FR30",
    "D10V",
    "D30V",
    "V850",
    "M32R",
    "MN10300",
    "MN10200",
    "PJ",
    "OPENRISC",
    "ARC_A5",
    "XTENSA",
  };

/* main.c */
void		my_objdump(char *file);
int		check_validity(char *file);
int		main(int ac, char **av);

/* xfunction */
int		xaccess(char *file);
int		xopen(char *pathname, int flags);
int		xclose(int fd);
long		xlseek(int fd);
void		*xmmap(int fd, char *file, unsigned int size);

/* obj_64.c */
char		*get_class64(Elf64_Ehdr *elf);
char		*get_machine64(Elf64_Ehdr *elf);
void		print_header64(t_objdump_64 obj);
int		print_asci(Elf64_Shdr *shdr, char *tmp, int i, int j);
int		print_body_section(Elf64_Shdr *, char *, int, int tab[4]);
int		print_format64(t_objdump_64 obj);
int		is_good_elf64(Elf64_Ehdr *elf);
void		format_64(char *file, unsigned int size, void *data);

/* obj_32.c */
char		*get_class32(Elf32_Ehdr *elf);
char		*get_machine32(Elf32_Ehdr *elf);
int		is_good_elf32(Elf32_Ehdr *elf);
void		print_header32(t_objdump_32 obj);
int		print_asci32(Elf32_Shdr *shdr, char *tmp, int i, int j);
int		print_body_section32(Elf32_Shdr *, char *, int, int tab[4]);
int		print_format32(t_objdump_32 obj);
void		format_32(char *file, unsigned int size, void *data);

#endif /* _OBJDUMP_H_ */
