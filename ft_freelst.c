#include "get_next_line.h"

void	ft_freelst(t_node **lst)
{
	t_node	*current;
	t_node *next;

	if (*lst == NULL)
        return;
    current = *lst;
    while (current != NULL)
	{
        next = current->next;
        free(current->str);
		free(current);
        current = next;
    }
    *lst = NULL;
}