#include "get_next_line.h"
#include <stdio.h>

static int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_rest(char *s, char *remains)
{
	int	i;

	i = 0;
	while (s[i])
	{
		remains[i] = s[i];
		i++;
	}
	remains[i] = '\0';
	//printf("remains: %s\n", remains);
	return (1);
}

static char	*ft_filler(char	*line, char *src)
{
	char	*result;
	int		lenline;
	int		lensrc;

	lenline = 0;
	lensrc = 0;
	result = (char *)malloc((ft_strlen(line, '\0') + ft_strlen(src, '\n') + 1)
			 * sizeof(char));
	if (!result)
		return (0);
	while (line != NULL && line[lenline])
	{
		result[lenline] = line[lenline];
		lenline++;
	}	
	while (src[lensrc] != '\n' && src[lensrc])
	{
		result[lenline + lensrc] = src[lensrc];
		lensrc++;
	}
	result[lenline + lensrc] = '\0';
	free(line);
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static char	remains[BUFFER_SIZE];
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = NULL;
	if (ft_strlen(remains, '\0') > 0)
	{
		*line = ft_filler(*line, remains);
		if (!*line)
			return (ft_free(*line));
		if (ft_searchnl(remains))
			return (ft_rest(remains + ft_strlen(remains, '\n') + 1, remains));
	}
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(*line));
		buff[ret] = '\0';
		*line = ft_filler(*line, buff);
		if (!*line)
			return (ft_free(*line));
		if (ft_searchnl(buff))
			return (ft_rest(buff + ft_strlen(buff, '\n') + 1, remains));
	}
	return (ret);
}
