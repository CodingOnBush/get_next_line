#include "get_next_line.h"

void	ft_putlst(t_node *lst)
{
	ft_putstr("list : ");
	if (!lst)
	{
		ft_putstr("NULL\n");
		return ;
	}
	while (lst)
	{
		ft_putstr(lst->str);
		ft_putstr("-->");
		lst = lst->next;
	}
	ft_putstr("NULL\n");
}