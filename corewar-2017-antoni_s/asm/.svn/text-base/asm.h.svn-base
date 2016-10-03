/*
** asm.h for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 15:35:04 2013 florian corradin
** Last update Sat Mar 30 16:15:56 2013 simon daguenet
*/

#ifndef ASM_H
# define ASM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"

# define	M		mnemonique
# define	ARG		&file[col][arg][ctr_arg]
# define	SIZE_MAX	(40)
# define	SIZE_READ	(16)

typedef struct s_list
{
  int			x1;
  struct s_list		*next;
}			t_list;

	/* add.c */
char	**add(char **bin, t_list **list, int col, char ***file);

	/* aff.c */
char	**aff(char **bin, t_list **list, int col, char ***file);

	/* and.c */
char	**and(char **bin, t_list **list, int col, char ***file);
char	**off_and(char **bin, t_list **list, int col, char ***file);

	/* array.c */
char	*my_stradd(char *strt, char *end);
char	*my_get_word(char *buf, int *pos);
int	my_is_word(char *buf, int i);
int	my_count_word(char *buf);
char	**my_str_to_wordtab(char *buf);

	/* check_error_sec.c */
int	check_sti_arg(char *arg, int line);
int	check_and_arg(char *arg, int line);
int	check_or_arg(char *arg, int line);
int	check_xor_arg(char *arg, int line);
int	check_st_arg(char *arg, int line);

	/* check_file_header.c */
int	check_header(char *file, int line);
int	check_lbl(char *l_file, int line);
int	which_check2(char *mnemo, char *arg, int line);
int	which_check(char *mnemo, char *arg, int line);

	/* ckeck_error_cmd.c */
int	check_live_arg(char *arg, int line);
int	check_ld_arg(char *arg, int line);
int	check_add_arg(char *arg, int line);
int	check_zjmp_arg(char *arg, int line);
int	check_sub_arg(char *arg, int line);

	/* fct_pars.c */
char	*mal_tab();
char	**init_bin(int size);
int	my_put_in_list(t_list **list);
t_list	*my_params_in_list(int size);

	/* find_offset.c */
int	offset_up(int pos, int col, char **bin);
int	get_offset_value2(int pos, char **bin, int col);
int	get_offset_value4(int pos, char **bin, int col);
char	*get_the_off2(char *line, char **bin, char ***file, int col);
char	*get_the_off4(char *line, char **bin, char ***file, int col);

	/* fork.c */
char	**fork_fun(char **bin, t_list **list, int col, char ***file);
char	**off_fork(char **bin, t_list **list, int col, char ***file);

	/* get_champion.c */
int	get_line(char *av);
char	***get_file(char *name);
void	put_word_tab(char **tab);
void	put_file_tab(char ***tab);

	/* get_ind_good_arg.c */
char	*get_ind_init2(t_list **list, int *ctr, int *ctr_arg, char *line);
char	*get_ind_init4(t_list **list, int *ctr, int *ctr_arg, char *line);
char	*get_arg_3_2(char *arg, int *ctr, int *ctr_arg);
char	*get_arg_3_4(char *arg, int *ctr, int *ctr_arg);

	/* get_instruction.c */
int	check_mnemo(char *mnemo);
int	check_mnemo_len(char *mnemo);
char	**my_strdup_tab(char **tab);
char	***my_clean_file(char ***file);
int	is_only_mnemo(char *str);

	/* get_line.c */
int	get_the_next_arg(char *arg);
char	*get_lbl(char *line);
int	get_the_lbl_line(char *ind, char ***file, char *bin);
int	offset_down2(int pos, int col, char **bin);
long	offset_down4(int pos, int col, char **bin);

	/* get_max.c */
void	my_put_exit(char *str);
int	my_max(int a, int b);
int	my_max3(int a, int b, int c);

	/* get_parmacode.c */
char	*get_octet_codage2(char *line, char *bin, int a, int i);
char	*get_octet_codage(char *line);
char	*get_bin_char(char *bin, int a, int cas);

	/* get_str.c */
int	is_number(char *str);
int	get_where_are_the_arg(char *line);
char	*get_reg(char *arg);

	/* get_wich_off.c */
char	**wich_inst2(char **bin, t_list **list, int col, char ***file);
char	**wich_inst(char **bin, t_list **list, int col, char ***file);
char	**wich_inst_off(char **bin, t_list **list, int col, char ***file);
char	**wich_inst_off2(char **bin, t_list **list, int col, char ***file);

	/* header.c */
char	*my_strcpy_bin(char *dest, char *src, int taille);
void	get_com_and_name(char **com, char **name, char ***file);
void	init_val(header_t *val);
header_t	get_header(char ***file, char **bin);

	/* header_comment.c */
char	*my_strcpy_comment(char *dest, char *src, int taille);
void	get_val_prog_size(header_t *val, char **bin);
int	get_size_bin(char **bin);
void	get_header_comment(header_t *val, char *comment);
char	*my_get_comment(char *comment);

	/* header_name.c */
char	*my_strcpy_exec_magic(char *dest, char *src);
char	*my_strcpy_name(char *dest, char *src, int taille);
void	get_header_name(header_t *val, char *name);
int	get_len_tab(char **name);
char	*cut_cut(char **name);

	/* ldi.c */
char	**ldi(char **bin, t_list **list, int col, char ***file);
char	**off_ldi(char **bin, t_list **list, int col, char ***file);

	/* lfork.c */
char	**lfork(char **bin, t_list **list, int col, char ***file);
char	**off_lfork(char **bin, t_list **list, int col, char ***file);

	/* live.c */
