/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:56:42 by momrane           #+#    #+#             */
/*   Updated: 2024/01/30 22:40:13 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*dup;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len && str[start])
		dup[i++] = str[start++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	if (!str)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (s1);
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = 0;
	return (out);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	char			*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}
