/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_backup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:44:35 by momrane           #+#    #+#             */
/*   Updated: 2024/01/30 17:54:48 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_n_in_backup(char **backup, char **line)
{
	int		n;
	char	*tmp;

	tmp = ft_strdup(*backup);
	if (!tmp)
		return ;
	free(*backup);
	n = ft_strchr(tmp, '\n') - tmp;
	*line = ft_substr(tmp, 0, n + 1);
	if (!(*line))
		return ;
	if (n == ft_strlen(tmp))
		*backup = NULL;
	else
		*backup = ft_substr(tmp, n + 1, ft_strlen(tmp) - n);
}

void	ft_handle_backup(char **backup, char **line)
{
	if (*backup == NULL || *line != NULL)
		return ;
	if (ft_strchr(*backup, '\n') != NULL)
		ft_n_in_backup(backup, line);
	else
	{
		*line = ft_strdup(*backup);
		if (!(*line))
			return ;
		free(*backup);
		*backup = NULL;
	}
}

int	main(void)
{
	char	*line;
	char	*backup;

	line = NULL;
	backup = ft_strdup("HelloWorld\n");
	ft_handle_backup(&backup, &line);
	printf("line: %s\n", line);
	printf("backup: %s\n", backup);
	if (line)
		free(line);
	free(backup);
	return (0);
}
