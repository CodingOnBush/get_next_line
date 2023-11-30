#include "get_next_line.h"

void	ft_freelst(t_node **lst)
{
	t_node	*temp;
	t_node	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp->str);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}