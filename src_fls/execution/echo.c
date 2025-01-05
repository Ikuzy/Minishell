/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:43:01 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:46:22 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_switch(char *str, char *switches)
{
	int	i;
	int	j;

	i = 0;
	if (!str || !switches)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		j = 0;
		while (switches[j])
			if (switches[j++] != str[i])
				return (-1);
		i++;
	}
	return (1);
}

int	ft_echo(char **arg)
{
	int	nl_flag;
	int	i;
	int	number_of_arg;

	i = 1;
	nl_flag = 0;
	if (!arg || !arg[1])
		return (write(1, "\n", 1), ft_free_all(NULL, 0), 0);
	number_of_arg = ft_tab_lenght(arg);
	while (arg[i] && ft_is_switch(arg[i], "n") == 1)
	{
		nl_flag = 1;
		i++;
	}
	if (number_of_arg == 1 && nl_flag == 1)
		return (ft_free_all(NULL, 0), 0);
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (i++ < number_of_arg - 1)
			write(1, " ", 1);
	}
	if (nl_flag == 0)
		write(1, "\n", 1);
	return (ft_free_all(NULL, 0), 0);
}
