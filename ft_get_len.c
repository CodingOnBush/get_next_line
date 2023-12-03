#include "get_next_line.h"

int	ft_get_len(t_node *lst)
{
	t_node	*curr;
	char	*str;
	int		len;

	curr = lst;
	len = 0;
	while (curr)
	{
		str = curr->str;
		while (*str != '\n' && *str)
		{
			len++;
			str++;
		}
		if (*str == '\n')
			return (len + 1);
		curr = curr->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_elem	*lst;
// 	char	*str;
// 	int		len;

// 	lst = ft_lstnew("H", 1);
// 	lst->next = ft_lstnew("W\n", 2);
// 	ft_putlst(lst);
// 	len = ft_get_len(lst);
// 	printf("len = %d\n", len);
// 	return (0);
// }