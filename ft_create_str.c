#include "get_next_line.h"

char	*ft_create_str(t_node *lst)
{
	t_node	*l;
	char	*out;
	int		len;
	
	len = ft_get_len(lst);
	if (len == 0)
		return (NULL);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	*out = '\0';
	while (lst != NULL && ft_strchr(lst->str, '\n') == NULL)
	{
		out = ft_strcat(out, lst->str);
		lst = lst->next;
	}
	if (lst != NULL && ft_strchr(lst->str, '\n') != NULL)
		out = ft_strcat(out, lst->str);
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
// 	lst = ft_lstnew("a\n\na\n\na", 1);
// 	// printf("lst->str : %s\n", lst->str);
// 	// buff = " World";
// 	// ft_lstappend(&lst, "\n", 6);
// 	// ft_putlst(lst);
// 	// ft_lstappend(&lst, "A", 2);
// 	// ft_putlst(lst);
// 	// ft_lstappend(&lst, " bonjourdasa\n", 25);
// 	ft_putlst(lst);
// 	str = ft_create_str(lst);
// 	printf("hello\n");
// 	if (*str == 0)
// 		return (0);
// 	// ft_putstr(str);
// 	printf("str[0] : %c\n", str[0]);
// 	printf("str[1] : %d\n", str[1]);
// 	printf("str[19] : %c\n", str[19]);
// 	printf("str[20] : %c\n", str[20]);
// 	printf("str[21] : %c\n", str[21]);
// 	printf("str[22] : %c\n", str[22]);
// 	printf("str[23] : %c\n", str[23]);
// 	printf("str[24] : %d\n", str[24]);
// 	printf("str[25] : %d\n", str[25]);
// 	printf("str[26] : %c\n", str[26]);
// 	printf("str[27] : %c\n", str[27]);
// 	printf("str[28] : %c\n", str[28]);
// 	printf("str[29] : %c\n", str[29]);
// 	printf("str[30] : %c\n", str[30]);
// 	printf("str[31] : %c\n", str[31]);
// 	return (0);
// }