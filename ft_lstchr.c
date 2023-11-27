#include "get_next_line.h"

int	ft_lstchr(t_elem *lst, int c)
{
	t_elem	*l;
	int		i;

	if (!lst)
		return (0);
	l = lst;
	while (l)
	{
		i = 0;
		while (l->str[i])
		{
			if (l->str[i] == c)
				return (1);
			i++;
		}
		l = l->next;
	}
	return (0);
}