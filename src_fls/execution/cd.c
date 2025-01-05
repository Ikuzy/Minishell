/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:33:07 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:45:53 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_expand_var(char *var)
{
	t_env	*next;
	int		i;

	if (!var)
		return (NULL);
	next = g_data->new_env;
	while (next && ft_check_env_var(next->value, var) != 0)
		next = next->next;
	if (!next)
		return (NULL);
	i = ft_strlen(var) + 1;
	return (next->value + i);
}

void	ft_free_pwd(char *new_path, char *old_path)
{
	if (old_path)
		free(old_path);
	if (new_path)
		free(new_path);
}

int	ft_change_dir(char *path)
{
	char	*var;
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = NULL;
	new_pwd = NULL;
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
		return (perror(path), ft_free_pwd(new_pwd, old_pwd), -1);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (perror(path), ft_free_pwd(new_pwd, old_pwd), -1);
	var = ft_strjoin("PWD=", new_pwd);
	if (!var)
		return (ft_free_pwd(new_pwd, old_pwd), -1);
	ft_add_or_update(var);
	free(var);
	if (!old_pwd)
		return (free(old_pwd), free(new_pwd), 0);
	var = ft_strjoin("OLDPWD=", old_pwd);
	if (!var)
		return (ft_free_pwd(new_pwd, old_pwd), -1);
	ft_add_or_update(var);
	free(var);
	return (free(new_pwd), free(old_pwd), 0);
}

int	ft_cd(char **arg)
{
	int		n_arg;
	char	*path;

	n_arg = 0;
	while (arg[n_arg])
		n_arg++;
	if (n_arg > 2)
		return (ft_putstr_fd("bash: cd: too many arguments\n", 2),
			(g_data->exit = 1), 0);
	else if (n_arg == 1)
	{
		path = ft_expand_var("HOME");
		if (!path)
			return ((g_data->exit = 0), ft_putstr_fd("bash: cd: HOME not set",
					2), 0);
		if (ft_change_dir(path) == -1)
			return (-1);
	}
	else if (n_arg == 2)
		if (ft_change_dir(arg[1]) == -1)
			return ((g_data->exit = 1), -1);
	return ((g_data->exit = 0), 0);
}
