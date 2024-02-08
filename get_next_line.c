/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:52:08 by momrane           #+#    #+#             */
/*   Updated: 2024/02/08 11:22:24 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	line = ft_strdup(buf);
	while (1)
	{
		if (ft_strchr(line, '\n') != NULL)
			break;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf, bytes);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') != NULL)
	{
		ft_strlcpy(buf, ft_strchr(line, '\n') + 1, BUFFER_SIZE + 1);
		line[ft_strchr(line, '\n') - line + 1] = '\0';
	}
	else
		buf[0] = '\0';
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("->%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
