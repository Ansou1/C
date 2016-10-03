/*
** allum1.h for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:40:17 2013 simon daguenet
** Last update Mon Feb 11 09:40:12 2013 simon daguenet
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>

typedef struct		s_element
{
  int			nbr;
  struct s_element	*next;
}			t_list;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_put_nbr(int nb);
void	my_put_error(int i);
void	my_put_error_term(int i);
int	my_getnbr(char *str);
void	my_put_in_list(t_list **list);
t_list	*my_params_in_list(int nbr);
void	aff_match(int nb_match, int nbr);
void	aff_list(t_list *list, int nbr);
int	my_rev_list(t_list **begin);
void	free_list(t_list *list);
int	get_player();
int	get_line_possible(t_list *list, int line_nbr);
int	get_line_player(t_list *list, int nbr_line);
int	get_match_possible(t_list *list, int matches_nbr, int line);
int	get_matches_player(t_list *list , int line_nbr);
int	delete_match(t_list *list, int line, int matches, int all);
int	get_all_match(t_list *list);
void	round_player(t_list *list, int i, int nbr_line);
int	nbr_line_in_list_current(t_list *list);
int	nbr_max_in_list(t_list *list);
void	check_end(int check_match);
int	get_victory(t_list *list);
int	vic_pair(t_list *list);
int	get_min_in_list(t_list *list);
int	get_max_in_list(t_list *list);
int	creat_pair(t_list *list, int val);
int	win_pair(t_list *list);
int	lose_with_pair(t_list *list);
int	check_is_number_one(t_list *list);
int	get_victory_pair(t_list *list, int check_match);
int	lose_ia(t_list *list);
int	take_one_in_max(t_list *list);
int	check_two_one(t_list *list);
int	check_is_pair(t_list *list);
int	take_the_diff_pair(t_list *list, int val);
int	put_at_one(t_list *list);
int	get_diff_pair(t_list *list);
int	put_third_win(t_list *list);
int	get_victory_third(t_list *list, int check_match);
int	nbr_line_pair(t_list *list);
int	nbr_line_impair(t_list *list);
int	algo_ia(t_list *list, int check_match, int nbr_line);
void	round_ia(t_list *list, int i, int nbr_line);
void	gere_player(t_list *list, int player, int nbr_line);
char	*my_strdup_old(char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*get_term(char **my_env, char *command);
int	outc(int c);
void	my_clear_screen();
int	check_ac_av(int ac, char **av, char **env);
int	get_nbr_of_player();
int	delete_match_pp(t_list *list, int line, int matches);
void	round_player_pp(t_list *list, int nbr_line);
int	gere_player_vs_player(t_list *list, int nbr_line);
int	get_nbr_of_line();

#endif
