/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:08:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/28 13:03:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_create_list(t_node **lst, int fd)
{
	char	*buff;
	int		size;
	
	if (*lst != NULL)
	{
		if (ft_lstchr(*lst, '\n'))
			return ;
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff || (size = read(fd, buff, BUFFER_SIZE)) <= 0)
		return ;
	if (!(*lst))
		*lst = ft_lstnew(buff, size); 
	else
		ft_lstadd(lst, ft_lstnew(buff, size));
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0 && ft_strchr(buff, '\n') == 0)
		ft_lstadd(lst, ft_lstnew(buff, size));
	if (size > 0)
		ft_lstadd(lst, ft_lstnew(buff, size));
	free(buff);
}

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

char    *get_next_line(int fd)
{
	static t_node	*lst = NULL;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!lst)
		ft_create_list(&lst, fd);
	// TODO : create string from list
	// TODO : update list
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		size;
	
	size = 0;
	fd = open("file2.txt", O_RDONLY);
	
	line = get_next_line(fd);
	printf("line : %s\n", line);
	
	line = get_next_line(fd);
	printf("line : %s\n", line);

	line = get_next_line(fd);
	printf("line : %s\n", line);

	line = get_next_line(fd);
	printf("line : %s\n", line);

	line = get_next_line(fd);
	printf("line : %s\n", line);	

	line = get_next_line(fd);
	printf("line : %s\n", line);

	// line = get_next_line(fd);
	// printf("line : %s\n", line);

	// line = get_next_line(fd);
	// printf("line : %s\n", line);

	// line = get_next_line(fd);
	// printf("line : %s\n", line);	

	// line = get_next_line(fd);
	// printf("line : %s\n", line);
	
	// line = "abcd\n";
	// printf("line : %s\n", line);
	// int npos = ft_get_index(line, '\n');
	// printf("npos : %d\n", npos);
	// printf("line[pos] : %s\n", &(line[npos + 1]));
	
	// line = get_next_line(fd);
	// printf("line : %s\n", line);

	// line = get_next_line(fd);
	// printf("line : %s\n", line);

	// line = get_next_line(fd);
	// printf("line : %s\n", line);

	close(fd);
	return (0);
}

/*
void	ft_lstadd(t_list **lst, t_list *new)
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

t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
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
			ft_putstr((char *)lst->str);
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

	// printf("STRDUP s : %s\n", s);
	// printf("STRDUP len : %d\n", len);
	if (!s)
		return (NULL);
	if (ft_strchr((char *)s, '\n') == 0)
		res = (char *)malloc(sizeof(char) * (len + 2));
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = '\n';
		res[i + 1] = '\0';
	}
	else
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

char	*ft_strcdup(const char *s, int len, int c)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

char	*ft_strcat(char *dest, const char *src)
{
	char *res;

	res = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (res);
}


char	*ft_create_str(t_list *lst)
{
	char *result;
	
	if (!lst)
		return (NULL);
	size_t total_length = 0;
	t_list *current = lst;
	while (current != NULL)
	{
		total_length += ft_strlen(current->str);
		current = current->next;
	}
	result = (char *)malloc(total_length + 1);
	if (!result)
		return NULL;
	current = lst;
	while (current != NULL)
	{
		ft_strcat(result, current->str);
		current = current->next;
	}
	return (result);
}

void	*ft_create_list(t_list *lst, int fd)
{
	char	*buff;
	int		size;
	
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff || (size = read(fd, buff, BUFFER_SIZE)) <= 0)
		return (NULL);
	lst = ft_lstnew(ft_strdup(buff, size));
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0 && !ft_strchr(buff, '\n'))
		ft_lstadd(&lst, ft_lstnew(ft_strdup(buff, size)));
	ft_putlst(lst);
	return (ft_strcdup(buff, size, '\n'));
}

char    *get_next_line(int fd)
{
	static t_list	*lst;
	char 		  	*buff;
	char			*line;
	int				size;
	int				len;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lst = ft_create_list(lst, fd);

	if (lst == NULL)
		return (NULL);
	
	line = ft_create_str(lst);

	return (line);
}
*/