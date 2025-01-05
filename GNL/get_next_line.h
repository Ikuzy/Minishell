/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:24:29 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:11:58 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup1(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*buffer_reader(char *str, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif