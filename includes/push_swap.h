#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <ncurses.h>
# include <limits.h>
# include <stdbool.h>
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define RESET "\x1B[0m"

typedef struct		s_stack
{
	int 			value;
	int				index;
	int				group;
	bool			master;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

enum e_action
{
	PA, PB, RA, RB, RR, SA, SB, SS, RRA, RRB, RRR, START, INVALID
};

typedef struct		s_action
{
	struct s_action	*next;
	struct s_action	*prev;
	enum e_action	action;
}					t_action;

typedef struct		s_stacks 
{
	bool			is_checker;
	bool			visualise;
	t_action		*v_actions;
	t_stack 		**a;
	t_stack 		**b;
}					t_stacks;

typedef struct		s_moves
{
	t_stack			*elem;
	int				a_moves;
	int				b_moves;
	int				total;
}					t_moves;

typedef struct		s_vstate
{
	SCREEN			*screen;
	WINDOW			*rightw;
	WINDOW			*leftw;
	WINDOW			*middlew;
	bool			tty;
	bool			interactive;
	int				input;
}					t_vstate;

bool				args_are_digits(int argc, char **argv);
bool				args_fit_int(int argc, char **argv);
bool				ft_act(t_stacks **container, char *str);
bool				ft_appendelem(t_stack **stack, int value);
bool				ft_hasdupe(t_stack **stack);
bool				ft_single_sorted(t_stack *head);
bool				ft_sorted(t_stack **stack, t_stack **helper);
bool				input_sane(int argc, char **argv);
bool				checker_preflight(int argc, char **argv);
bool				pushswap_preflight(int argc, char **argv);
int					cleanup(t_stacks *container);
void				collect_actions(t_stacks *container);
int					get_min(t_stack **stack);
int					get_value_at_index(t_stack **stack, int index);
int					index_of(t_stack **stack, int number);
enum				e_action get_action(char *str);
int					len_from_start(t_stack *head, t_stack *item);
int					len_to_end(t_stack *head, t_stack *item);
int					max_index(t_stack *stack);
int					min_index(t_stack *stack);
int					stack_is_long(t_stack *stack);
int					stack_len(t_stack *stack);
int					visi(t_stacks *container);
int					visualize_stacks(t_stacks *container);
long				ft_atol(char *string);
t_action			*new_action(enum e_action action);
t_stack				*ft_newelem(int value);
t_stack				*ft_stackinit();
t_stack				*get_last_item(t_stack *stack);
t_stacks			*ft_containstacks(t_stack **a, t_stack **b, bool is_checker);
void				act_reverse(t_stacks **container, enum e_action action);
void				append_new_action(t_action **previous, enum e_action a);
void				collect_actions(t_stacks *container);
void				destroy_stack(t_stack *head);
void				ft_anotherway(t_stacks **container);
void				ft_push(t_stack **sender, t_stack **receiver);
void				ft_reverse(t_stack **stack);
void				ft_rotate(t_stack **stack);
void				ft_sort_below_five(t_stacks **container);
void				ft_sort_five(t_stacks **container);
void				ft_sort_three(t_stacks **container);
void				ft_sort_three_b(t_stacks **container);
void				ft_sort_two(t_stacks **container);
void				ft_swap(t_stack **stack);
void				gsort(t_stacks **container, t_moves **moves, int a_max);
void				normalise(t_stack *stacka, int count);
void				p_action(WINDOW *win, enum e_action action, int row);
void				pa(t_stacks **stacks);
void				pb(t_stacks **stacks);
void				print_actions_down(WINDOW *win, t_action *action, int pos);
void				print_actions_up(WINDOW *win, t_action *action, int pos);
void				push_back_to_a(t_stacks **container);
void				ra(t_stacks **stacks);
void				rb(t_stacks **stacks);
void				reverse_action(t_stacks **container, t_vstate *state);
void				rr(t_stacks **stacks);
void				rra(t_stacks **stacks);
void				rrb(t_stacks **stacks);
void				rrr(t_stacks **stacks);
void				sa(t_stacks **stacks);
void				sb(t_stacks **stacks);
void				ss(t_stacks **stacks);

#endif