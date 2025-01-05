/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:51:32 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:35:00 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_args(t_token *start)
{
	t_token	*token;
	int		count;
	int		i;

	count = 1;
	if (!start)
		return (-1);
	token = start;
	if (is_type(token, PIPE) && token->next)
		token = token->next;
	while (token && !is_type(token, PIPE))
	{
		if (token->type == CMD || token->type == ARG)
		{
			i = 0;
			while (token->args && token->args[i++])
				count++;
		}
		token = token->next;
	}
	return (count);
}

static int	process_cmd_arg_token(char **tab, int *i, t_token *token)
{
	int	j;

	j = 0;
	if (token->type == CMD || token->type == ARG)
	{
		while (token->args && token->args[j])
		{
			tab[*i] = ft_strdup(token->args[j]);
			if (!tab[*i])
				return (0);
			(*i)++;
			j++;
		}
	}
	return (1);
}

char	**line_tab(t_token *start)
{
	t_token	*token;
	char	**tab;
	int		i;

	i = count_args(start);
	if (!start || i == -1)
		return (NULL);
	token = start;
	if (is_type(token, PIPE) && token->next)
		token = token->next;
	tab = malloc(sizeof(char *) * i);
	if (!tab)
		return (NULL);
	i = 0;
	while (token && token->type != PIPE)
	{
		process_cmd_arg_token(tab, &i, token);
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}
