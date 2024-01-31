/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:56:42 by momrane           #+#    #+#             */
/*   Updated: 2024/01/31 16:15:23 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

void	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	if (!src || dstsize <= 0)
		return ;
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int	len;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len + 1);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	int		s1_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	join = (char *)malloc((s1_len + len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, len + 1);
	free(s1);
	return (join);
}
