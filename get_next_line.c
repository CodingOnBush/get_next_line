/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/30 12:36:40 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static t_node	*lst = NULL;
	char			*line;
	int				s;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_createlst(fd, &lst);
	if (s < 0)
	{
		// ft_freelst(&lst);
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
	
	fd = open("./file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_putstr("line : ");
		ft_putstr(line);
		putchar('\n');
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
