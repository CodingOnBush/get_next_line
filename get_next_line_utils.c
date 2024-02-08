/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:56:42 by momrane           #+#    #+#             */
/*   Updated: 2024/02/08 11:24:20 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	if (src == NULL)
		return ;
	src_len = ft_strlen(src);
	if (len > 0)
	{
		i = 0;
		while (i < src_len && i < len - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}

char	*ft_strjoin(char *line, char *buf, int buf_len)
{
	char	*res;
	int		line_len;

	if (line == NULL)
		return (NULL);
	line_len = ft_strlen(line);
	res = (char *)malloc((line_len + buf_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, line, line_len + 1);
	ft_strlcpy(&res[line_len], buf, buf_len + 1);
	free(line);
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
