/*
** nm.c for  in /home/daguen_s/rendu/nm-objdump/src_nm
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Mar 16 16:51:53 2014 daguen_s
** Last update Sun Mar 16 19:58:49 2014 daguen_s
*/

#include "nm.h"

int		get_the_tables_symbol(t_nm *obj)
{
  int		i;

  obj->my_strtab = NULL;
  obj->my_symtab = NULL;
  i = 0;
  while (i < obj->elf->e_shnum)
    {
      if ((size_t)&(obj->strtab[obj->shdr[i].sh_name]) +
	  sizeof(obj->shdr[i].sh_name) > (size_t)obj->data + obj->size)
	return (0);
      if (obj->shdr[i].sh_size)
	{
	  if (strcmp(&(obj->strtab[obj->shdr[i].sh_name]), ".symtab") == 0)
	    obj->my_symtab = (Elf64_Shdr*)&(obj->shdr[i]);
	  if (strcmp(&(obj->strtab[obj->shdr[i].sh_name]), ".strtab") == 0)
	    obj->my_strtab = (Elf64_Shdr*)&(obj->shdr[i]);
	}
      i++;
    }
  return ((obj->my_strtab != NULL && obj->my_symtab != NULL) ? (1) : (0));
}

char		get_the_symbol(t_nm obj, Elf64_Sym *symtab, int i)
{
  if (ELF64_ST_BIND(symtab[i].st_info) == STB_GLOBAL)
    {
      if (ELF64_ST_BIND(symtab[i].st_info) == STB_WEAK)
	return ('W');
      if (ELF64_ST_TYPE(symtab[i].st_info) == STT_FUNC)
	return ((obj.shdr[symtab[i].st_shndx].sh_type == SHT_PROGBITS)
		? 'T' : 'U');
      else
	return ('G');
    }
  else
    {
      if (ELF64_ST_BIND(symtab[i].st_info) == STB_WEAK)
	return ('w');
      if (ELF64_ST_TYPE(symtab[i].st_info) == STT_FUNC)
	if (obj.shdr[symtab[i].st_shndx].sh_type == SHT_PROGBITS)
	  return ('t');
      if (ELF64_ST_TYPE(symtab[i].st_info) == STT_OBJECT)
	if (obj.shdr[symtab[i].st_shndx].sh_type == SHT_PROGBITS)
	  return ('d');
	else
	  return ('g');
    }
  return ('?');
}

void		print_the_nm(t_nm obj)
{
  Elf64_Sym	*symtab;
  char		*tab_of_string;
  int		i;
  char		symbol;

  i = -1;
  symtab = (Elf64_Sym*)((char*)obj.data + obj.my_symtab->sh_offset);
  tab_of_string = (char*)((char*)obj.data + obj.my_strtab->sh_offset);
  while (++i < SIZE)
    {
      if (symtab[i].st_name != 1 && symtab[i].st_info != STT_SECTION)
	{
	  symbol = get_the_symbol(obj, symtab, i);
	  if (symbol != 'w' && symbol != 'U')
	    printf("%08x%08x ", (uint32_t)(symtab[i].st_value >> 32),
		   (uint32_t)symtab[i].st_value);
	  else
	    printf("                 ");
	  printf("%c %s\n", symbol, &tab_of_string[symtab[i].st_name]);
	}
    }
}

void		format_64(char *file, unsigned int size, void *data)
{
  t_nm		obj;

  obj.file = file;
  obj.size = size;
  obj.data = data;
  obj.elf = (Elf64_Ehdr*)data;
  if (is_good_elf(obj.elf))
    {
      if (obj.elf->e_shoff + obj.elf->e_shnum * obj.elf->e_shentsize
	  <= (size_t)size)
	{
	  obj.shdr = (Elf64_Shdr*)(data + obj.elf->e_shoff);
	  obj.strtab = (char*)(data + obj.shdr[obj.elf->e_shstrndx].sh_offset);
	  if (get_the_tables_symbol(&obj))
	    print_the_nm(obj);
	  else
	    fprintf(stderr, "nm: '%s': File is truncated\n", file);
	}
      else
	fprintf(stderr, "nm: '%s': File is truncated\n", file);
    }
  else
    fprintf(stderr, "nm: '%s': No such file\n", file);
}
