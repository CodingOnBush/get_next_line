#include "get_next_line.h"

char	*ft_create_str(t_node *lst)
{
	t_node	*current;
	char	*new;
	char	*str;
	int		len;
	
	len = ft_get_len(lst);
	if (len == 0)
		return (NULL);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	current = lst;
	while (current)
	{
		str = current->str;
		while (*str != '\n' && *str)
			*new++ = *str++;
		current = current->next;
	}
	if (*str == '\n')
		*new++ = *str++;
	*new = '\0';
	return (new - len);
}

// int	main(void)
// {
// 	t_node	*lst = NULL;
// 	char	*str;
// 	// char	*buff;

// 	// buff = malloc(10 * sizeof(char));
// 	// if (!buff)
// 		// return (0);
// 	// buff = "Hello";
// 	// lst = ft_lstnew("a\n\na\n\na", 1);
// 	// printf("lst->str : %s\n", lst->str);
// 	// buff = " World";
// 	// ft_lstappend(&lst, "\n", 6);
// 	// ft_putlst(lst);
// 	// ft_lstappend(&lst, "A", 2);
// 	// ft_putlst(lst);
// 	// ft_lstappend(&lst, " bonjourdasa\n", 25);
// 	// ft_putlst(lst);
// 	char *str1;
// 	// char *str2;

// 	str1 = ft_strdup("\0", 1);
// 	// str2 = ft_strdup("de\n", 3);
// 	ft_lstappend(&lst, str1);
// 	// ft_lstappend(&lst, str2);
// 	ft_putlst(lst);
// 	str = ft_create_str(lst);
// 	// printf("hello\n");
// 	if (!str)
// 	{
// 		printf("str is NULL\n");
// 		return (0);
// 	}
// 	// ft_putstr(str);
// 	printf("str[0] : %c\n", str[0]);
// 	printf("str[1] : %c\n", str[1]);
// 	printf("str[2] : %c\n", str[2]);
// 	printf("str[3] : %c\n", str[3]);
// 	printf("str[4] : %c\n", str[4]);
// 	printf("str[5] : %c\n", str[5]);
// 	printf("str[6] : %d\n", str[6]);
// 	printf("str[7] : %d\n", str[7]);
// 	printf("str[8] : %c\n", str[8]);
// 	printf("str[9] : %c\n", str[9]);
// 	printf("str[10] : %c\n", str[10]);
// 	printf("str[11] : %c\n", str[11]);
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