#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define MAX_FD 1024

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			ft_searchnl(char *str);
int			ft_free(char *line);
int			get_next_line(int fd, char **line);

#endif