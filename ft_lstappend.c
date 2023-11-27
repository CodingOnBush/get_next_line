#include "get_next_line.h"

void	ft_lstappend(t_node **lst, char *buff, int size)
{
	t_node	*new;

	new = ft_lstnew(buff, size);
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = new;
	}
}

// int	main(void)
// {
// 	t_node	*lst;
// 	char	*buff;

// 	lst = NULL;
// 	ft_putlst(lst);
// 	buff = "salut";
// 	ft_lstappend(&lst, buff, 6);
// 	ft_putlst(lst);
// 	buff = "ca va";
// 	ft_lstappend(&lst, buff, 6);
// 	ft_putlst(lst);
// 	return (0);
// }