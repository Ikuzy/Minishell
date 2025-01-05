/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stp_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:52:11 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:50:01 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	setup_dup2_readout(int fd, t_command *cmd)
{
	if (!cmd->args[0])
		ft_free_all(": ambiguous redirect\n", 1);
	if (cmd->type == APPEND)
		fd = open(cmd->args[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
	else if (cmd->type == TRUNC)
		fd = open(cmd->args[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd < 0)
	{
		perror(cmd->args[0]);
		ft_free_all(NULL, 0);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_free_all("error in dup2 rederiction append|trunc\n", 1);
	close(fd);
}

void	setup_dup2_readin(int fd, t_command *cmd)
{
	if (!cmd->args[0])
		ft_free_all(": ambiguous redirect\n", 1);
	fd = open(cmd->args[0], O_RDONLY);
	if (fd < 0)
	{
		perror(cmd->args[0]);
		ft_free_all(NULL, 1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_free_all("error in dup2 red_in\n", 1);
	close(fd);
}

void	ft_setup_dup2(t_command *cmd)
{
	int	fd;

	fd = 0;
	if (ft_return_next_cmd(cmd) != NULL)
		if (dup2(g_data->pipe_line[1], STDOUT_FILENO) == -1)
			ft_free_all("error in dup2 red_out in child\n", 1);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == HEREDOC)
		{
			if (dup2(g_data->pip[g_data->i_pip++][0], STDIN_FILENO) == -1)
				ft_free_all("error in dup2 heredoc\n", 1);
		}
		else if (cmd->type == APPEND || cmd->type == TRUNC)
			setup_dup2_readout(fd, cmd);
		else if (cmd->type == INF)
			setup_dup2_readin(fd, cmd);
		cmd = cmd->next;
	}
}
