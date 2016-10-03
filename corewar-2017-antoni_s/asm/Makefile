##
## Makefile for corewar_asm in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sat Mar 16 16:39:34 2013 simon daguenet
## Last update Sat Mar 30 17:51:56 2013 simon daguenet
##

SRC_ASM=	add.c\
		aff.c\
		and.c\
		array.c\
		check_error_sec.c\
		check_file_header.c\
		ckeck_error_cmd.c\
		fct_pars.c\
		find_offset.c\
		fork.c\
		get_champion.c\
		get_ind_good_arg.c\
		get_instruction.c\
		get_line.c\
		get_max.c\
		get_parmacode.c\
		get_str.c\
		get_wich_off.c\
		header.c\
		header_comment.c\
		header_name.c\
		ldi.c\
		lfork.c\
		live.c\
		lld.c\
		lldi.c\
		make_bin.c\
		manage_error1.c\
		manage_error.c\
		management_error.c\
		my_nbr_str_int.c\
		my_nbr_str_sho.c\
		my_nbr_str_u_int.c\
		my_nbr_str_u_sho.c\
		my_strcmp.c\
		op.c\
		or.c\
		other_check_begin.c\
		parser.c\
		recup.c\
		recup_nbr.c\
		st.c\
		sti.c\
		str_concat.c\
		sub.c\
		tab.c\
		type.c\
		x_fct.c\
		xor.c\
		zjmp.c\
		convert_base.c\
		epur_str.c\
		fonction.c\
		get_next_line.c\
		my_eror.c\
		my_getnbr_base.c\
		my_getnbr.c\
		my_power_rec.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_strlen.c

OBJ=		$(SRC_ASM:.c=.o)

CC=		cc

NAME=		asm

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ -o $@

gdb:
	$(CC) $(SRC_ASM) -g3

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all