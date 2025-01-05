/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:45:27 by ozouine           #+#    #+#             */
/*   Updated: 2023/11/30 17:35:41 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, i);
	return (result);
}
