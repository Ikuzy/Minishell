/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:03:12 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:51:21 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_appand(char *var, char *newstr)
{
	int		j;
	char	*path;

	j = -1;
	path = ft_expand_var(var);
	free(var);
	while (path && path[++j])
		newstr = apend_char_str(newstr, path[j]);
	return (newstr);
}
