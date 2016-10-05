/*
** obj_64.c for  in /home/daguen_s/rendu/nm-objdump/src_obj
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Mar 13 12:28:43 2014 daguen_s
** Last update Sat Mar 15 12:52:27 2014 daguen_s
*/

#include "objdump.h"

int		get_good_section(t_objdump_64 obj, int i)
{
  if (obj.elf->e_type == ET_EXEC)
    return (obj.shdr[i].sh_size && CMP(".bss") != 0 && CMP(".shstrtab") != 0
	    && CMP(".strtab") != 0 && CMP(".symtab") != 0 &&
	    obj.shdr[i].sh_type != SHT_NULL);
  if (obj.elf->e_type == ET_REL)
    return (obj.shdr[i].sh_size && CMP(".bss") != 0 && CMP(".shstrtab") != 0
	    && CMP(".strtab") != 0 && CMP(".symtab") != 0 &&
	    obj.shdr[i].sh_type != SHT_REL && obj.shdr[i].sh_type != SHT_RELA
	    && obj.shdr[i].sh_type != SHT_NULL);
  if (obj.elf->e_type == ET_DYN)
    return (obj.shdr[i].sh_size && CMP(".bss") != 0 && CMP(".shstrtab") != 0
	    && CMP(".strtab") != 0 && CMP(".symtab") != 0 &&
	    obj.shdr[i].sh_type != SHT_NULL);
  return (0);
}

int		print_format64(t_objdump_64 obj)
{
  int		tab[4];
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (i < obj.elf->e_shnum)
    {
      if ((size_t)&obj.strtab[NAME] + SIZE > (size_t)obj.data + obj.size)
	return (fprintf(stderr, "objdump: %s: File truncated\n", obj.file));
      if (get_good_section(obj, i))
	{
	  printf("\nContents of section %s:\n", &obj.strtab[NAME]);
	  size += print_body_section(obj.shdr, (char*)obj.data, i, tab);
	  while (size % 16 !=0)
	    {
	      printf(" ");
	      size++;
	    }
	}
      i++;
    }
  return (printf("\n"));
}

int		is_good_elf64(Elf64_Ehdr *elf)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0 || elf->e_ident[EI_MAG1] != ELFMAG1 ||
      elf->e_ident[EI_MAG2] != ELFMAG2 || elf->e_ident[EI_MAG3] != ELFMAG3 ||
      elf->e_type != ET_NONE || elf->e_ident[EI_VERSION] == EV_NONE
      || elf->e_ident[EI_DATA] == ELFDATANONE)
    return (-1);
  return (1);
}

void		format_64(char *file, unsigned int size, void *data)
{
  t_objdump_64	obj;

  obj.file = file;
  obj.size = size;
  obj.data = data;
  obj.elf = (Elf64_Ehdr*)data;
  if (is_good_elf64(obj.elf))
    {
      if (obj.elf->e_shoff +
	  obj.elf->e_shnum * obj.elf->e_shentsize <= (size_t)size)
	{
	  obj.shdr = (Elf64_Shdr*)(obj.data + obj.elf->e_shoff);
	  obj.strtab = (char*)(obj.data +
			       obj.shdr[obj.elf->e_shstrndx].sh_offset);
	  print_header64(obj);
	  print_format64(obj);
	}
      else
	fprintf(stderr, "objdump: %s: File truncated\n", obj.file);
    }
  else
    fprintf(stderr, "objdump: '%s': File format not recognized\n", obj.file);
}
