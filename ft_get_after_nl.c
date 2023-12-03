#include "get_next_line.h"

char	*ft_get_after_nl(char *str)
{
	char	*newlinePos;
	char	*out;
	int		len;
	int		i;

	if (!str)
        return (NULL);
	newlinePos = ft_strchr(str, '\n');
    if (!newlinePos || *(newlinePos + 1) == '\0')
        return (NULL);
    len = 0;
    while (*(newlinePos + 1 + len) != '\0')
        len++;
    out = (char *)malloc((len + 1) * sizeof(char));
    if (!out)
        return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = *(newlinePos + 1 + i);
		i++;
	}
    out[i] = '\0';
    return (out);
}

// #include <stdio.h>

// int	main(void)
// {
//     char *str = ft_strdup("Hello\nWorld", 12);
//     char *result = ft_get_after_nl(str);
//     if (result)
// 	{
//         printf("Result: %s\n", result);
//         free(result);
// 	}
// 	else
//         printf("No newline found or only null character after newline\n");
//     return 0;
// }