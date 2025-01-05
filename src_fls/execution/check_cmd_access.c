/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:42:33 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:46:02 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_cmd_is_path(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || *cmd == '\0')
		return (-1);
	while (cmd[i])
		if (cmd[i++] == '/')
			return (1);
	return (0);
}

int	is_a_directory(char *path)
{
	struct stat		path_stat;
	unsigned int	flag;

	flag = 0;
	if (stat(path, &path_stat) == -1)
		return (0);
	flag = path_stat.st_mode;
	return (S_ISDIR(flag));
}

void	ft_check_path(char *path)
{
	if (!path)
		return ;
	if (access(path, F_OK) == 0)
	{
		if (is_a_directory(path) == 1)
		{
			ft_putstr_fd(path, 2);
			ft_free_all(": Is a directory\n", 126);
		}
		else if (access(path, X_OK) != 0)
		{
			perror(path);
			ft_free_all(NULL, 126);
		}
	}
	else
	{
		perror(path);
		ft_free_all(NULL, 127);
	}
}
