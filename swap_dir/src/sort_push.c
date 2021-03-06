#include "push_swap.h"

static t_list	*cpy_len(t_list *lst, int len)
{
	t_list	*cpy_sort;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(cpy_sort = ft_lstnew(lst->content, sizeof(t_pile))))
		return (NULL);
	lst = lst->next;
	while (lst && len-- > 1)
	{
		tmp = ft_lstnew(lst->content, sizeof(t_pile));
		ft_lstadd_back(cpy_sort, tmp);
		lst = lst->next;
	}
	return (cpy_sort);
}

static int	seek_way(t_list *lst, int var)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_1 = NULL;
	tmp_2 = NULL;
	if (!(tmp_1 = ft_lstcpy(lst, sizeof(t_pile)))
		|| !(tmp_2 = ft_lstcpy(lst, sizeof(t_pile))))
	{
		ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
		ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
		return (0);
	}
	len = ft_lstcount(lst);
	while (i < len)
	{
		if (((t_pile*)(tmp_1->content))->val == var)
			break;
		rotate(&tmp_1);
		i++;
	}
	while (j < len)
	{
		if (((t_pile*)(tmp_2->content))->val == var)
			break;
		rev_rotate(&tmp_2);
		j++;
	}
	ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
	if (i <= j)
		return (i);
	else
		return (-1 * j);
}

static void	deal_sort(t_hint hint, t_list *cpy_s)
{
	int		val;
	int		tmp;
	int		high;

	if (cpy_s->next)
		deal_sort(hint, cpy_s->next);
	val = ((t_pile*)((*(hint.lst_b))->content))->val;
	high = ((t_pile*)(cpy_s->content))->val;
	hint.mark->asc = 1;
	if (val == high)
		p_local(hint.lst_b, hint.lst_a, hint.mark);
	else if ((tmp = seek_way(*(hint.lst_b), high)) > 0)
	{
		hint.mark->asc = 0;
		while (tmp--)
			r_local(hint.lst_b, hint.mark);
		hint.mark->asc = 1;
		p_local(hint.lst_b, hint.lst_a, hint.mark);
	}
	else
	{
		hint.mark->asc = 0;
		while (tmp++)
			rev_local(hint.lst_b, hint.mark);
		hint.mark->asc = 1;
		p_local(hint.lst_b, hint.lst_a, hint.mark);
	}
	hint.mark->asc = 0;
}

void	sort_push(t_hint hint, t_list *lst_conf)
{
	int	len;
	t_list	*cpy_s;

	if (lst_conf->next)
		sort_push(hint, lst_conf->next);
	cpy_s = NULL;
	len = ((t_pile*)(lst_conf->content))->val;
	if (!(cpy_s = cpy_len(*(hint.lst_b), len)))
		return ;
	sort_it(&cpy_s);
	deal_sort(hint, cpy_s);
	ft_lstdel(&cpy_s, (void(*)(void*, size_t))del_content);
}
