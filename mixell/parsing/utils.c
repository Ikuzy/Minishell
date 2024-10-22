/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:57:39 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/05 16:22:41 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini.h"

char *put_prompt()
{
    char *line;

    line = readline("minishel >> ");
    return (line);
}
int sd_quotes(char *line)
{
    int squotes;
    int dquotes;
    int i;

    squotes = 0;
    dquotes = 0;
    i = 0;
    while (line[i])
    {
        if(line[i] == '"' || line[i] == 39)
        {
            if(dquotes == 0 && line[i] == '"' && squotes == 0)
                dquotes = 1;
            else if(squotes == 0 && line[i] == 39 && dquotes == 0)
                squotes = 1;
            else if(line[i] == '"' && dquotes == 1)
                dquotes = 0;
            else if(line[i] == 39 && squotes == 1)
                squotes = 0;
        }
        i++;
    }
    if(squotes == 1 || dquotes == 1)
        return (printf("syntax error\n"), 1);
    return 0;
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}