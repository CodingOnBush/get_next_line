#include "get_next_line.h"

void	ft_update_lst(t_node **lst)
{
	t_node	*temp;
	char	*s;
	// int		i;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		if (ft_strchr(temp->str, '\n'))
		{
			// ft_putstr("temp->str = ");
			// ft_putstr(temp->str);
			// printf("\n");
			s = ft_remove_before(temp->str, '\n');
			if (!s)
				return ;
			// ft_putstr("s = ");
			// ft_putstr(s);
			// printf("\n");
			if (*s != '\0')
			{
				temp->str = s;
				*lst = temp;
				return ;
			}
		}
		temp = temp->next;
	}
	*lst = temp;
}

// int	main(void)
// {
// 	t_node	*lst;

// 	lst = NULL;
// 	ft_lstappend(&lst, "a\n", 4);
// 	ft_lstappend(&lst, "\n\n", 4);
// 	ft_lstappend(&lst, "a", 4);
// 	ft_putlst(lst);
// 	ft_update_lst(&lst);
// 	ft_putlst(lst);
// 	ft_update_lst(&lst);
// 	ft_putlst(lst);
// 	ft_update_lst(&lst);
// 	ft_putlst(lst);
// 	return (0);
// }