#include "get_next_line.h"

char	*ft_remove_before(char *str, char c)
{
	char	*out;
	int		i;
	int		j;
	// int		len;

	i = 0;
	if (!str)
		return (NULL);
	// ft_putstr("str = ");
	// ft_putstr(str);
	// printf("\n");
	while (str[i] && str[i] != c)
		i++;
	// len = ft_strlen(str) - i;
	// ft_putstr("len = ");
	// printf("%d\n", len);
	out = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!out)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		out[j] = str[i];
		i++;
		j++;
	}
	out[j] = '\0';
	return (out);
}

// int	main(void)
// {
// 	char	*out;
// 	char	*str;
// 	char	c;

// 	c = 'd';
// 	str = malloc(sizeof(char) * 5);
// 	if (!str)
// 		return (0);
// 	str[0] = 'd';
// 	str[1] = '\0';
// 	str[2] = 'd';
// 	str[3] = 'd';
// 	str[4] = '\0';
// 	printf("str : %s\n", str);
// 	out = ft_remove_before(str, c);
// 	printf("out : %s\n", out);
// 	if (out)
// 	{
// 		printf("out[0] : %c\n", out[0]);
// 		printf("out[1] : %c\n", out[1]);
// 		printf("out[2] : %c\n", out[2]);
// 		printf("out[3] : %d\n", out[3]);
// 		return (0);
// 	}

// 	t_node	*lst;

// 	lst = ft_lstnew(str, 4);
// 	str = "ij\nkl";
// 	ft_lstappend(&lst, str, 4);
// 	ft_putlst(lst);

// 	lst->next->str = ft_remove_before(lst->next->str, '\n');
// 	ft_putlst(lst);
// 	return (0);
// }
