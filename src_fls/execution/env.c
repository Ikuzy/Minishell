/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:44:02 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:46:39 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_lst_create_env_node(char *str)
{
	t_env	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_env));
	if (!new)
		ft_free_all("Error in allocation of new_node in new_env\n", 1);
	new->value = ft_strdup(str);
	if (!new->value)
	{
		free(new);
		ft_free_all("Error in allocation in new_value\n", 1);
	}
	new->next = NULL;
	return (new);
}

void	ft_lst_add_back_env_node(t_env *next)
{
	t_env	*head;

	if (next)
	{
		head = g_data->new_env;
		while (head->next)
			head = head->next;
		head->next = next;
	}
}

void	ft_create_minimal_env(void)
{
	t_env	*next;
	char	*pwd;
	char	*tmp;

	g_data->new_env = ft_lst_create_env_node("SHLVL=1");
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		tmp = ft_strjoin("PWD=", pwd);
		next = ft_lst_create_env_node(tmp);
		ft_lst_add_back_env_node(next);
		free(pwd);
		free(tmp);
	}
}

void	ft_create_new_env(void)
{
	int		i;
	char	*tmp;
	t_env	*next;

	i = 0;
	if (!g_data->old_env || !g_data->old_env[0])
	{
		ft_create_minimal_env();
		return ;
	}
	g_data->new_env = ft_lst_create_env_node(g_data->old_env[i++]);
	while (g_data->old_env[i])
	{
		if (ft_check_env_var(g_data->old_env[i], "SHLVL") == 0)
		{
			tmp = ft_update_shlvl(g_data->old_env[i] + 6);
			next = ft_lst_create_env_node(tmp);
			free(tmp);
		}
		else
			next = ft_lst_create_env_node(g_data->old_env[i]);
		ft_lst_add_back_env_node(next);
		i++;
	}
}

void	ft_env(void)
{
	t_env	*env;

	env = g_data->new_env;
	while (env)
	{
		if (ft_check_equal_env(env->value) == 1)
			printf("%s\n", env->value);
		env = env->next;
	}
	ft_free_all(NULL, 0);
}
