/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambigeous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:49:08 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:45:06 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	amb_count_args(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	ambigeous_file(t_token *token)
{
	t_token	*cur;

	cur = token;
	while (cur)
	{
		if (cur->args && cur->args[0])
		{
			if (cur && cur->type == FILENAME && amb_count_args(cur->args) > 1)
			{
				if (cur->input)
					free(cur->input);
				cur->input = NULL;
			}
		}
		else if (amb_count_args(cur->args) == 0 && cur->type == FILENAME)
		{
			if (cur->input)
				free(cur->input);
			cur->input = NULL;
		}
		cur = cur->next;
	}
}
