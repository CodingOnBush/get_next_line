#include "get_next_line.h"

void	ft_putlst(t_node *lst)
{
	t_node	*current;

	ft_putstr("list : ");
	current = lst;
	while (current != NULL)
	{
		ft_putstr(current->str);
		ft_putstr("-->");
		current = current->next;
	}
	ft_putstr("NULL");
	ft_putchar('\n');
}