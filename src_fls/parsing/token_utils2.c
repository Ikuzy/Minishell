/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:58:06 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 21:06:52 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_sep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("<>|;", line[i]))
		return (0);
	else if (ft_strchr("<>|;", line[i]) && quotes(line, i) == 0)
		return (1);
	else
		return (0);
}

int	is_types(t_token *token, char *types)
{
	if (ft_strchr(types, 'X') && is_type(token, CMD))
		return (1);
	else if (ft_strchr(types, 'G') && is_type(token, ARG))
		return (1);
	else if (ft_strchr(types, 'F') && is_type(token, FILENAME))
		return (1);
	else if (ft_strchr(types, 'T') && is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && is_type(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && is_type(token, INF))
		return (1);
	else if (ft_strchr(types, 'P') && is_type(token, PIPE))
		return (1);
	else if (ft_strchr(types, 'H') && is_type(token, HEREDOC))
		return (1);
	return (0);
}

void	process_token_help(t_token **token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	if ((*token)->next)
		ft_putstr_fd((*token)->next->input, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putendl_fd("'", 2);
}
