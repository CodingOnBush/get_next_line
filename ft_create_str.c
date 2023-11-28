#include "get_next_line.h"

char	*ft_create_str(t_node *lst)
{
	t_node	*l;
	char	*out;
	int		len;
	
	if (!lst)
		return (NULL);
	len = ft_get_len(lst);
	if (len == 0)
		return (NULL);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	*out = '\0';
	while (lst)
	{
		out = ft_strcat(out, lst->str);
		lst = lst->next;
	}
	return (out);
}

// int	main(void)
// {
// 	t_node	*lst;
// 	char	*str;
// 	// char	*buff;

// 	// buff = malloc(10 * sizeof(char));
// 	// if (!buff)
// 		// return (0);
// 	// buff = "Hello";
// 	lst = ft_lstnew("Hello", 5);
// 	// buff = " World";
// 	ft_lstappend(&lst, " World", 6);
// 	ft_putlst(lst);
// 	ft_lstappend(&lst, "A", 2);
// 	ft_putlst(lst);
// 	ft_lstappend(&lst, "B", 2);
// 	ft_putlst(lst);
// 	str = ft_create_str(lst);
// 	ft_putstr(str);
// 	return (0);
// }