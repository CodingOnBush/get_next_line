/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/30 12:25:42 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static t_node	*lst = NULL;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_createlst(fd, &lst) < 0)
	{
		ft_freelst(&lst);
		return (NULL);
	}
	if (!lst)
		return (NULL);
	line = ft_create_str(lst);
	ft_update_lst(&lst);
	return (line);
}


int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	
	fd = open("./bible.txt", O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		// printf("line[0] : %d\n", line[0]);
		ft_putstr("line : ");
		ft_putstr(line);
		putchar('\n');
		free(line);
	}
	close(fd);
	return (0);
}
