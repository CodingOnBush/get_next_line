#include "get_next_line.h"

char	*ft_strcat(char *dst, char *src)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)src;
	while (dst[i])
		i++;
	while (*s && *s != '\n')
	{
		dst[i] = *s;
		s++;
		i++;
	}
	dst[i] = *s;
	dst[i + 1] = '\0';
	// free(src);
	return (dst);
}

// int	main(void)
// {
// 	char	str[100] = "Hello";
// 	char	*str2;
// 	char	*res;

// 	str2 = " World!";
// 	res = ft_strcat(str, str2);
// 	printf("res : %s\n", res);
// 	printf("res[12] : %d\n", res[12]);
// 	return (0);
// }