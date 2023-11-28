#include "get_next_line.h"

int	ft_get_index(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

// int	main(void)
// {
// 	char	*str;
// 	int		npos;

// 	str = "abcd";
// 	printf("str : %s\n", str);
// 	npos = ft_get_index(str, '\n');
// 	printf("\\n at %d pos\n", npos);
// 	printf("&(str[npos + 1]) : %s\n", &(str[npos + 1]));
// 	return (0);
// }