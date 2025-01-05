/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:25:55 by ozouine           #+#    #+#             */
/*   Updated: 2023/11/30 17:36:05 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = ft_strlen(s);
	while (0 <= j)
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		j--;
	}
	return (NULL);
}
