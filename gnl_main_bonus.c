
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	int		ret;
	int		fd = open("text.txt", O_RDONLY);
	int		fd_bonus = open("text_bonus.txt", O_RDONLY);
	int		i;

	i = 0;
	ret = 1;
	printf("\n");
	while (ret > 0)
	{
		if (i % 2 == 0)
			ret = get_next_line(fd, &line);
		else
			ret = get_next_line(fd_bonus, &line);
		printf("return value in main: %d\n", ret);
		printf("line in main: %s\n", line);
		i++;
	}
	printf("return value in main: %d\n", ret);
	printf("last line in main: ");
	i = 0;
	while (line[i])
	{
		printf("%c", line[i]);
		i++;
	}
	printf("\n");
//	system("leaks a.out");
	return (0);
}