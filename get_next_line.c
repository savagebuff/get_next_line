#include "get_next_line.h"

// Parameters 
// #1. file descriptor for reading
// #2. The value of what has been read

// Return value 
// 1 : A line has been read
// 0 : EOF has been reached
// -1 : An error happened

static char	*ft_ending(char *line, char **text)
{
	int		i;
	int		j;
	char	*tmp;

	if (!*text)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	free(line);
	if (!ft_strchr(*text, '\n'))
	{
		line = ft_substr(*text, 0, ft_strlen(*text));
		free(*text);
		*text = NULL;
		return (line);
	}
	i = ft_strlen(*text);
	j = ft_strlen(ft_strchr(*text, '\n'));
	line = ft_substr(*text, 0, i - j + 1);
	tmp = *text;
	*text = ft_substr(ft_strchr(*text, '\n'), 1, j - 1);
	free(tmp);
	return (line);
}

static void	ft_bufferization(int fd, char *buff, char **text)
{
	int		i;
	char	*tmp;

	if (!*text || !ft_strchr(*text, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = '\0';
			if (!*text)
				*text = ft_substr(buff, 0, i);
			else
			{
				tmp = *text;
				*text = ft_strjoin(*text, buff);
				free(tmp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*text;

	buff = malloc(BUFFER_SIZE + 1);
	line = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd < 0 || !line || !buff
		|| read(fd, 0, 0) == -1)
	{
		free(buff);
		free(line);
		line = NULL;
		return (NULL);
	}
	ft_bufferization(fd, buff, &text);
	return (ft_ending(line, &text));
}
