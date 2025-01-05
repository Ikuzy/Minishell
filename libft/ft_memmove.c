/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:13:18 by ozouine           #+#    #+#             */
/*   Updated: 2023/11/30 17:35:12 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*(d--) = *(s--);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
