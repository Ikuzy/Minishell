/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:52:46 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:50:09 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_to_nl(char *str)
{
	int	i;
	int	n_nl;

	n_nl = 0;
	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '\n')
			n_nl = i;
		i++;
	}
	i = 0;
	while (str[i] && i <= n_nl)
		write(1, &str[i++], 1);
}

void	ft_sig_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		ft_free_all(NULL, 130);
	}
	else if (sig == SIGQUIT)
	{
		ft_free_all("Quit\n", 131);
	}
}

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_free_utils();
		g_data->exit = 130;
		g_data->command = NULL;
		write(1, "\n", 1);
		rl_on_new_line();
		ft_print_to_nl(ft_prompt(2));
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
