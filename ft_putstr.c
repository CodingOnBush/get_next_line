#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			write(1, "#", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}