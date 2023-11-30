#include "get_next_line.h"

t_node	*ft_lstnew(char *buff, int size)
{
	t_node	*new;
	char	*s;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	s = ft_strdup(buff, size);
	if (!s)
	{
		free(new);
		return (NULL);
	}
	new->str = s;
	new->next = NULL;
	// free(buff);
	return (new);
}

// int	main(void)
// {
// 	char	*buff = "Hello World!";
// 	t_elem	*new = ft_lstnew(buff, 5);
// 	printf("new->str  : %s\n", new->str);
// 	printf("new->next : %s\n", (char *)new->next);
// 	return (0);
// }