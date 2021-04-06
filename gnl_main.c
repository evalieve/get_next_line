
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
	int		i;

	i = 0;
	printf("\n");
	while ((ret = get_next_line(fd, &line) > 0))
	{
		printf("return value in main: %d\n", ret);
		printf("line in main: ");
		while (line[i])
		{
			printf("%c", line[i]);
			i++;
		}
		printf("\n");
		i = 0;
	}
	printf("return value in main: %d\n", ret);
	printf("last line in main: ");
	while (line[i])
	{
		printf("%c", line[i]);
		i++;
	}
	printf("\n");
//	system("leaks a.out");
	return (0);
}