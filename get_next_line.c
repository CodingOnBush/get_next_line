/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/01/29 11:10:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_handle_backup(char **backup, char **line)
{
	int posn;
	int rest;
		
	if (ft_strchr(*backup, '\n') == NULL)
	{
		*line = ft_strdup(*backup);
		*backup = NULL;
		return ;
	}
	posn = ft_strchr(*backup, '\n') - *backup;
	*line = ft_substr(*backup, 0, posn + 1);
	rest = ft_strlen(*backup) - posn;
	*backup = ft_substr(*backup, posn + 1, rest);
}

static int	ft_handle_buf(char **backup, char *buf, char **line)
{
	int	posn;

	if (ft_strchr(buf, '\n') == NULL)
	{
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (-1);
		return (1);
	}
	posn = ft_strchr(buf, '\n') - buf;
	*line = ft_strjoin(*line, ft_substr(buf, 0, posn + 1));
	if (!(*line))
		return (-1);
	*backup = ft_substr(buf, posn + 1, ft_strlen(buf) - posn);
	if (!(*backup))
		return (-1);
	return (0);
}

// static void	ft_n_in_backup(char **backup, char **line)
// {
// 	int posn;
// 	int rest;

// 	posn = ft_strchr(*backup, '\n') - *backup;
// 	*line = ft_substr(*backup, 0, posn + 1);
// 	if (!(*line))
// 		return ;
// 	rest = ft_strlen(*backup) - posn;
// 	*backup = ft_substr(*backup, posn + 1, rest);
// 	if (!(*backup))
// 		return ;
// }

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*line;
	char		*buf;
	int			b;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_handle_backup(&backup, &line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b = 1;
	while (b > 0)
	{
		b = read(fd, buf, BUFFER_SIZE);
		buf[b] = '\0';
		if (ft_handle_buf(&backup, buf, &line) <= 0)
			break;
	}
	free(buf);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("[%d] : %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
	// gcc -Wall -Werror -Wextra *.c -g3 -D BUFFER_SIZE=5
	// valgrind -s --track-origins=yes --leak-check=full ./a.out
}
