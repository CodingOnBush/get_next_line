/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/01/31 16:19:41 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;
	int			i;

	line = ft_strdup(buf);
	while (1)
	{
		if (ft_strchr(line, '\n') != NULL)
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf, bytes);
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') != NULL)
	{
		ft_strlcpy(buf, ft_strchr(line, '\n') + 1, BUFFER_SIZE + 1);
		i = ft_strchr(line, '\n') - line + 1;
	}
	else
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	line[i] = '\0';
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
