/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:53:30 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:35:15 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	split_token_input(t_token *token)
{
	t_token	*cur;

	if (!token)
		return ;
	cur = token;
	while (cur)
	{
		if (is_types(cur, "XGF"))
		{
			cur->args = ft_split_it(cur->input);
		}
		else
			cur->args = NULL;
		cur = cur->next;
	}
}
