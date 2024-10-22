/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:21 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/06 12:46:10 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_free(char **str)
{
	int i = 0;

	while (str[i])
		free (str[i++]);
	free (str);
}

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
char *ft_strcpy(char *s1, char s2)
{
	s1[0] = s2;
	s1[1] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '"')
					break;
				i++;
			}
			if (str[i])
				wc++;
		}
		while (str[i] && (str[i] != ' ' && str[i] != '\t') && str[i] != '"')
			i++;
		if (str[i])
			wc++;
	}
	printf("%d\n", wc);
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

t_parse *split_line(char *line)
{
	int  i;
	int j;
	char *str;
	char tmp[2];
	t_parse *head;
	head = NULL;
	i = 0;
	while(line[i])
	{
		j = i;
		while((line[i ] != '|' && (line[i ] != '>' && line[i ] != '<')) )
			i++;
		if (i > j)
		{
			str = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(str, &line[j], i - j );
		}
		add_token(&head, str, cmp(str));
		if (line[i] != '\0')
		{	
			add_token(&head, ft_strcpy(tmp, line[i]), cmp(tmp));
			i++;
		}
		// free(str);
	}
	return(head);
}