#include <stdlib.h>

int	ft_searchnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_free(char *line)
{
	free(line);
	line = 0;
	return (-1);
}
