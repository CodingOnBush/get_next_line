/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/24 18:21:59 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_putlst(t_list *lst)
{
	if (lst)
	{
		ft_putstr("list : ");
		while (lst)
		{
			ft_putstr((char *)lst->content);
			ft_putstr("---->");
			lst = lst->next;
		}
		ft_putstr("NULL");
		ft_putchar('\n');
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_remainder_strdup(const char *s, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    *get_next_line(int fd)
{
	static t_list	*remainder;
	t_list	*line;
	size_t	size;
	char	*buff;
	int	len;
	int	i;

	remainder = NULL;
	len = 0;
	i = 0;
	size = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
		
	if (remainder == NULL)
	{
		// printf("remainder : NULL\n");
		line = remainder;
	}
	else
	{
		// printf("remainder : %s\n", (char *)remainder->content);
		line = ft_lstnew(remainder->content);
	}

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);

	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0 && ft_strchr(buff, '\n') == 0)
	{
		ft_lstadd_back(&line, ft_lstnew(ft_strdup(buff, size)));
		size = read(fd, buff, BUFFER_SIZE);
	}
	// printf("buff : %s\n", buff);
	remainder = ft_lstnew(ft_remainder_strdup(buff, size));
	// printf("remainder : %s\n", (char *)remainder->content);
	
	// printf("remainder : %s\n", (char *)remainder->content);
	// printf("here : %s\n", str);
	// remainder = ft_lstnew(ft_strchr(buff, '\n') + 1);
	// printf("remainder : %s\n", (char *)remainder->content);
	// if (remainder == NULL)
	// 	line = ft_lstnew(remainder);
	// else
	// 	line = ft_lstnew(buff); 
	// {
	// 	ft_lstadd_back(&line, ft_lstnew(buff));
	// 	// printf("line->content : %s\n", (char *)line->content);
	// 	size = read(fd, buff, BUFFER_SIZE);
	// }
	// if (size > 0)
	// {
	// 	remainder = ft_strchr(buff, '\n') + 1;
	// 	printf("remainder : %s\n", remainder);
	// }
	// if (line)
	// 	printf("line->content : %s\n", (char *)line->content);

	ft_putlst(line);
	free(buff);
	return (line->content);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		size;
	
	size = 0;
	fd = open("file2.txt", O_RDONLY);
	line = get_next_line(fd);
	// if (!line)
	// 	return (0);
	printf("1.return : %s\n", line);

	line = get_next_line(fd);
	// if (!line)
	// 	return (0);
	printf("2.return : %s\n", line);

	line = get_next_line(fd);
	// if (!line)
	// 	return (0);
	printf("3.return : %s\n", line);

	line = get_next_line(fd);
	// if (!line)
	// 	return (0);
	printf("4.return : %s\n", line);

	close(fd);
	return (0);
}