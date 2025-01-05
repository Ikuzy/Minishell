/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:49:37 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:48:56 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_inti_execution(void)
{
	g_data->save_stdin = dup(STDIN_FILENO);
	g_data->save_stdout = dup(STDOUT_FILENO);
	g_data->i_pip = 0;
	g_data->n_cmd = ft_numbers_of_cmd(g_data->command);
	g_data->i = 0;
}

void	ft_init_minishell(int ac, char **av, char **env)
{
	if (ac != 1)
	{
		ft_free_all("error in pass more args\n", 1);
	}
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	g_data = malloc(sizeof(t_data));
	if (!g_data)
		ft_free_all("error in alloc g_data\n", 1);
	ft_bzero(g_data, sizeof(t_data));
	g_data->ac = ac;
	g_data->av = av;
	g_data->old_env = env;
	ft_create_new_env();
}