/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:45:11 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:46:56 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_numbers_of_cmd(t_command *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		if (cmd->type == PIPE)
			count++;
		cmd = cmd->next;
	}
	return (count);
}

t_command	*ft_return_next_cmd(t_command *cmd)
{
	while (cmd && cmd->type != PIPE)
		cmd = cmd->next;
	if (!cmd)
		return (cmd);
	return (cmd->next);
}

t_command	*ft_return_cmd_index(t_command *cmd)
{
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == CMD)
			return (cmd);
		cmd = cmd->next;
	}
	return (NULL);
}

char	*fetch_path_of_cmd(t_env *env, char *cmd)
{
	int	i;

	i = 0;
	if (check_cmd_is_path(cmd) == 1)
		return (ft_check_path(g_data->path), ft_strdup(cmd));
	else if (check_cmd_is_path(cmd) == -1)
		return (ft_putstr_fd(cmd, 2), ft_free_all(": command not found\n", 127),
			NULL);
	while (env && ft_strnstr(env->value, "PATH=", 6) == NULL)
		env = env->next;
	if (!env)
		return (ft_strjoin("./", cmd));
	g_data->tab = ft_split(env->value + 5, ':');
	if (!g_data->tab)
		ft_free_all("error in split in fetch path\n", 1);
	while (g_data->tab[i])
	{
		g_data->path = ft_strjoin_path(g_data->tab[i++], cmd, '/');
		if (access(g_data->path, F_OK) == 0)
			return (g_data->path);
		free(g_data->path);
	}
	return (NULL);
}

void	ft_get_next_pip(t_command *cmd)
{
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == HEREDOC)
			g_data->i_pip++;
		cmd = cmd->next;
	}
}
