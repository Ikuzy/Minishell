#include "../include/minishell.h"

int	check_meta_char(char *str)
{
	int		i;
	char	*unsupported;

	i = 0;
	unsupported = "!#%%&()*,:;@[\\]^`{}";
	while (str[i])
	{
		if (ft_strchr(unsupported, str[i]))
		{
			printf("✘ mish: Unsupported character: %c\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
