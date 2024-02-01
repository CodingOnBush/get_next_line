/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:56:42 by momrane           #+#    #+#             */
/*   Updated: 2024/02/01 20:51:16 by momrane          ###   ########.fr       */
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
	int	s;
	int	i;

	if (src == NULL)
		return ;
	s = 0;
	while (src[s])
		s++;
	if (len > 0)
	{
		i = 0;
		while (i < s && i < len - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strdup(char *str)
{
	char	*out;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	out = (char *)malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, str, i + 1);
	return (out);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*out;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	out = (char *)malloc((i + len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, i + 1);
	ft_strlcpy(&out[i], s2, len + 1);
	free(s1);
	return (out);
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