char	**live(char **bin, t_list **list, int col, char ***file);
char	**off_live(char **bin, t_list **list, int col, char ***file);

	/* lld.c */
char	**lld(char **bin, t_list **list, int col, char ***file);
char	**off_lld(char **bin, t_list **list, int col, char ***file);

	/* lldi.c */
char	**lldi(char **bin, t_list **list, int col, char ***file);
char	**off_lldi(char **bin, t_list **list, int col, char ***file);

	/* make_bin.c */
char	**get_asm_bin(t_list *stock, int size, char **bin, char ***file);
void	make_bin_line(int fd, char *str, int size);
void	make_bin_head(header_t head, char *name);
void	make_bin(char **bin, char *name);

	/* manage_error1.c */
int	check_aff_arg(char *arg, int line);
int	check_lfork_arg(char *arg, int line);
int	check_lldi_arg(char *arg, int line);

	/* manage_error.c */
int	check_ldi_arg(char *arg, int line);
int	check_lld_arg(char *arg, int line);
int	check_fork_arg(char *arg, int line);

	/* management_error.c */
int	is_label(char *line);
int	is_header(char  *line);
void	my_put_error(char *msg1, char *msg2, int line, int mode);
char	*get_mnemo(char *file);
int	manag_eror(int line, char *av);

	/* my_nbr_str_int.c */
char	*my_eror(int nb, int *ctr, char *ret);
char	*my_nbr_str(int nb);
char	*my_erorl(int nb, int *ctr, char *ret);
char	*my_nbr_strl(long nb);

	/* my_nbr_str_sho.c */
char	*my_eror1(short nb, int *ctr, char *ret);
char	*my_nbr_str_sho(short nb);

	/* my_nbr_str_u_int.c */
char	*my_eror2(unsigned int nb, int *ctr, char *ret);
char	*my_nbr_str_u_int(unsigned int nb);

	/* my_nbr_str_u_sho.c */
char	*my_eror3(unsigned short nb, int *ctr, char *ret);
char	*my_nbr_str_u_sho(unsigned short nb);

	/* my_strcmp.c */
int	my_strcmp(char *str1, char *str2);
int	my_strncmp(char *str1, char *str2, int n);

	/* or.c */
char	**or(char **bin, t_list **list, int col, char ***file);
char	**off_or(char **bin, t_list **list, int col, char ***file);

	/* other_check_begin.c */
int	my_null(int *i, int *i1, int *i2);
int	error_open(int fd, char *file);
int	check_arguments(char *file, int line);
int	check_assemb(char *file, int line);
int	my_check_the_file(char **file);

	/* parser.c */
char	*get_octet_value(char *bin);
char	*get_good_name(char *name);
void	my_asm(char *name, int size, char ***file);

	/* recup.c */
char	*my_clean2(char *ret);
char	*my_clean4(char *ret);
void	my_memset(char c, char **str);
char	*my_copy_str_to(char *dest, char *src, int pos);

	/* recup_nbr.c */
char	*recup_nbr2(char *str);
char	*recup_nbr4(char *str);
char	*recup_nbr4l(char *str);

	/* st.c */
char	**st( char **bin, t_list **list, int col, char ***file);

	/* sti.c */
char	**sti(char **bin, t_list **list, int col, char ***file);
char	**ld(char **bin, t_list **list, int col, char ***file);
char	**off_sti(char **bin, t_list **list, int col, char ***file);
char	**off_ld(char **bin, t_list **list, int col, char ***file);

	/* str_concat.c */
char	*my_strcats(char *strt, char *end);
char	*my_strcat_free_strt(char *strt, char *end);
char	*my_strcat_free_end(char *strt, char *end);
char	*my_strcat_free_all(char *strt, char *end);

	/* sub.c */
char	**sub(char **bin, t_list **list, int col, char ***file);

	/* tab.c */
int	my_len_bigtab(char ***tab);
void	my_free_tab(char **tab);
void	my_free_bigtab(char ***tab);

	/* type.c */
int	is_reg(char *str);
int	is_dir2(char *str);
int	is_dir(char *str);
int	is_ind(char *str);

	/* x_fct.c */
void	xfree(void *ptr);
void	*xmalloc(size_t taille);
void	xclose(int fd);

	/* xor.c */
char	**xor(char **bin, t_list **list, int col, char ***file);
char	**off_xor(char **bin, t_list **list, int col, char ***file);

	/* zjump.c */
char	**zjmp(char **bin, t_list **list, int col, char ***file);
char	**off_zjmp(char **bin, t_list **list, int col, char ***file);

/* ################################################################ */
/* ###								### */
/* ###			FONCTION DE LA LIB			### */
/* ###								### */
/* ################################################################ */
int	get_i_from_base(char c, char *base_from);
long	convert_base_from_to_10(char *nbr, char *base_from);
char	*convert_from_10_to_base(long long nbr, char *base_to);
char	*convert_base(char *nbr, char *base_from, char *base_to);
char	*my_epurstr(char *str);
char	*my_strdup(char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
int	my_buf(char *buffer, char *buffer_s, int ret);
char	*my_realloc(char *buffer, int size);
char	*get_next_line(const int fd);
void	check_malloc(void *ptr);
char	*my_check_neg2(char *str, char *neg);
int	digit_to_val(char c, char *base);
long long	my_getnbr_base(char *str, char *base);
char	*my_check_neg(char *str, char *neg);
int	my_getnbr(char *str);
long	my_power_rec(int nb, int power);
void	my_putchar(char c);
void	my_eror_nbr(int nb);
void	my_put_nbr(int nb);
void	my_putstr(char *str);
char	*my_revstr(char *str);
int	my_strlen(char *str);

#endif
