#include "mini.h"

t_parse	*ft_lstnew(char *content, int type)
{
	t_parse	*node;

	node = malloc(sizeof(t_parse));
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
    node->type = type;
	node->next = NULL;
	return (node);
}

t_parse	*ft_lstlast(t_parse *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_parse **lst, t_parse *new)
{
	t_parse	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	if (tmp)
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*lst = new;
}

void add_token(t_parse **head, char *content, int type)
{
    t_parse *new_node = ft_lstnew(content, type);
    if (!new_node)
        return;
    if (!head && !(*head))
        *head = new_node  ; 
    else
    {
       ft_lstadd_back(head, new_node);
    }
}

char *ft_cpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (i < n && s2[i])
    {
        // if (s2[i] != ' ')
		    s1[i] = s2[i];
        i++;
    }
	s1[i] = '\0';
	return (s1);
}

char *ft_dcpy(char *s1, char *s2, int n, char c)
{
	int i = 0;
	int j = 0;

	while (i < n && s2[j])
    {
		s1[i++] = s2[j];
	    j++;
    }
	s1[i] = '\0';
	return (s1);
}

int special(char *line, int j, char c, int count)
{
	j++;
	while(line[j] != c)
		j++;
	if (line[j] == c)
		count++;
	while (line[j] != '\0' && line[j] != '>' && line[j] != '<'
			&& line[j] != '|' && line[j] != ' ' && line[j] != '\'' && line[j] != '"')
		j++;
	return j;
}

int dq_cpy(t_parse **head, char *line, int i, char c, int s)
{
    int j;
	int count = 1;
    char *str;

	j = i;
	while (i > 0 && line[i - 1] != '>' && line[i - 1] != '<'
			&& line[i - 1] != '|' && line[i - 1] != ' ')
		i--;
	while (line[j] == '"' || line[j] == '\'')
	{
		if (line[j] == '"' || line[j] == '\'')
			j = special (line, j, line[j], count);
		else
			break;
	}
    str = (char *)malloc(sizeof(char) * ((j - i) + 1));
	ft_dcpy(str, &line[i], j - i, c);
    add_token (head, str, cmp(str));
    free (str);
    return (j);
}

t_parse *spliting(char *line)
{
    int i = 0;
    int j;
    char *str;
	char c;
    t_parse *head;

    str = NULL; 
    head = NULL;
    while (line[i])
    {
        while (line[i] == ' ')
            i++;
        j = i;
        while (line[i] != '\0' && line[i] != '>' && line[i] != '<' && line[i] != '|'
				&& line[i] != ' ' && line[i] != '"' && line[i] != '\'')
		{
			if (line[i] == '"' || line[i] == '\'')
			{
				c = line[i];
				i++;
				while (line[i] && line[i] != c)
					i++;
			}
			else
	            i++;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			i = dq_cpy(&head, line, i, line[i], 0) + 1;
			if (line[i] != '\0' && (line[i] == '>' || line[i] == '<' || line[i] == '|'))
        	{
            	str = (char *)malloc(sizeof(char) * 2);
		    	ft_cpy(str, &line[i], 1);
            	add_token (&head, str, cmp(str));
            	free (str);
                i++;
            }
		}
        else
        {
        	if (i > j)
			{
		    	str = (char *)malloc(sizeof(char) * ((i - j) + 1));
		    	ft_cpy(str, &line[j], i - j );
            	add_token (&head, str, cmp(str));
            	free (str);
	    	}
        	if (line[i] != '\0' && (line[i] == '>' || line[i] == '<' || line[i] == '|'))
        	{
            	str = (char *)malloc(sizeof(char) * 2);
		    	ft_cpy(str, &line[i], 1);
            	add_token (&head, str, cmp(str));
            	free (str);
                i++;
            }
        }
        if (line[i] == '\0')
            break;
        else if (line[i] == ' ')
            i++;
    }
    return (head);
}