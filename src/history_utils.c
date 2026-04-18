#include "../include/minishell.h"

void	handle_heredoc_child(char *delimiter, int *fd_pipe)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	close(fd_pipe[0]);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delimiter))
			break ;
		write(fd_pipe[1], line, ft_strlen(line));
		write(fd_pipe[1], "\n", 1);
		free(line);
	}
	if (!line)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	close(fd_pipe[1]);
	exit(0);
}

int handle_heredoc(char *delimiter, t_dir *dir, t_env *my_env, char **line)
{
	int fd_pipe[2];
	pid_t pid;
	int status;
	
	(void)my_env;
	(void)dir;
	if (pipe(fd_pipe) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid = fork();
	if (pid == 0)
		handle_heredoc_child(delimiter, fd_pipe);
	else if (pid > 0)
	{
		close(fd_pipe[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && handle_signals(status, fd_pipe[0], line))
			return (0);
		return (fd_pipe[0]);
	}
	else
		return (perror("fork"),1);
	return (0);
}

void	history_nd_process(char **line, t_dir *dir, t_env **my_env,
		t_stat *status)
{
	add_history(*line);
	char *delimiter = *line;
	dir->heredoc_fd = -1;
	while ((delimiter = strstr(delimiter, "<<")) != NULL)
	{
		delimiter += 2;
		while (isspace((unsigned char)*delimiter))
			delimiter++;
		char *end = delimiter;
		while (*end && !isspace((unsigned char)*end))
			end++;
		char saved_char = *end;
		*end = '\0';
		dir->heredoc_fd = handle_heredoc(delimiter, dir, *my_env, line);
		if (dir->heredoc_fd == -1)
		{
			dir->exit_status_ = 1;
			*end = saved_char;
			return;
		}
		*end = saved_char;
	}
	tilda_remod(line, *dir);
	process_input(line, dir, my_env, status);
}

char	*trim_whitespace(char *str)
{
	char	*end;

	while (isspace((unsigned char)*str))
		str++;
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}
