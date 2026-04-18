#include "../include/minishell.h"

int	is_num(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if ((*str > '9' || *str < '0') && *str != '\"' && *str != '"')
			return (1);
		str++;
	}
	return (0);
}

static void	reverse_string(char *buffer, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
}

static void	convert_digits(int num, char *buffer, int *index)
{
	if (num == 0)
		buffer[(*index)++] = '0';
	while (num > 0)
	{
		buffer[(*index)++] = (num % 10) + '0';
		num /= 10;
	}
}

void	int_to_str(int num, char *buffer)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = num < 0;
	if (is_negative)
		num = -num;
	convert_digits(num, buffer, &i);
	if (is_negative)
		buffer[i++] = '-';
	reverse_string(buffer, 0, i - 1);
	buffer[i] = '\0';
}
