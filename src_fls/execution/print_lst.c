/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:49:54 by ozouine           #+#    #+#             */
/*   Updated: 2025/01/05 20:49:25 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_type(int type)
{
	if (type == -1)
		printf("| type: ----------- ERROR   |\n+----------------+\n");
	else if (type == CMD)
		printf("| type: ----------- TOKEN   |\n+----------------+\n");
	else if (type == TRUNC)
		printf("| type: ----------- RED_OUT |\n+----------------+\n");
	else if (type == INF)
		printf("| type: ----------- RED_IN  |\n+----------------+\n");
	else if (type == APPEND)
		printf("| type: ----------- APP     |\n+----------------+\n");
	else if (type == HEREDOC)
		printf("| type: ----------- HER_DOC |\n+----------------+\n");
	else if (type == PIPE)
		printf("| type: ----------- PIPE    |\n+--------------+\n\n");
	else if (type == ARG)
		printf("| type: ----------- ARG     |\n+--------------+\n\n");
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args != NULL && *args)
	{
		printf("	+---------------------------+\n");
		printf("	| arg[%d]: --------- [%s]\n", i++, *args++);
		printf("	+---------------------------+\n");
	}
}

void	print_list(t_command *table)
{
	if (!table)
		return ;
	while (table != NULL)
	{
		printf("+---------------------------+\n");
		printf("| token: ---------- [%s]\n", table->value);
		print_type(table->type);
		print_args(table->args);
		table = table->next;
	}
}

void	exit_fork(int status)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		exit(status);
	wait(&status);
}
