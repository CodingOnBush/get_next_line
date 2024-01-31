/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/01/30 20:53:35 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_handle_buf(char **backup, char *buf, char **line)
{
	int		posn;
	char	*tmp;

	if (buf[0] == '\0')
	{
		free(*backup);
		*backup = NULL;
		return (0);
	}
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
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (ft_handle_buf(&backup, buffer, &line) <= 0)
			break ;
	}
	free(buffer);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	line = NULL;
// 	fd = open("file", O_RDONLY);
// 	i = 1;
// 	while (i < 40)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("[%d] : %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// 	// gcc -Wall -Werror -Wextra *.c -g3 -D BUFFER_SIZE=5
// 	// valgrind -s --track-origins=yes --leak-check=full ./a.out
// }
