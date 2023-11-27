#include "get_next_line.h"

int	ft_get_len(t_node *lst)
{
	int		len;
	t_node	*l;

	if (!lst)
		return (0);
	len = 0;
	l = lst;
	while (l)
	{
		len += ft_strlen(l->str);
		l = l->next;
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