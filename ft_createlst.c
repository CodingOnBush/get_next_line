#include "get_next_line.h"

int	ft_createlst(int fd, t_node **lst)
{
	char	*buff;
	int		s;
	
	buff = NULL;
	s = 0;
	while (ft_lstchr(*lst) == 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (-1);
		s = read(fd, buff, BUFFER_SIZE);
		if (s <= 0)
		{
			free(buff);
			return (s);
		}
		buff[s] = '\0';
		// ft_putstr("buff : ");
		// ft_putstr(buff);
		// putchar('\n');
		ft_lstappend(lst, buff);
		// ft_putlst(*lst);
	}
	// printf("YO2\n");
	return (s);
}
