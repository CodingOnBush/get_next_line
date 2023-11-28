#include "get_next_line.h"

char	*ft_strdup(char *s, int len)
{
	char	*out;
	int		i;

	if (len < 0)
		return (NULL);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

// int	main(void)
// {
// 	char *s = "Hello World!";
// 	char *out = ft_strdup(s, 5);
// 	printf("%s\n", out);
// 	// printf("out[4] = %c\n", out[4]);
// 	// printf("out[5] = %d\n", out[5]);
// 	return (0);
// }