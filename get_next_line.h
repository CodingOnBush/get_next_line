/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:12 by momrane           #+#    #+#             */
/*   Updated: 2023/11/29 10:44:59 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 1000000
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//delete


typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}					t_node;

char	*ft_create_str(t_node *lst);
int		ft_get_len(t_node *lst);
void	ft_lstappend(t_node **lst, char *buff, int size);
int		ft_lstchr(t_node *lst, int c);
t_node	*ft_lstnew(char *buff, int size);
void	ft_putchar(char c);//delete
void	ft_putlst(t_node *lst);//delete
int		ft_putstr(char *str);//delete
char	*ft_remove_before(char *str, char c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s, int len);
int		ft_strlen(char *str);
void	ft_update_lst(t_node **lst);
char    *get_next_line(int fd);
int		ft_createlst(int fd, t_node **lst);
void	ft_freelst(t_node **lst);

#endif
