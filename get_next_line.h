/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:12 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 09:05:25 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//delete
# define BUFFER_SIZE 1

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char    *get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strdup(char *s, int len);


#endif
