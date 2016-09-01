#include "push_swap.h"

void	rev_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "rra", mark->tab_op);
	else
		add_op(mark->op_lst, "rrb", mark->tab_op);
	rev_rotate(lst);
}

void	r_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "ra", mark->tab_op);
	else
		add_op(mark->op_lst, "rb", mark->tab_op);
	rotate(lst);
}

void	s_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "sa", mark->tab_op);
	else
		add_op(mark->op_lst, "sb", mark->tab_op);
	swap(lst);
}
