/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:54:17 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 22:14:08 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_env_var(char *env, char *var)
{
	int	i;

	i = 0;
	while (env[i] && var[i])
	{
		if (env[i] != var[i])
			break ;
		i++;
	}
	if (!var[i] && (env[i] == '=' || !env[i]))
		return (0);
	return (-1);
}

void	ft_lst_del_env_node(t_env *to_del)
{
	t_env	*head;
	t_env	*next;

	if (!to_del || !g_data->new_env)
		return ;
	head = g_data->new_env;
	next = to_del->next;
	if (head && head == to_del)
		g_data->new_env = head->next;
	else
		while (head->next && head->next != to_del)
			head = head->next;
	head->next = next;
	free(to_del->value);
	free(to_del);
}

int	ft_unset_from_env(char *var)
{
	t_env	*head;
	t_env	*tmp;

	if (!var || *var == '\0')
	{
		return (0);
	}
	head = g_data->new_env;
	while (head)
	{
		tmp = head->next;
		if (ft_check_env_var(head->value, var) == 0)
			ft_lst_del_env_node(head);
		head = tmp;
	}
	return (0);
}

int	ft_unset(char **args)
{
	int	i;

	i = 1;
	if (!args)
		return ((g_data->exit = 0), 0);
	while (args[i])
		ft_unset_from_env(args[i++]);
	return ((g_data->exit = 0), 0);
}

char	*ft_prompt(int flag)
{
	if (g_data->prompt)
		free(g_data->prompt);
	if (flag == 1)
		g_data->prompt = ft_strdup ("minishell >> ");
	else
		g_data->prompt = ft_strdup ("\nminishell >> ");
	return (g_data->prompt);
}
