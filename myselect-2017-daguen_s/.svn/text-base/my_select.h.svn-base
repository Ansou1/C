/*
** my_select.h for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 21:10:42 2013 simon daguenet
** Last update Sat Jan 19 23:32:56 2013 simon daguenet
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <curses.h>
#include <term.h>

typedef struct	s_element
{
  int			u_s;
  int			m_r;
  int			x;
  char			*word;
  struct s_element	*next;
  struct s_element	*prev;
}			t_list;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_put_error(int i);
void	my_put_error_2(int i);
void	my_first_time(t_list **list, char *word, t_list *elem, int i);
void	my_other_time(t_list **list, char *word, t_list *elem, int i);
void	my_put_in_list(t_list **list, char *word, int i, int taille);
t_list	*my_params_in_list(int ac, char **av);
void	aff_list(t_list *list);
char	*my_strdup_old(char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*get_term(char **my_env, char *command);
int	outc(int c);
void	free_list(t_list **list);
void	init_t(struct termios *t);
int	keys(char *str);
int	print(t_list **tmp);
int	print_underline(char *s);
int	print_video(char *s);
int	print_und_vid(char *s);
int	underline(t_list **list);
int	video_mode(t_list **list);
int	move_up(t_list **list);
int	move_down(t_list **list);
int	press_space(t_list **list);
void	press_enter(t_list **list);
int	delete_elem(t_list **list, int *taille);
void	disp(t_list **list);
void	aff_list_with_bool(t_list *list);
void	check_size(int *taille);
int	press_delete(t_list **list, int *taille);
void	press_exit(t_list **list);
int	gere_command(t_list **list, int value_key, int *taille);
void	display_list(t_list *list);
void	get_sigint(int sig);
int	display_loop(t_list *list, int *taille);

#endif
