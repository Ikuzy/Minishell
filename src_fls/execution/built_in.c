/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:32:29 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:45:33 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	get_pwd_from_env(void)
{
	char	*pwd;

	pwd = ft_expand_var("PWD");
	if (pwd)
	{
		printf("%s\n", pwd);
		ft_free_all(NULL, 1);
	}
	ft_free_all("This location have no  path\n", 1);
}

void	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		get_pwd_from_env();
	printf("%s\n", pwd);
	free(pwd);
	ft_free_all(NULL, 0);
}

void	ft_check_exit_arg(char **args)
{
	int	i;

	i = 0;
	while (args[1][i] && (args[1][i] == ' ' || args[1][i] == '	'))
		i++;
	if (args[1][i] == '+' || args[1][i] == '-')
		i++;
	while (args[1][i])
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			ft_putstr_fd(args[1], 2);
			g_data->exit = 2;
			ft_free_all(": numeric argument required\n", 2);
		}
		i++;
	}
	if (i >= 16 && (ft_atoi(args[1]) == 0 || ft_atoi(args[1]) == -1))
	{
		ft_putstr_fd(args[1], 2);
		g_data->exit = 2;
		ft_free_all(": numeric argument required\n", 2);
	}
}

int	ft_exit(char **args)
{
	int				i;
	unsigned char	c;

	i = 0;
	if (!args || !args[1])
		ft_free_all(NULL, 0);
	ft_check_exit_arg(args);
	i = ft_tab_lenght(args);
	if (i > 2)
		return ((g_data->exit = 1),
			ft_putstr_fd("bash: exit: too many arguments\n", 2), 0);
	c = ft_atoi(args[1]);
	ft_free_all(NULL, c);
	return (0);
}
