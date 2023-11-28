/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/28 21:08:39 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_lst(t_node *lst)
{
	t_node	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->str);
		free(lst);
		lst = temp;
	}
}

void ft_create_list(t_node **lst, char **buff, int fd)
{
	int		size;
	
	while ((size = read(fd, *buff, BUFFER_SIZE)) > 0 && !ft_lstchr(*lst, '\n'))
	{
		// ft_putstr("buff : ");
		// ft_putstr(*buff);
		// printf("\n");
		// printf("size : %d\n", size);
		ft_lstappend(lst, *buff, size);
	}
	// printf("size : %d\n", size);
	// ft_putlst(*lst);
}



char    *get_next_line(int fd)
{
	static t_node	*lst;
	char			*line;
	char			*buff;
	
	lst = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ft_create_list(&lst, &buff, fd);
	if (lst != NULL)
	{
		ft_putlst(lst);
		// printf("hello\n");
		line = ft_create_str(lst);
		ft_update_lst(&lst);
		ft_putlst(lst);
		return (line);
	}
	// ft_putlst(lst);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		size;
	int		i;
	
	size = 0;
	fd = open("file.txt", O_RDONLY);
	i = 0;
	// line = get_next_line(fd);
	// ft_putstr(line);
	// printf("\n");
	// printf("line[0] : %c\n", line[0]);
	// printf("line[1] : %d\n", line[1]);

	// line = get_next_line(fd);
	// ft_putstr(line);
	// printf("\n");
	// printf("line[0] : %c\n", line[0]);
	// printf("line[1] : %d\n", line[1]);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_putstr(line);
		printf("\n");
		// printf("line : %s\n", line);
		// printf("line[0] : %c\n", line[0]);
		// printf("line[1] : %d\n", line[1]);
		// printf("line[2] : %c\n", line[2]);
		// printf("line[3] : %c\n", line[3]);
		// printf("line[4] : %d\n", line[4]);
		// printf("line[5] : %d\n", line[5]);
		i++;
	}
	close(fd);
	return (0);
}
