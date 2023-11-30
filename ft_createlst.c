#include "get_next_line.h"

int	ft_createlst(int fd, t_node **lst)
{
	char	*buff;
	int		s;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!ft_lstchr(*lst, '\n'))
	{
		while ((s = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[s] = '\0';
			ft_lstappend(lst, buff, s);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	}
	free(buff);
	return (s);
}