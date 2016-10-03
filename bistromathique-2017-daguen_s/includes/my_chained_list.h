/*
** ch_list.h for listes chainées in /home/elegbe_m//programmation/tests_chained_lists
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 23 13:35:01 2012 martial elegbede
** Last update Sat Nov 10 16:51:38 2012 martial elegbede
*/

#ifndef MY_CHAINED_LIST_H_
#define MY_CHAINED_LIST_H_

#define STRLIST (0)
#define NBRLIST (1)
#define N next

typedef	struct	s_list
{
  int	content;
  char	*nbr;
  char	str;
  int	op_prio;
  struct s_list	*next;
} t_list;

typedef	struct	s_stack
{
  char	op;
  int	op_prio;
  struct s_stack	*next;
} t_stack;

int	my_put_nb_in_list(t_list **list, char *nbr);
int	my_put_str_in_list(t_list **list, char str);
int	my_put_in_stack(t_stack **stack, t_list *list);
int	my_delete_garbage_list(t_list **list);
void	delete_list(t_list **list);
void	delete_stack(t_stack **list);
void	my_show_list(t_list *list);
void	my_show_stack(t_stack *list);
t_list	*str_to_list(char *str, char *base);
void	my_rev_list(t_list **begin);
void	assign_prio(t_list *list);

#endif
