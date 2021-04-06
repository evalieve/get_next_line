#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			ft_searchnl(char *str);
int			ft_free(char *line);
int			get_next_line(int fd, char **line);

#endif