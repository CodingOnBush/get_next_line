/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:12 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 15:25:17 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//delete
# define BUFFER_SIZE 1000

typedef struct s_elem
{
	char			*str;
	struct s_elem	*next;
}					t_elem;

int		ft_get_len(t_elem *lst);
t_elem	*ft_lstnew(char *buff, int size);
void	ft_putlst(t_elem *lst);
int		ft_putstr(char *str);
char	*ft_strdup(char *s, int len);
int		ft_strlen(char *str);

char    *get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	ft_putchar(char c);
char	*ft_strdup(char *s, int len);


#endif
