#include "get_next_line.h"

void	ft_update_lst(t_node **lst)
{
	t_node	*temp;
	char	*s;
	int		i;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		// printf("temp->str : %s\n", temp->str);
		if (ft_strchr(temp->str, '\n'))
		{
			s = ft_remove_before(temp->str, '\n');
			temp->str = s;
			*lst = temp;
			return ;
		}
		temp = temp->next;
	}
}

int	main(void)
{
	t_node	*lst;
	
	lst = NULL;
	ft_lstappend(&lst, "abcd", 4);
	ft_lstappend(&lst, "efgh", 4);
	ft_lstappend(&lst, "i\nkl", 4);
	ft_lstappend(&lst, "mnop", 4);
	ft_lstappend(&lst, "qrst", 4);
	ft_putlst(lst);
	ft_update_lst(&lst);
	ft_putlst(lst);
	return (0);
}