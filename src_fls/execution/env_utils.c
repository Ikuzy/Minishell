/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:43:26 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:27:03 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_calc_env(void)
{
	int		i;
	t_env	*next;

	i = 0;
	next = g_data->new_env;
	while (next)
	{
		next = next->next;
		i++;
	}
	return (i);
}

char	*ft_update_shlvl(char *str)
{
	int		num;
	char	*tmp;
	char	*tmp2;

	if (!str)
		return (NULL);
	num = ft_atoi(str);
	num++;
	tmp = ft_itoa(num);
	if (!tmp)
		return (NULL);
	tmp2 = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	return (tmp2);
}

int	ft_check_equal_env(char *value)
{
	if (!value)
		return (-1);
	while (*value)
		if (*value++ == '=')
			return (1);
	return (0);
}

char	*ft_get_env_last_cmd(t_command *last)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	tab = last->args;
	if (!tab)
		return (NULL);
	while (tab[i] && tab[i + 1])
		i++;
	line = ft_strjoin("_=", tab[i]);
	return (line);
}
