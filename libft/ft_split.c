/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:35:16 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:31:58 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	count_w(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*alloc_w(char *str, char c)
{
	int		len_w;
	int		i;
	char	*ptr;

	len_w = 0;
	while (str[len_w] && str[len_w] != c)
		len_w++;
	ptr = (char *)malloc(sizeof(char) * (len_w + 1));
	if (ptr != NULL)
	{
		i = 0;
		while (i < len_w)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	**sub_split(char const *s, char c, char **strs)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = alloc_w((char *)s, c);
			if (strs[i] == NULL)
				return (ft_free(strs, i));
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (count_w((char *)s, c) + 1));
	if (strs == NULL)
		return (NULL);
	strs = sub_split(s, c, strs);
	return (strs);
}
