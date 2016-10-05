/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:45:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:06:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "checker.h"

# define N 0
# define S 1
# define R 2
# define REV 3

typedef struct	s_sort
{
	int			high;
	int			low;
	int			r_high;
	int			r_low;
	int			rot;
}				t_sort;

typedef struct	s_pile
{
	int			val;
}				t_pile;

typedef struct	s_op
{
	char		*op;
}				t_op;

typedef struct	s_mark
{
	char		**tab_op;
	t_list		**op_lst;
	int			asc;
}				t_mark;

typedef struct	s_lstmed
{
	t_list		*tmp_1;
	t_list		*tmp_2;
	int			nu_med;
	int			i;
	int			j;
	int			k;
}				t_lstmed;

typedef struct	s_hint
{
	t_list		**lst_a;
	t_list		**lst_b;
	t_mark		*mark;
	t_list		*lst_data;
	t_list		*lst_conf;
	t_list		*lst_lim;
}				t_hint;

typedef struct	s_range
{
	int			one;
	int			two;
	int			three;
	int			four;
}				t_range;

typedef struct	s_seek
{
	t_list		*tmp_1;
	t_list		*tmp_2;
	int			len;
	int			i;
	int			j;
}				t_seek;

typedef	struct	s_main
{
	t_list		*lst_a;
	t_list		*lst_b;
	char		**tab_op;
	t_list		*op;
}				t_main;

typedef struct	s_darg
{
	char		**av_cpy;
	int			*tab;
	t_list		*lst;
	int			nb_arg;
	int			nb_opt;
}				t_darg;

t_list			*lst_tab2d(int ac, char **av);
void			print_lst(t_list *lst);
void			swap(t_list **lst);
void			push(t_list **lst_a, t_list **lst_b);
void			rotate(t_list **lst);
void			rev_rotate(t_list **lst);
int				lst_average(t_list *lst);
int				lst_average_rest(t_list *lst);
int				lst_median(t_list *lst);
int				lstmed_range(t_list *lst, int range);
int				check_asc(t_list *lst);
int				check_asc_rot(t_list *lst);
int				uni_sort(t_list *lst_a, t_list *lst_b);
void			del_content(void *content, size_t content_size);
int				check_prev(t_list *lst);
int				check_next(t_list *lst);
int				get_highest(t_list *lst);
int				get_lowest(t_list *lst);
int				turn_list(t_list **lst, t_mark *mark);
int				check_prevnext(t_list *lst);
int				asc_sort(t_list **lst);
int				where_is(t_list *lst, int num);
void			end_push(t_list **lst_a, t_list **lst_b);
void			main_sort(t_list **lst_a, t_list **lst_b);
void			del_content(void *content, size_t size);
int				quick_sort(t_list **lst_a, t_list **lst_b, t_mark *mark);
void			lst_trans(t_list **lst, int range);
int				get_next(t_list *lst);
int				get_prev(t_list *lst);
int				get_higher(t_list *lst, int val);
int				get_lower(t_list *lst, int val);
int				count_low(t_list *lst, int val);
int				count_high(t_list *lst, int val);
void			add_op(t_list **op_lst, char *op, char **tab_op);
char			**init_op(void);
void			print_tab_op(char **tab_op);
void			free_init(char **tab_op);
void			print_op(t_list *lst_op);
void			check_op(t_list **op);
void			rev_local(t_list **lst, t_mark *mark);
void			r_local(t_list **lst, t_mark *mark);
void			s_local(t_list **lst, t_mark *mark);
void			p_local(t_list **lst_a, t_list **lst_b, t_mark *mark);
void			elem_sort(t_list **lst, t_mark *mark, int range);
int				check_asc_len(t_list *lst, int len);
int				check_half_sort(t_list *lst, int len);
t_list			*get_lstlen(int len);
int				check_lstlen(t_list *lst, int div);
void			len_sort(t_list **lst, t_mark *mark, int len);
void			cpy_link(t_list *lst);
t_tree			*get_trlen(int len, int div);
void			print_tr(t_tree *tr);
void			get_lstconf(t_tree *tr, t_list **lst);
int				get_lstval(t_list *lst, int range);
t_list			*get_lstlim(t_list *lst_conf);
t_list			*get_lstdata(t_list *lst, int pow);
t_list			*make_lstdata(t_list *lst, int itr);
void			sort_it(t_list **lst);
void			ulti_sort(t_list **lst_a, t_list **lst_b, t_mark *mark);
int				get_first(t_list *lst);
int				get_last(t_list *lst);
void			deal_hint(t_hint hint);
t_list			*calc_lstconf(t_list *lst_data, t_list *lst_a);
int				check_rothint(t_hint *hint, t_range rg);
void			sort_push(t_hint hint, t_list *lst_conf);
void			deal_sort(t_hint hint, t_list *cpy_s);
int				seek_way(t_list *lst, int var);
void			sort_hint(t_hint *hint, int *i, int j);
void			sort_hint_2(t_hint *hint, int *i);
void			init_rangval(t_range *r_val, t_list *lst_data, int j);
void			bzero_rangval(t_range *r_val);
int				count_below(t_list *lst, int val);
int				count_above(t_list *lst, int val);
int				count_btw(t_list *lst, int one, int two);

#endif
