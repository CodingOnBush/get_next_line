#include "get_next_line.h"

t_elem	*ft_lstnew(char *buff, int size)
{
	t_elem	*new;
	char	*s;

	new = (t_elem *)malloc(sizeof(t_elem));
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