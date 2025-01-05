/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:06:41 by ozouine           #+#    #+#             */
/*   Updated: 2023/11/30 17:35:07 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*srce;

	if (dest == src)
		return (dest);
	i = 0;
	dst = (unsigned char *)dest;
	srce = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = srce[i];
		i++;
	}
	return (dst);
}
