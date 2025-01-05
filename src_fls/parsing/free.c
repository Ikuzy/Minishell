/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:47:54 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:34:27 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	free_token_list(t_token *token)
{
	t_token	*next;
	int		i;

	while (token)
	{
		next = token->next;
		free(token->input);
		if (token->args)
		{
			i = 0;
			while (token->args[i])
			{
				free(token->args[i]);
				i++;
			}
			free(token->args);
		}
		free(token);
		token = next;
	}
}

void	free_parser_list(t_parser *pars)
{
	t_parser	*tmp;

	while (pars)
	{
		tmp = pars->next;
		free(pars);
		pars = tmp;
	}
}
