/*
** corewar.h for corewar in /home/efilon/corewar-2017-antoni_s/corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Sun Mar 17 20:02:01 2013 sebastien antonico
** Last update Sun Mar 31 19:01:03 2013 sebastien antonico
*/

#ifndef FILE_H_
# define FILE_H_

#include "op.h"

#define	BOOL		char
#define	TRUE		1
#define	FALSE		0
#define	LAST_PROC	-1
#define	NO_DUMP		-1
#define	NO_ADRESSES	-1
#define	CTODIE		0
#define	CYCL		1
#define	TOTALC		2
#define	LIVEC		3
#define	C_OCT1		p->c_oct.type1
#define	C_OCT2		p->c_oct.type2
#define	C_OCT3		p->c_oct.type3
#define	USAGE		"Usage : ./corewar [-dump nbr] file...\n"
#define	READ_ON_VM(x)	cw->vm + ((p->pc - cw->vm + (x)) % MEM_SIZE)

typedef struct	s_coding_oct
{
  char		type1;
  char		type3;
  char		type2;
}		t_coding_oct;

typedef struct		s_proc
{
  t_coding_oct		c_oct;
  unsigned char		regs[REG_NUMBER][REG_SIZE];
  char			carry;
  unsigned char		*pc;
  int			nbr_cycle;
  struct s_proc		*next;
  BOOL			bool_live;
  int			tmp_val;
  int			tmp_num_reg;
  unsigned char		*tmp_pc;
  char			type_instr;
  int			num_player;
}			t_proc;

typedef struct	s_champ
{
  unsigned char	*binary;
  header_t	header;
  int		size;
  BOOL		alive;
  BOOL		exist;
}		t_champ;

typedef struct		s_cw
{
  t_proc		*list_proc;
  t_champ		champs[4];
  int			nb_champs;
  unsigned char		*vm;
  int			dump;
  int			addresses[4];
  void			(*ptr_read[16])(struct s_cw *, t_proc *);
  void			(*ptr_exec[16])(struct s_cw *, t_proc *);
}			t_cw;

/* check_live.c */
int             check_procs_alive(t_cw *cw);
int             check_champs(t_cw *cw);
int             nb_champs_alive(t_cw *cw);
int             check_win(t_cw *cw);
void            reinit_live_proc(t_cw *cw);

/* corewar.c */
void            exit_cw(t_cw *cw);
void    init_first_proc(t_cw *cw);
void            place_champs(t_cw *cw);
void    memdump(t_cw *cw);
int     corewar(t_cw *cw);

/* cycles.c */
int     get_nb_cycle(t_proc *p);
int     read_proc(t_cw *cw, t_proc *p);
int     exec_proc(t_cw *cw, t_proc *p);
void            do_cycle(t_cw *cw);

/* fight.c */
int     is_valid_nb(int nb, int min, int max);
int     is_valid_opcode(t_proc *p);
int             fight(t_cw *cw);

/* get_file.c */
int     inv_nb(unsigned int nb);
t_champ         get_binary(char *name);

/* proc.c */
t_proc  *get_proc(t_proc *first, int id);
void    init_regs(t_proc *p, t_proc *from, int num_player);
void    add_proc(t_proc *p, int num_player, unsigned char *pc, t_proc *from);
void    rm_proc(t_proc **procs, int id);
int             size_procs(t_proc *procs);

/* reg.c */
int     tab_to_int(unsigned char *tab, int regsize);
void    write_int(unsigned char *r, int regsize, int v);

/* misc.c */
void    fill_coding_oct(t_proc *p);
int     total_size(t_cw *cw);
void    fill_pfunc_read(t_cw *cw);
void    fill_pfunc_exec(t_cw *cw);
int     check_defines();

/* instructions */
void	read_live(t_cw *cw, t_proc *p);
void	exec_live(t_cw *cw, t_proc *p);
void	read_ld(t_cw *cw, t_proc *p);
void	exec_ld(t_cw *cw, t_proc *p);
void	read_st(t_cw *cw, t_proc *p);
void	exec_st(t_cw *cw, t_proc *p);
void	read_add(t_cw *cw, t_proc *p);
void	exec_add(t_cw *cw, t_proc *p);
void	read_sub(t_cw *cw, t_proc *p);
void	exec_sub(t_cw *cw, t_proc *p);
void	read_and(t_cw *cw, t_proc *p);
void	exec_and_or_xor(t_cw *cw, t_proc *p);
void	read_or(t_cw *cw, t_proc *p);
void	read_xor(t_cw *cw, t_proc *p);
void	read_zjmp(t_cw *cw, t_proc *p);
void	exec_zjmp(t_cw *cw, t_proc *p);
void	read_sti(t_cw *cw, t_proc *p);
void	exec_sti(t_cw *cw, t_proc *p);
void	read_ldi(t_cw *cw, t_proc *p);
void	exec_ldi(t_cw *cw, t_proc *p);
void	read_fork(t_cw *cw, t_proc *p);
void	exec_fork(t_cw *cw, t_proc *p);
void	read_lfork(t_cw *cw, t_proc *p);
void	exec_lfork(t_cw *cw, t_proc *p);
void	read_lld(t_cw *cw, t_proc *p);
void	exec_lld(t_cw *cw, t_proc *p);
void	read_lldi(t_cw *cw, t_proc *p);
void	exec_lldi(t_cw *cw, t_proc *p);
void	read_aff(t_cw *cw, t_proc *p);
void	exec_aff(t_cw *cw, t_proc *p);

#endif /* !FILE_H_ */
