#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char			*ptr;
	unsigned char	val;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	val = (unsigned char)c;
	while (*ptr)
	{
		if (*ptr == val)
			return (ptr);
		ptr++;
	}
	if (*ptr == val)
		return (ptr);
	return (0);
}