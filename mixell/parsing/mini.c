/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:00:07 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/27 19:12:51 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main(int ac ,char **av, char **env)
{
    
    t_parse *split;
    
    while (1)
    {
        char *line = put_prompt();
        if (sd_quotes(line) == 0)
        {
		    split = spliting(line);        
            if (!line || strcmp(line, "exit") == 0)
            {
                free(line);
             break;
            }


            printf("You entered: %s\n", line);
        while (split)
        {
            printf("%s\n", split->content);
            split = split->next;
        }
            // free (split);
        }
        if (*line)
            add_history(line);
        free(line);
    }
    printf("Exiting...\n");
    return 0;
}

