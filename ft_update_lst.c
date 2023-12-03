#include "get_next_line.h"

void	ft_update_lst(t_node **lst)
{
	t_node	*current;
	char	*new;

	// ft_putlst(*lst);
    if (*lst == NULL)
		return ;
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	// ft_putstr("current->str : ");
	// ft_putstr(current->str);
	// ft_putchar('\n');
	new = ft_get_after_nl(current->str);
	if (new == NULL)
	{
		ft_freelst(lst);
		*lst = NULL;
		return ;
	}
	// ft_putstr("new : ");
	// ft_putstr(new);
	// ft_putchar('\n');
	// printf("YO\n");
	ft_freelst(lst);
	ft_lstappend(lst, new);
	// ft_putlst(*lst);
}
// int	main(void)
// {
//     t_node *lst = NULL;
// 	char *str1;
// 	char *str2;

// 	str1 = ft_strdup("abc", 3);
// 	str2 = ft_strdup("de\n", 3);
// 	ft_lstappend(&lst, str1);
// 	ft_lstappend(&lst, str2);

//     // ft_putstr("List before update:");
// 	// ft_putchar('\n');
//     // ft_putlst(lst);

//     ft_update_lst(&lst);
	
// 	// ft_putchar('\n');
// 	// ft_putstr("List after first update:");
// 	// ft_putchar('\n');
//     ft_putlst(lst);

// 	// ft_putstr("lst->str : ");
// 	// ft_putstr(lst->str);
// 	// ft_putchar('\n');

// 	// if (lst == NULL)
// 	// 	printf("NULL\n");
// 	// else
// 	// 	printf("NOT NULL\n");

//     // ft_update_lst(&lst);
//     // printf("\nList after second update:\n");
//     // ft_putlst(lst);

//     // ft_update_lst(&lst);
//     // printf("\nList after third update:\n");
//     // ft_putlst(lst);

//     return 0;
// }