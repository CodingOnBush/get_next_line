#include "get_next_line.h"

int	ft_lstchr(t_node *lst)
{
    t_node *current;

	current = lst;
    while (current)
	{
        char *str = current->str;
        while (*str)
		{
            if (*str == '\n')
                return 1;
            str++;
        }
        current = current->next;
    }
    return (0);
}
// int	main(void)
// {
//     t_node *lst = NULL;
// 	char *str1;
// 	char *str2;

// 	str1 = ft_strdup("/nbc", 3);
// 	str2 = ft_strdup("def", 3);
// 	ft_lstappend(&lst, str1);
// 	ft_lstappend(&lst, str2);

//     ft_putlst(lst);

//     if (ft_lstchr(lst, '\n') == 1)
// 		printf("There is a newline in the list\n");
// 	else
// 		printf("There is no newline in the list\n");

//     return (0);
// }