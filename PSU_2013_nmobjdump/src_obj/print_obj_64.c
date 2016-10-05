/*
** print_obj_64.c for  in /home/daguen_s/rendu/nm-objdump/src_obj
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 15 12:51:04 2014 daguen_s
** Last update Tue Mar 18 12:12:24 2014 daguen_s
*/

#include "objdump.h"

char		*get_class64(Elf64_Ehdr *elf)
{
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    return ("elf32");
  else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    return ("elf64");
  else if (elf->e_ident[EI_CLASS] == ELFCLASSNONE)
    return ("unknown");
  return ("unknown");
}

char		*get_machine64(Elf64_Ehdr *elf)
{
  if (elf->e_machine < 94)
    return (my_machine[elf->e_machine]);
  else
    return ("unknown");
}

void		print_header64(t_objdump_64 obj)
{
  printf("\n%s:     file format %s-%s\n", obj.file, get_class64(obj.elf)
	 , get_machine64(obj.elf));
  if (obj.elf->e_type == ET_EXEC)
    {
      printf("architecture: i386:%s, flags 0x00000112:\n",
	     get_machine64(obj.elf));
      printf("EXEC_P, HAS_SYMS, D_PAGED\n");
    }
  if (obj.elf->e_type == ET_REL)
    {
      printf("architecture: i386:%s, flags 0x00000011:\n",
	     get_machine64(obj.elf));
      printf("HAS_RELOC, HAS_SYMS\n");
    }
  if (obj.elf->e_type == ET_DYN)
    {
      printf("architecture: i386:%s, flags 0x00000150:\n",
	     get_machine64(obj.elf));
      printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
    }
  printf("start address 0x%016x\n", (int)obj.elf->e_entry);
}

int		print_asci(Elf64_Shdr *shdr, char *tmp, int i, int j)
{
  if (tmp[shdr[i].sh_offset + j] > 31 && tmp[shdr[i].sh_offset + j] < 127)
    return (printf("%c", tmp[shdr[i].sh_offset + j]));
  else
    return (printf("."));
}

int		print_body_section(Elf64_Shdr *shdr, char *tmp,
				   int i, int tab[4])
{
  tab[1] = 0;
  tab[3] = 0;
  while (tab[1] < shdr[i].sh_size)
    {
      if (tab[1] % 16 == 0)
	{
	  tab[2] = 0;
	  printf(" %04x ", (unsigned int)shdr[i].sh_addr + tab[1]);
	  tab[0] = -1;
	  while ((++tab[0] + tab[1] < shdr[i].sh_size) && tab[0] != 16)
	    {
	      tab[2] += printf("%02x", TMP + tab[0] + tab[1]]);
	  if (tab[0] == 3 || tab[0] == 7 || tab[0] == 11)
	    tab[2] += printf(" ");
	}
      while (tab[2]++ < 35)
	printf(" ");
      printf("  ");
    }
  tab[3] += print_asci(shdr, tmp, i, tab[1]);
  tab[1]++;
  if (tab[1] % 16 == 0 && (tab[1] != shdr[i].sh_size))
    printf("\n");
}
  return (tab[3]);
}
