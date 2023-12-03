#include "get_next_line.h"

void	ft_lstappend(t_node **lst, char *buff)
{
    t_node *newNode;
    t_node *current;

    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
        return ;
    newNode->str = buff;
    newNode->next = NULL;
    if (*lst == NULL)
    {
        *lst = newNode;
        return ;
    }
    current = *lst;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

// int	main(void)
// {
// 	t_node	*lst;
// 	char	*buff;

// 	lst = NULL;
// 	ft_putlst(lst);
// 	buff = "salut";
// 	ft_lstappend(&lst, buff, 6);
// 	ft_putlst(lst);
// 	buff = "ca va";
// 	ft_lstappend(&lst, buff, 6);
// 	buff = "salut";
// 	ft_lstappend(&lst, buff, 6);
// 	ft_putlst(lst);
// 	return (0);
// }