/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/01/29 14:38:28 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_handle_backup(char **backup, char **line)
{
	int	posn;
	int	rest;

	if (ft_strchr(*backup, '\n') != NULL)
	{
		posn = ft_strchr(*backup, '\n') - *backup;
		*line = ft_substr(*backup, 0, posn + 1);
		printf("line: %s\n", *line);
		rest = ft_strlen(*backup) - posn;
		free(*backup);
		*backup = ft_substr(*backup, posn + 1, rest);
		return (1);
	}
	*line = ft_strjoin(*line, *backup);
	free(*backup);
	*backup = NULL;
	if (!(*line))
		return (-1);
	return (0);
}

static int	ft_handle_buf(char **backup, char *buf, char **line)
{
	int		posn;
	char	*tmp;

	if (buf[0] == '\0')
		return (0);
	if (ft_strchr(buf, '\n') != NULL)
	{
		posn = ft_strchr(buf, '\n') - buf;
		tmp = ft_substr(buf, 0, posn + 1);
		if (!tmp)
			return (-1);
		*line = ft_strjoin(*line, tmp);
		if (!(*line))
			return (-1);
		free(*backup);
		*backup = NULL;
		free(tmp);
		*backup = ft_substr(buf, posn + 1, ft_strlen(buf) - posn);
		if (!(*backup))
			return (-1);
		return (0);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	if (tmp != NULL)
		free(tmp);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*line;
	char		*buf;
	int			b;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup != NULL)
		if (ft_handle_backup(&backup, &line) == 1)
			return (line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (1)
	{
		b = read(fd, buf, BUFFER_SIZE);
		buf[b] = '\0';
		if (ft_handle_buf(&backup, buf, &line) <= 0)
			break ;
	}
	if (b <= 0 && backup != NULL)
	{
		free(backup);
		backup = NULL;
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
	i = 1;
	while (i < 40)
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
