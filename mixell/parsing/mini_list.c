/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:08:18 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/06 14:35:56 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// t_parse *new_token(char *content, int type)
// {
//     t_parse *new_node = malloc(sizeof(t_parse));
//     if (!new_node)
//         return NULL;
//     new_node->content = ft_strdup(content); 
//     new_node->type = type;
//     new_node->next = NULL;
//     return new_node;
// }

// void add_token(t_parse **head, char *content, int type)
// {
//     t_parse *new_node = new_token(content, type);
//     if (!new_node)
//         return;
//     if (!(*head))
//         *head = new_node  ; 
//     else
//     {
//         t_parse *temp = *head;
//         while (temp->next != NULL)
//         {
//             printf ("+++++++++++++++\n");
//             temp = temp->next;
//         }
//         temp->next = new_node;
//     }
// }

void parse_input(char **split, t_parse **head)
{
    int i;

    i = 0;
    while (split[i])
    {
        add_token(head, split[i], cmp(split[i]));
        i++;
    }
}

int cmp(char *split)
{
    if(strcmp(split, "|") == 0)
        return(pipe);
    else if(strcmp(split, "\"") == 0)
        return(dquote);
    else if(strcmp(split, "'") == 0)
        return(squote);
    else if(strcmp(split, ">") == 0)
        return(output);
    else if(strcmp(split, "<") == 0)
        return(input);
    else if(strcmp(split, ">>") == 0)
        return(redirection);
    else if(strcmp(split, "<<") == 0)
        return(heredoc);
    else if(strcmp(split, "cd") == 0 || strcmp(split, "echo") == 0 || strcmp(split, "pwd") == 0 
            || strcmp(split, "export") == 0 || strcmp(split, "unset") == 0 || strcmp(split, "env") == 0)
        return (command);
    else
        return(word);
}
