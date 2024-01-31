/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/01/31 11:24:12 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = ft_strdup(buf);
	while (1)
	{
		if (ft_strchr(line, '\n') != NULL)
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		line = ft_strjoin(line, buf, bytes_read);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (ft_strchr(line, '\n') != NULL)
		ft_strlcpy(buf, ft_strchr(line, '\n') + 1, BUFFER_SIZE + 1);
	else
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	if (ft_strchr(line, '\n') != NULL)
		line[ft_strchr(line, '\n') - line + 1] = '\0';
	else
		line[ft_strlen(line)] = '\0';
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
