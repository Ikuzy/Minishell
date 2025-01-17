/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:49:47 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:04:39 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	process_token(t_token **cur, t_token **start, int *flag)
{
	if (*flag == 1)
	{
		while (*start)
		{
			*start = (*start)->next;
			if (*start && (*start)->type == PIPE)
			{
				*cur = *start;
				if ((*start)->next && (*start)->next->type != CMD)
					*flag = 0;
				break ;
			}
		}
	}
	if (*flag == 0)
	{
		if ((*cur)->type == ARG && (*cur)->prev
			&& (*cur)->prev->type == FILENAME)
		{
			(*cur)->type = CMD;
			*flag = 1;
		}
	}
}

void	check_cmd(t_token *token)
{
	t_token	*cur;
	t_token	*start;
	int		flag;

	cur = token;
	start = token;
	if (cur && cur->type == CMD)
		flag = 1;
	else
		flag = 0;
	while (cur)
	{
		process_token(&cur, &start, &flag);
		cur = cur->next;
	}
	cur = token;
}

void	get_tokens_type(t_token *token, int sep)
{
	t_token	*cur;

	cur = token;
	while (cur)
	{
		if (ft_strcmp(cur->input, ">") == 0 && sep == 0)
			cur->type = TRUNC;
		else if (ft_strcmp(cur->input, ">>") == 0 && sep == 0)
			cur->type = APPEND;
		else if (ft_strcmp(cur->input, "<") == 0 && sep == 0)
			cur->type = INF;
		else if (ft_strcmp(cur->input, "<<") == 0 && sep == 0)
			cur->type = HEREDOC;
		else if (ft_strcmp(cur->input, "|") == 0 && sep == 0)
			cur->type = PIPE;
		else if (cur->prev == NULL || cur->prev->type >= TRUNC)
			cur->type = CMD;
		else
			cur->type = ARG;
		cur = cur->next;
	}
	get_file_types(token);
	check_cmd(token);
}

void	get_file_types(t_token *token)
{
	t_token	*cur;

	cur = token;
	while (cur)
	{
		if (cur->prev && is_types(cur->prev, "TAIH") && !is_types(cur, "TAIHP"))
			cur->type = FILENAME;
		cur = cur->next;
	}
}
