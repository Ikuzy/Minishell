/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emty_cmd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:05:46 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:04:13 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	process_token(t_token **token, t_token **cur, t_token **prev,
		t_token *next)
{
	if (((*cur)->type == CMD || (*cur)->type == ARG)
		&& (*cur)->input[0] == '\0')
	{
		if (*prev)
			(*prev)->next = next;
		else
			*token = next;
		if (next)
			next->prev = *prev;
		free((*cur)->input);
		free(*cur);
		*cur = next;
	}
	else
	{
		*prev = *cur;
		*cur = next;
	}
}

void	ignore_empty_cmd_arg(t_token **token)
{
	t_token	*cur;
	t_token	*next;
	t_token	*prev;

	if (!token || !*token)
		return ;
	cur = *token;
	prev = NULL;
	while (cur)
	{
		next = cur->next;
		process_token(token, &cur, &prev, next);
	}
	get_tokens_type(*token, 0);
}
