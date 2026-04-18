#include "../include/minishell.h"

static void	handle_redirection(char *operator, char *filename)
{
	int	fd;

	fd = 0;
	if (!ft_strcmp(operator, ">"))
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (!ft_strcmp(operator, ">>"))
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (!ft_strcmp(operator, "<"))
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("open");
	else
	{
		if (!ft_strcmp(operator, ">") || !ft_strcmp(operator, ">>"))
			dup2(fd, STDOUT_FILENO);
		else
			dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	check_redirections(char *str)
{
	char	**tokens;
	int		i;

	tokens = ft_split(str, ' ');
	if (!tokens)
		return ;
	i = -1;
	while (tokens[++i])
	{

		if ((!ft_strcmp(tokens[i], ">") || !ft_strcmp(tokens[i], ">>")
				|| !ft_strcmp(tokens[i], "<")) && tokens[i + 1])
		{
			handle_redirection(tokens[i], tokens[i + 1]);
			i++;
		}
	}
	free_array(tokens);
}
