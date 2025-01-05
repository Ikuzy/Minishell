/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:47:30 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:03:40 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_utils_2(void)
{
	if (g_data->exec_env)
	{
		ft_free_tab(g_data->exec_env);
		g_data->exec_env = NULL;
	}
	if (g_data->prompt)
	{
		free(g_data->prompt);
		g_data->prompt = NULL;
	}
	if (g_data->command)
	{
		ft_free_command(g_data->command);
		g_data->command = NULL;
	}
}

void	ft_free_utils(void)
{
	if (g_data)
	{
		g_data->i = 0;
		if (g_data->pip)
			ft_close_free_heredoc_pipes();
		if (g_data->path)
		{
			free(g_data->path);
			g_data->path = NULL;
		}
		if (g_data->tab)
		{
			ft_free_tab(g_data->tab);
			g_data->tab = NULL;
		}
		ft_free_utils_2();
	}
}
