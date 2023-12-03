/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/12/03 12:29:04 by allblue          ###   ########.fr       */
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
	if (s < 0 || !lst)
	{
		ft_freelst(&lst);
		return (NULL);
	}
	// ft_putlst(lst);
	line = ft_create_str(lst);
	if (line == NULL)
	{
		ft_freelst(&lst);
		lst = NULL;
		return (NULL);
	}
	// ft_putstr("line inside : ");
	// ft_putstr(line);
	// putchar('\n');
	// printf("YO\n");
	ft_update_lst(&lst);
	// ft_putstr("line : ");
	// ft_putstr(line);
	// putchar('\n');
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("./file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_putstr("line : ");
		ft_putstr(line);
		putchar('\n');
	}
	free(line);
	close(fd);
	return (0);
}
